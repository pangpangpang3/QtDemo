#include "dbmanager.h"
#include "application.h"
#include "signalmanager.h"
#include "utils/baseutils.h"
#include <QDebug>
#include <QDir>
#include <QMutex>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

namespace {

const QString DATABASE_PATH = QDir::homePath() + "/.local/share/deepin/deepin-image-viewer/";
const QString DATABASE_NAME = "deepinimageviewer.db";

}  // namespace

DBManager::DBManager(QObject *parent)
    : QObject(parent)
    , m_connectionName("default_connection")
{
    checkDatabase();
}

const QStringList DBManager::getAllPaths() const
{
    QStringList paths;
    const QSqlDatabase db = getDatabase();
    if (! db.isValid())
        return paths;

    QSqlQuery query( db );
    query.prepare( "SELECT "
                   "FilePath "
                   "FROM ImageTable3 ORDER BY Time DESC");
    if (! query.exec()) {
        qWarning() << "Get Data from ImageTable3 failed: " << query.lastError();
        return paths;
    }
    else {
        while (query.next()) {
            paths << query.value(0).toString();
        }
    }

    return paths;
}

const DBImgInfoList DBManager::getAllInfos() const
{
    DBImgInfoList infos;
    const QSqlDatabase db = getDatabase();
    if (! db.isValid()) {
        return infos;
    }
    QSqlQuery query( db );
    query.prepare( "SELECT FilePath, FileName, MountPoint, Time "
                   "FROM ImageTable3 ORDER BY Time DESC");
    if (! query.exec()) {
        qWarning() << "Get data from ImageTable3 failed: " << query.lastError();
        return infos;
    }
    else {
        using namespace utils::base;
        while (query.next()) {
            DBImgInfo info;
            info.filePath = query.value(0).toString();
            info.fileName = query.value(1).toString();
            info.mountPoint = query.value(2).toString();
            info.time = stringToDateTime(query.value(3).toString());

            infos << info;
        }
    }

    return infos;
}

const QStringList DBManager::getAllTimelines() const
{
    QStringList times;
    const QSqlDatabase db = getDatabase();
    if (! db.isValid())
        return times;

    QSqlQuery query( db );
    query.prepare( "SELECT DISTINCT Time "
                   "FROM ImageTable3 ORDER BY Time DESC");
    if (! query.exec()) {
        qWarning() << "Get Data from ImageTable3 failed: " << query.lastError();
        return times;
    }
    else {
        while (query.next()) {
            times << query.value(0).toString();
        }
    }

    return times;
}

const DBImgInfoList DBManager::getInfosByTimeline(const QString &timeline) const
{
    const DBImgInfoList list = getImgInfos("Time", timeline);
    if (list.count() < 1) {
        return DBImgInfoList();
    }
    else {
        return list;
    }
}

const DBImgInfo DBManager::getInfoByName(const QString &name) const
{
    DBImgInfoList list = getImgInfos("FileName", name);
    if (list.count() < 1) {
        return DBImgInfo();
    }
    else {
        return list.first();
    }
}

const DBImgInfo DBManager::getInfoByPath(const QString &path) const
{
    DBImgInfoList list = getImgInfos("FilePath", path);
    if (list.count() != 1) {
        return DBImgInfo();
    }
    else {
        return list.first();
    }
}

int DBManager::getImgsCount() const
{
    const QSqlDatabase db = getDatabase();
    if (! db.isValid()) {
        return 0;
    }
    QSqlQuery query( db );
    query.exec("BEGIN IMMEDIATE TRANSACTION");
    query.prepare( "SELECT COUNT(*) FROM ImageTable3" );
    if (query.exec()) {
        query.first();
        int count = query.value(0).toInt();
        query.exec("COMMIT");
        return count;
    }

    return 0;
}

int DBManager::getImgsCountByMountPoint(const QString &mountPoint) const
{
    const QSqlDatabase db = getDatabase();
    if (mountPoint.isEmpty() || ! db.isValid()) {
        return 0;
    }

    QSqlQuery query( db );
    query.prepare("SELECT COUNT(*) FROM ImageTable3 "
                          "WHERE MountPoint=:MountPoint AND FilePath !=\" \"");
    query.bindValue(":MountPoint", mountPoint);
    if (query.exec()) {
        query.first();
        return query.value(0).toInt();
    }
    else {
        qDebug() << "Get images count by MountPoint failed :" << query.lastError();
        return 0;
    }
}

bool DBManager::isImgExist(const QString &path) const
{
    const QSqlDatabase db = getDatabase();
    if (db.isValid()) {
        return false;
    }
    QSqlQuery query( db );
    query.exec("BEGIN IMMEDIATE TRANSACTION");
    query.prepare( "SELECT COUNT(*) FROM ImageTable3 WHERE FilePath = :path" );
    query.bindValue( ":path", path );
    if (query.exec()) {
        query.first();
        if (query.value(0).toInt() > 0) {
            query.exec("COMMIT");
            return true;
        }
    }

    return false;
}

void DBManager::insertImgInfos(const DBImgInfoList &infos)
{
    const QSqlDatabase db = getDatabase();
    if (infos.isEmpty() || ! db.isValid()) {
        return;
    }

    QVariantList filenames, filepaths, mountpoints, times;

    for (DBImgInfo info : infos) {
        filenames << info.fileName;
        filepaths << info.filePath;
        mountpoints << info.mountPoint;
        times << utils::base::timeToString(info.time, true);
    }

    // Insert into ImageTable3
    QSqlQuery query( db );
    query.exec("BEGIN IMMEDIATE TRANSACTION");
    query.prepare( "REPLACE INTO ImageTable3 "
                   "(FilePath, FileName, MountPoint, Time) VALUES (?, ?, ?, ?)" );
    query.addBindValue(filepaths);
    query.addBindValue(filenames);
    query.addBindValue(mountpoints);
    query.addBindValue(times);
    if (! query.execBatch()) {
        qWarning() << "Insert data into ImageTable3 failed: "
                   << query.lastError();
        query.exec("COMMIT");
    }
    else {
        query.exec("COMMIT");
        emit dApp->signalM->imagesInserted(infos);
    }
}

void DBManager::removeImgInfos(const QStringList &paths)
{
    QSqlDatabase db = getDatabase();
    if (paths.isEmpty() || ! db.isValid()) {
        return;
    }

    // Collect info before removing data
    DBImgInfoList infos;
    for (QString path : paths) {
        infos << getInfoByPath(path);
    }

    QSqlQuery query(db);
    // Remove from albums table
    const QStringList al = getAllAlbumNames();
    for (QString album : al) {
        removeFromAlbum(album, paths);
    }

    // Remove from image table
    QString qs = "DELETE FROM ImageTable3 WHERE FilePath=?";
    query.prepare(qs);
    query.addBindValue(paths);
    if (! query.execBatch()) {
        qWarning() << "Remove data from ImageTable3 failed: "
                   << query.lastError();
    }
    else {
        emit dApp->signalM->imagesRemoved(infos);
    }
}

void DBManager::removeMountPoint(const QString &mountPoint)
{
    QSqlDatabase db = getDatabase();
    if (mountPoint.isEmpty() || ! db.isValid()) {
        return;
    }

    // Collect info before removing data
    DBImgInfoList infos = getImgInfos("MountPoint", mountPoint);
    QStringList paths;
    for (auto info : infos) {
        paths << info.filePath;
    }

    QSqlQuery query(db);
    // Remove from albums table
    const QStringList al = getAllAlbumNames();
    for (QString album : al) {
        removeFromAlbum(album, paths);
    }

    // Remove from image table
    QString qs = "DELETE FROM ImageTable3 WHERE MountPoint=:point";
    query.prepare(qs);
    query.bindValue(":point", mountPoint);
    if (! query.exec()) {
        qWarning() << "Remove mount-device data from ImageTable3 failed: "
                   << query.lastError();
    }
    else {
        emit dApp->signalM->imagesRemoved(infos);
    }
}

const DBAlbumInfo DBManager::getAlbumInfo(const QString &album) const
{
    DBAlbumInfo info;
    QSqlDatabase db = getDatabase();
    if (! db.isValid()) {
        return info;
    }

    info.name = album;
    QStringList paths;

    QSqlQuery query( db );
    query.prepare( "SELECT DISTINCT FilePath FROM AlbumTable3 "
                   "WHERE AlbumName =:name AND FilePath != \" \" ");
    query.bindValue(":name", album);
    if ( ! query.exec() ) {
        qWarning() << "Get data from AlbumTable3 failed: "
                   << query.lastError();
    }
    else {
        while (query.next()) {
            paths << query.value(0).toString();
        }
    }

    info.count = paths.length();
    if (paths.length() == 1) {
        info.endTime = getInfoByPath(paths.first()).time;
        info.beginTime = info.endTime;
    }
    else if (paths.length() > 1) {
        info.endTime = getInfoByPath(paths.first()).time;
        info.beginTime = getInfoByPath(paths.last()).time;
    }

    return info;
}

const QStringList DBManager::getAllAlbumNames() const
{
    QStringList list;
    const QSqlDatabase db = getDatabase();
    if (! db.isValid()) {
        return list;
    }
    QSqlQuery query( db );
    query.prepare( "SELECT DISTINCT AlbumName FROM AlbumTable3" );
    if ( !query.exec() ) {
        qWarning() << "Get AlbumNames failed: " << query.lastError();
    }
    else {
        while (query.next()) {
            list << query.value(0).toString();
        }
    }

    return list;
}

const QStringList DBManager::getPathsByAlbum(const QString &album) const
{
    QStringList list;
    const QSqlDatabase db = getDatabase();
    if (! db.isValid()) {
        return list;
    }
    QSqlQuery query( db );
    query.prepare( "SELECT DISTINCT FilePath FROM AlbumTable3 "
                   "WHERE AlbumName=:album AND FilePath != \" \"" );
    query.bindValue(":album", album);
    if (! query.exec() ) {
        qWarning() << "Get Paths from AlbumTable3 failed: " << query.lastError();
    }
    else {
        while (query.next()) {
            list << query.value(0).toString();
        }
    }

    return list;
}

const DBImgInfoList DBManager::getInfosByAlbum(const QString &album) const
{
    DBImgInfoList infos;
    const QSqlDatabase db = getDatabase();
    if (! db.isValid()) {
        return infos;
    }
    QSqlQuery query( db );
    query.prepare("SELECT DISTINCT i.FilePath, i.FileName, i.MountPoint, i.Time "
                  "FROM ImageTable3 AS i, AlbumTable3 AS a "
                  "WHERE i.FilePath=a.FilePath AND a.AlbumName=:album");
    query.bindValue(":album", album);
    if (! query.exec()) {
        qWarning() << "Get ImgInfo by album failed: " << query.lastError();
    }
    else {
        using namespace utils::base;
        while (query.next()) {
            DBImgInfo info;
            info.filePath = query.value(0).toString();
            info.fileName = query.value(1).toString();
            info.mountPoint = query.value(2).toString();
            info.time = stringToDateTime(query.value(3).toString());

            infos << info;
        }
    }
    return infos;
}

int DBManager::getImgsCountByAlbum(const QString &album) const
{
    const QSqlDatabase db = getDatabase();
    if (! db.isValid()) {
        return 0;
    }
    QSqlQuery query( db );
    query.prepare("SELECT COUNT(*) FROM AlbumTable3 "
                          "WHERE AlbumName =:album AND FilePath !=\" \"");
    query.bindValue(":album", album);
    if (query.exec()) {
        query.first();
        return query.value(0).toInt();
    }
    else {
        qDebug() << "Get images count error :" << query.lastError();
        return 0;
    }
}

int DBManager::getAlbumsCount() const
{
    const QSqlDatabase db = getDatabase();
    if (! db.isValid()) {
        return 0;
    }
    QSqlQuery query( db );
    query.prepare("SELECT COUNT(DISTINCT AlbumName) FROM AlbumTable3");
    if (query.exec()) {
        query.first();
        return query.value(0).toInt();
    }
    else {
        return 0;
    }
}

bool DBManager::isImgExistInAlbum(const QString &album, const QString &path) const
{
    const QSqlDatabase db = getDatabase();
    if (! db.isValid()) {
        return false;
    }
    QSqlQuery query( db );
    query.prepare( "SELECT COUNT(*) FROM AlbumTable3 WHERE FilePath = :path "
                   "AND AlbumName = :album");
    query.bindValue( ":path", path );
    query.bindValue( ":album", album );
    if (query.exec()) {
        query.first();
        return (query.value(0).toInt() == 1);
    }
    else {
        return false;
    }
}

bool DBManager::isAlbumExistInDB(const QString &album) const
{
    const QSqlDatabase db = getDatabase();
    if (! db.isValid()) {
        return false;
    }
    QSqlQuery query( db );
    query.prepare( "SELECT COUNT(*) FROM AlbumTable3 WHERE AlbumName = :album");
    query.bindValue( ":album", album );
    if (query.exec()) {
        query.first();
        return (query.value(0).toInt() >= 1);
    }
    else {
        return false;
    }
}

void DBManager::insertIntoAlbum(const QString &album, const QStringList &paths)
{

    const QSqlDatabase db = getDatabase();
    if (! db.isValid() || album.isEmpty()) {
        return;
    }
    QStringList nameRows, pathRows;
    for (QString path : paths) {
        nameRows << album;
        pathRows << path;
    }

    QSqlQuery query( db );
    query.exec("BEGIN IMMEDIATE TRANSACTION");
    query.prepare("REPLACE INTO AlbumTable3 (AlbumId, AlbumName, FilePath) "
                  "VALUES (null, ?, ?)");
    query.addBindValue(nameRows);
    query.addBindValue(pathRows);
    if (! query.execBatch()) {
        qWarning() << "Insert data into AlbumTable3 failed: "
                   << query.lastError();
    }
    query.exec("COMMIT");

    //FIXME: Don't insert the repeated filepath into the same album
    //Delete the same data
    query.prepare("DELETE FROM AlbumTable3 where AlbumId NOT IN"
                  "(SELECT min(AlbumId) FROM AlbumTable3 GROUP BY"
                  " AlbumName, FilePath) AND FilePath != \" \"");
    if (!query.exec()) {
        qDebug() << "delete same date failed!";
    }
    query.exec("COMMIT");

    emit dApp->signalM->insertedIntoAlbum(album, paths);
}

void DBManager::removeAlbum(const QString &album)
{
    const QSqlDatabase db = getDatabase();
    if (! db.isValid()) {
        return;
    }
    QSqlQuery query( db );
    query.prepare("DELETE FROM AlbumTable3 WHERE AlbumName=:album");
    query.bindValue(":album", album);
    if (!query.exec()) {
        qWarning() << "Remove album from database failed: " << query.lastError();
    }
}

void DBManager::removeFromAlbum(const QString &album, const QStringList &paths)
{
    const QSqlDatabase db = getDatabase();
    if (! db.isValid()) {
        return;
    }

    QSqlQuery query(db);
    query.exec("BEGIN IMMEDIATE TRANSACTION");
    // Remove from albums table
    QString qs("DELETE FROM AlbumTable3 WHERE AlbumName=\"%1\" AND FilePath=?");
    query.prepare(qs.arg(album));
    query.addBindValue(paths);
    if (! query.execBatch()) {
        qWarning() << "Remove images from DB failed: " << query.lastError();
    }
    else {
        emit dApp->signalM->removedFromAlbum(album, paths);
    }
    query.exec("COMMIT");
}

void DBManager::renameAlbum(const QString &oldAlbum, const QString &newAlbum)
{
    const QSqlDatabase db = getDatabase();
    if (! db.isValid()) {
        return;
    }
    QSqlQuery query( db );
    query.prepare("UPDATE AlbumTable3 SET "
                  "AlbumName = :newName "
                  "WHERE AlbumName = :oldName ");
    query.bindValue( ":newName", newAlbum );
    query.bindValue( ":oldName", oldAlbum );
    if (! query.exec()) {
        qWarning() << "Update album name failed: " << query.lastError();
    }
}

const DBImgInfoList DBManager::getImgInfos(const QString &key, const QString &value) const
{
    DBImgInfoList infos;
    const QSqlDatabase db = getDatabase();
    if (! db.isValid()) {
        return infos;
    }
    QSqlQuery query( db );
    query.prepare(QString("SELECT FilePath, FileName, MountPoint, Time FROM ImageTable3 "
                          "WHERE %1= :value ORDER BY Time DESC").arg(key));
    query.bindValue(":value", value);
    if (!query.exec()) {
        qWarning() << "Get Image from database failed: " << query.lastError();
    }
    else {
        using namespace utils::base;
        while (query.next()) {
            DBImgInfo info;
            info.filePath = query.value(0).toString();
            info.fileName = query.value(1).toString();
            info.mountPoint = query.value(2).toString();
            info.time = stringToDateTime(query.value(3).toString());

            infos << info;
        }
    }

    return infos;
}

const QSqlDatabase DBManager::getDatabase() const
{
    if( QSqlDatabase::contains(m_connectionName) ) {
        QSqlDatabase db = QSqlDatabase::database(m_connectionName);
        return db;
    }
    else {
        //if database not open, open it.
        QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE", m_connectionName);//not dbConnection
        db.setDatabaseName(DATABASE_PATH + DATABASE_NAME);
        if (! db.open()) {
            qWarning()<< "Open database error:" << db.lastError();
            return QSqlDatabase();
        }
        else {
            return db;
        }
    }
}

void DBManager::checkDatabase()
{
    QDir dd(DATABASE_PATH);
    if (! dd.exists()) {
        qDebug() << "create database paths";
        dd.mkpath(DATABASE_PATH);
        if (dd.exists())
            qDebug() << "create database succeed!";
        else
            qDebug() << "create database failed!";
    } else {
        qDebug() << "database is exist!";
    }
    const QSqlDatabase db = getDatabase();
    if (! db.isValid()) {
        return;
    }
    bool tableExist = false;
    QSqlQuery query( db );
    query.prepare( "SELECT name FROM sqlite_master "
                   "WHERE type=\"table\" AND name = \"ImageTable3\"");
    if (query.exec() && query.first()) {
        tableExist = ! query.value(0).toString().isEmpty();
    }
    //if tables not exist, create it.
    if ( ! tableExist ) {
        QSqlQuery query(db);
        // ImageTable3
        ///////////////////////////////////////////////////////
        //FilePath           | FileName | MountPoint | Time  //
        //TEXT primari key   | TEXT     | TEXT       | TEXT  //
        ///////////////////////////////////////////////////////
        query.exec( QString("CREATE TABLE IF NOT EXISTS ImageTable3 ( "
                            "FilePath TEXT primary key, "
                            "FileName TEXT, "
                            "MountPoint TEXT, "
                            "Time TEXT )"));

        // AlbumTable3
        //////////////////////////////////////////////////////////
        //AlbumId               | AlbumName         | FilePath  //
        //INTEGER primari key   | TEXT              | TEXT      //
        //////////////////////////////////////////////////////////
        query.exec( QString("CREATE TABLE IF NOT EXISTS AlbumTable3 ( "
                            "AlbumId INTEGER primary key, "
                            "AlbumName TEXT, "
                            "FilePath TEXT)") );

        // Check if there is an old version table exist or not

        //TODO: AlbumTable's primary key is changed, need to importVersion again
        importVersion1Data();
        importVersion2Data();
    }

}

void DBManager::importVersion1Data()
{
    const QSqlDatabase db = getDatabase();
    if (! db.isValid()) {
        return;
    }
    bool tableExist = false;
    QSqlQuery query( db );
    query.prepare( "SELECT name FROM sqlite_master "
                   "WHERE type=\"table\" AND name = \"ImageTable\"");
    if (query.exec() && query.first()) {
        tableExist = ! query.value(0).toString().isEmpty();
    }

    if (tableExist) {
        // Import ImageTable into ImageTable3
        query.clear();
        query.prepare( "SELECT filename, filepath, time "
                       "FROM ImageTable ORDER BY time DESC");
        if (! query.exec()) {
            qWarning() << "Import ImageTable into ImageTable3 failed: "
                       << query.lastError();
        }
        else {
            DBImgInfoList infos;
            using namespace utils::base;
            while (query.next()) {
                DBImgInfo info;
                info.fileName = query.value(0).toString();
                info.filePath = query.value(1).toString();
                info.time = stringToDateTime(query.value(2).toString());

                infos << info;
            }
            insertImgInfos(infos);
        }

        // Import AlbumTable into AlbumTable3
        query.clear();
        query.prepare("SELECT DISTINCT a.albumname, i.filepath "
                      "FROM ImageTable AS i, AlbumTable AS a "
                      "WHERE i.filename=a.filename ");
        if (! query.exec()) {
            qWarning() << "Import AlbumTable into AlbumTable3 failed: "
                       << query.lastError();
        }
        else {
            // <Album-Paths>
            QMap<QString, QStringList> aps;
            using namespace utils::base;
            while (query.next()) {
                QString album = query.value(0).toString();
                QString path = query.value(1).toString();
                if (aps.keys().contains(album)) {
                    aps[album].append(path);
                }
                else {
                    aps.insert(album, QStringList(path));
                }
            }
            for (QString album : aps.keys()) {
                insertIntoAlbum(album, aps[album]);
            }
        }

        // Drop old table
        query.clear();
        query.prepare("DROP TABLE AlbumTable");
        if (! query.exec()) {
            qWarning() << "Drop old tables failed: " << query.lastError();
        }
        query.prepare("DROP TABLE ImageTable");
        if (! query.exec()) {
            qWarning() << "Drop old tables failed: " << query.lastError();
        }
    }
}

void DBManager::importVersion2Data()
{
    const QSqlDatabase db = getDatabase();
    if (! db.isValid()) {
        return;
    }
    bool tableExist = false;
    QSqlQuery query( db );
    query.prepare( "SELECT name FROM sqlite_master "
                   "WHERE type=\"table\" AND name = \"ImageTable2\"");
    if (query.exec() && query.first()) {
        tableExist = ! query.value(0).toString().isEmpty();
    }

    if (tableExist) {
        // Import ImageTable2 into ImageTable3
        query.clear();
        query.prepare( "SELECT FileName, FilePath, Time "
                       "FROM ImageTable2 ORDER BY Time DESC");
        if (! query.exec()) {
            qWarning() << "Import ImageTable2 into ImageTable3 failed: "
                       << query.lastError();
        }
        else {
            DBImgInfoList infos;
            using namespace utils::base;
            while (query.next()) {
                DBImgInfo info;
                info.fileName = query.value(0).toString();
                info.filePath = query.value(1).toString();
                info.time = stringToDateTime(query.value(2).toString());

                infos << info;
            }
            insertImgInfos(infos);
        }

        // Import AlbumTable2 into AlbumTable3
        query.clear();
        query.prepare(" SELECT AlbumName, FilePath FROM AlbumTable2 ");
        if (! query.exec()) {
            qWarning() << "Import AlbumTable2 into AlbumTable3 failed: "
                       << query.lastError();
        }
        else {
            // <Album-Paths>
            QMap<QString, QStringList> aps;
            using namespace utils::base;
            while (query.next()) {
                QString album = query.value(0).toString();
                QString path = query.value(1).toString();
                if (aps.keys().contains(album)) {
                    aps[album].append(path);
                }
                else {
                    aps.insert(album, QStringList(path));
                }
            }
            for (QString album : aps.keys()) {
                insertIntoAlbum(album, aps[album]);
            }
        }

        // Drop old table
        query.clear();
        query.prepare("DROP TABLE AlbumTable2");
        if (! query.exec()) {
            qWarning() << "Drop old tables failed: " << query.lastError();
        }
        query.prepare("DROP TABLE ImageTable2");
        if (! query.exec()) {
            qWarning() << "Drop old tables failed: " << query.lastError();
        }
    }
}
