#!/usr/bin/env python
# encoding: utf-8
"""
WILoaderTests.py

Created by Thomas Ait-taleb on 2010-10-24.
Copyright (c) 2010 Projet Home. All rights reserved.
"""

import unittest
from WILoader import *


class WILoaderTests(unittest.TestCase):
	def setUp(self):
		self.interfaceLoader = WILoader()
		pass
	
	def test_loadTestFile(self):
		interface = self.interfaceLoader.loadFile("xml/ui_test2.xml")
		interface.prettyPrint('')

if __name__ == '__main__':
	unittest.main()