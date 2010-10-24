#!/usr/bin/env python
# encoding: utf-8
"""
WIColorTests.py

Created by Thomas Ait-taleb on 2010-10-23.
Copyright (c) 2010 Projet Home. All rights reserved.
"""

import unittest
from WIColor import *

class WIColorTests(unittest.TestCase):
	def setUp(self):
		pass

	def test_initWithoutParams(self):
		color = WIColor()
		self.assertEqual(color.red, 0)
		self.assertEqual(color.green, 0)
		self.assertEqual(color.blue, 0)
  
	def test_initWithParams(self):
		r = 42
		g = 67
		b = 600
  
		color = WIColor(r,g,b)
		self.assertEqual(color.red, r)
		self.assertEqual(color.green, g)
		self.assertEqual(color.blue, b)


if __name__ == '__main__':
	unittest.main()