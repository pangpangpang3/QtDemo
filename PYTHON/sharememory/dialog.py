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
from PyQt5.QtWidgets import QApplication, QWidget, QTextEdit, QLabel, QLineEdit, QPushButton, QVBoxLayout, QHBoxLayout
#from PyQt5.QtCore import QSize

class MessageSender(QWidget):
    def __init__(self, parent=None):
        super(MessageSender, self).__init__(parent)

        self.messageHistory = QTextEdit()
        #self.messageHistory.setFixedSize(QSize(400, 500))
        self.loadImage = QPushButton("loadImage")
        self.showImage = QPushButton('showImage')
        self.messageBoxLabel = QLabel("Message:")
        self.sendMessageButton = QPushButton("Send")
        self.messageBox = QLineEdit()
        #self.messageBox.sizeHint()
        self.imageLoadLayout = QHBoxLayout()
        self.imageLoadLayout.addWidget(self.loadImage)
        self.imageLoadLayout.addWidget(self.showImage)
        self.imageLoadLayout.addStretch()

        self.messageBoxLayout = QHBoxLayout()
        self.messageBoxLayout.addWidget(self.messageBoxLabel)
        self.messageBoxLayout.addWidget(self.messageBox)
        self.messageBoxLayout.addWidget(self.sendMessageButton)

        self.mainLayout = QVBoxLayout()
        self.mainLayout.addWidget(self.messageHistory)
        self.mainLayout.addLayout(self.imageLoadLayout)
        self.mainLayout.addLayout(self.messageBoxLayout)
        self.setLayout(self.mainLayout)
#if __name__ == '__main__':
#    app = QApplication(sys.argv)
#    window = MessageSender()
#    window.show()
#    app.exit(app.exec_())
