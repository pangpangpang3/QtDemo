#! /usr/bin/env python
# -*- coding: utf-8 -*-

# Copyright (C) 2014~2016 Deepin, Inc.
#               2014~2016 penghui
#
# Author:     penghui <penghuilater@gmail.com>
# Maintainer: penghui <penghuilater@gmail.com>
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.

import sys
from PyQt5.QtWidgets import QWidget, QApplication, QFileDialog, QVBoxLayout
from PyQt5.QtCore import QBuffer, QDataStream, QSharedMemory
from PyQt5.QtGui import QImage, QPixmap

from dialog import MessageSender

class MainWindow(QWidget):
    def __init__(self, parent = None):
        super(MainWindow, self).__init__(parent)
        self.shareMemory = QSharedMemory('QSharedMemoryExample')

        self.ui = MessageSender()


        self.setWindowTitle("simple communication demo")
        self.mainLayout = QVBoxLayout()
        self.mainLayout.addWidget(self.ui)
        self.setFixedSize(500, 600)
        self.setLayout(self.mainLayout)



    def sendMessage(self):
        textbuf = QBuffer()
        textbuf.open(QBuffer.ReadWrite)
        messageText = QDataStream(textbuf)
        messageText << self.ui.messageBox.text
        size = textbuf.size()

        if not self.shareMemory.create(size):
            return

        size = min(self.shareMemory.size(), size)
        self.sharedMemory.lock()









if __name__ == '__main__':

    app = QApplication(sys.argv)
    mainWindow = MainWindow()
    mainWindow.show()
    sys.exit(app.exec_())


