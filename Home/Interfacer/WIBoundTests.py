#!/usr/bin/env python
# encoding: utf-8
"""
WIBoundTests.py

Created by Thomas Ait-taleb on 2010-10-23.
Copyright (c) 2010 Projet Home. All rights reserved.
"""

import unittest
from WIBound import *

class WIBoundTests(unittest.TestCase):
	def setUp(self):
		pass

	def test_initWithoutParams(self):
		bounds = WIBound()
		self.assertEqual(bounds.x, 0)
		self.assertEqual(bounds.y, 0)
		self.assertEqual(bounds.h, 0)
		self.assertEqual(bounds.w, 0)
	
	def test_initWithParams(self):
		x = 42
		y = 67
		h = 600
		w = 800
	
		bounds = WIBound(x,y,w,h)
		self.assertEqual(bounds.x, x)
		self.assertEqual(bounds.y, y)
		self.assertEqual(bounds.h, h)
		self.assertEqual(bounds.w, w)


if __name__ == '__main__':
	unittest.main()