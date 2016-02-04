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

import QtQuick 2.0
import QtQuick.Particles 2.0

Rectangle {
    id: root
    width: 600; height: 760
    color: "#1f1f1f"

    ParticleSystem {
        id: particleSystem
    }

    Emitter {
        id: emitter
        anchors.centerIn: parent
        width: 160; height: 80
        system: particleSystem
        emitRate: 10
        lifeSpan: 1000
        lifeSpanVariation: 500
        size: 16
        endSize: 32

        //rotationVariation: 45
        //rotationVelocity: 15
        //rotationVelocityVariation: 15
        //entryEffect: ImageParticle.Scale 
      //  velocity: AngleDirection {
      //      angle: 90
      //      angleVariation: 15
      //      magnitude: 100
      //      magnitudeVariation: 50
      //  } 
      //  velocity: AngleDirection {
      //      angle: -45
      //      angleVariation: 0
      //      magnitude: 100
      //  }
      //  acceleration: AngleDirection {
      //      angle: 90
      //      magnitude: 25
      //  } 
        velocity: TargetDirection {
        targetX: 100
        targetY: 0
        targetVariation: 100/6
        magnitude: 100
        } 
    }

    ImageParticle {
        source:"../images/star.png"
        system: particleSystem
    }
}
