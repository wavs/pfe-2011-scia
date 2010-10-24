#!/usr/bin/env python
# encoding: utf-8
"""
WIViewTests.py

Created by Thomas Ait-taleb on 2010-10-23.
Copyright (c) 2010 Projet Home. All rights reserved.
"""

import unittest
from WIView import *

class WIViewTests(unittest.TestCase):
	
	def setUp(self):		
		pass
	
	def test_initWithoutParams(self):
		view = WIView()
		self.assertEqual(view.bounds.x, 0)
		self.assertEqual(view.bounds.y, 0)
		self.assertEqual(view.bounds.h, 0)
		self.assertEqual(view.bounds.w, 0)
		self.assertEqual(view.tag, 0)
		self.assertEqual(view.backgroundColor.red, 0)
		self.assertEqual(view.backgroundColor.green, 0)
		self.assertEqual(view.backgroundColor.blue, 0)
		self.assertEqual(view.subviews, [])
	
	def test_initWithParams(self):
		x = 42
		y = 67
		h = 600
		w = 800
		r = 12
		g = 34
		b = 89
		tag = 123
		viewTest = "test"
		
		view = WIView(WIBound(x,y,w,h), WIColor(r,g,b), tag)
		view.addSubview(viewTest)
		self.assertEqual(view.bounds.x, x)
		self.assertEqual(view.bounds.y, y)
		self.assertEqual(view.bounds.h, h)
		self.assertEqual(view.bounds.w, w)
		self.assertEqual(view.backgroundColor.red, r)
		self.assertEqual(view.backgroundColor.green, g)
		self.assertEqual(view.backgroundColor.blue, b)
		self.assertEqual(view.tag, tag)
		self.assertEqual(view.subviews, [viewTest])

if __name__ == '__main__':
	unittest.main()