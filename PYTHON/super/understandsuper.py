#!/usr/bin python3
import logging

class LoggingDict(dict):
    def __setitem__(self, key, value):
        logging.info('Settingto %r' % (key, value))
        super().__setitem__(key, value)



a = LoggingDict()
a = {'penghui': 'come on', 'snoppy': 'come down'}
b = a.get('penghui')
print a
print b
