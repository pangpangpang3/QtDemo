/****************************************************************************
**
**  Copyright (C) 2014 ~ 2016 Deepin, Inc.
**                2011 ~ 2014 penghui
**
**  Author:     penghui <penghuilater@gmail.com>
**  Maintainer: penghui <penghuilater@gmail.com>
**
**  This program is free software: you can redistribute it and/or modify
**  it under the terms of the GNU General Public License as published by
**  the Free Software Foundation, either version 3 of the License, or
**  any later version.
**
**  This program is distributed in the hope that it will be useful,
**  but WITHOUT ANY WARRANTY; without even the implied warranty of
**  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
**  GNU General Public License for more details.
**
**  You should have received a copy of the GNU General Public License
**  along with this program.  If not, see <http://www.gnu.org/licenses/>.
**
****************************************************************************/

import QtQuick 2.1
import QtGraphicalEffects 1.0 
Item {
    id: root
    width: 400
    height: 400

    Rectangle {
        id: bug
        anchors.fill: parent
        color: "#25292b"
    }
    Canvas {
        id: mask
        anchors.fill: parent

        Component.onCompleted: {
             loadImage("516.png")
        }

        onPaint: {
            var ctx = mask.getContext('2d')
            ctx.save()
            ctx.strokeStyle = "#009cff"
            ctx.shadowBlur = 10
            ctx.shadowColor = "#009cff"
            ctx.lineWidth = 3;
            ctx.beginPath();
            ctx.ellipse(0, 0, 400, 400)
            ctx.closePath()
            ctx.stroke();
            ctx.clip()
            ctx.drawImage('516.png', 0, 0)
            ctx.stroke()
            ctx.restore()
        }
    }


}
