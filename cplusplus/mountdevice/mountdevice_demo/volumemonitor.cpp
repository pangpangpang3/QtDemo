#include "volumemonitor.h"

#include <fcntl.h>
#include <unistd.h>
#include <QFile>
#include <QSet>
#include <QTextStream>
#include <QDebug>

namespace {
    const char mountFile[] = "/proc/mounts";
    QSet<QString> parseMountFile() {
        QFile file(mountFile);
        if (file.exists()) {
            if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
                QTextStream textStream(&file);
                QString fileContent = textStream.readAll();
                file.close();
                return QSet<QString>::fromList(fileContent.split("\n"));
            }
        }
        return  QSet<QString>();
    }

    QString getMountPoint(const QString& record) {
        const QStringList items = record.split(" ");
        if (items.length() > 4) {
            return items.at(1);
        } else {
            return "";
        }
    }
}

VolumeMonitor::VolumeMonitor(QObject *parent)
    : QObject(parent)
{
    this->setObjectName("VolumeMonitor");
}

bool VolumeMonitor::start() {
    //get the set of mounted device's info;
    m_fileContentSet = parseMountFile();

    m_fileKde = open(mountFile, O_RDONLY);
    if (m_fileKde == -1) {
        qWarning() << "open /proc/mounts failed!";
        return false;
    }

    m_socketNotifier = new QSocketNotifier(m_fileKde,
                                           QSocketNotifier::Write, this);

    connect(m_socketNotifier, &QSocketNotifier::activated,
            this, &VolumeMonitor::onFileChanged);
    return true;
}

bool VolumeMonitor::isRunning() {
    if (m_fileKde!= -1 && m_socketNotifier) {
        return true;
    } else {
        return false;
    }
}

bool VolumeMonitor::stop() {
    if (this->isRunning()) {
        close(m_fileKde);
        m_fileKde = -1;
        delete m_socketNotifier;
        m_socketNotifier = nullptr;
        return true;
    } else {
        return false;
    }
}
void VolumeMonitor::onFileChanged() {
    QSet <QString> changedItemSet = parseMountFile();
    for(const QString& item: changedItemSet - m_fileContentSet)
        emit deviceAdded(getMountPoint(item));
    for(const QString& item: m_fileContentSet - changedItemSet)
        emit deviceRemoved(getMountPoint(item));

    m_fileContentSet = changedItemSet;
}

VolumeMonitor::~VolumeMonitor()
{
    this->stop();
}
