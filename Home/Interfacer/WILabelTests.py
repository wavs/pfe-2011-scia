#!/usr/bin/env python
# encoding: utf-8
"""
WILabelTests.py

Created by Thomas Ait-taleb on 2010-10-23.
Copyright (c) 2010 Projet Home. All rights reserved.
"""

import unittest
from WILabel import *

class WIImageViewTests(unittest.TestCase):
	def setUp(self):
		pass
	
	def test_initWithoutParams(self):
		label = WILabel()
		self.assertEqual(label.bounds.x, 0)
		self.assertEqual(label.bounds.y, 0)
		self.assertEqual(label.bounds.h, 0)
		self.assertEqual(label.bounds.w, 0)
		self.assertEqual(label.tag, 0)
		self.assertEqual(label.backgroundColor.red, 0)
		self.assertEqual(label.backgroundColor.green, 0)
		self.assertEqual(label.backgroundColor.blue, 0)
		self.assertEqual(label.subviews, [])
		self.assertEqual(label.text, "")
		self.assertEqual(label.textColor.red, 0)
		self.assertEqual(label.textColor.green, 0)
		self.assertEqual(label.textColor.blue, 0)
		self.assertEqual(label.fontSize, 10)
		
	def test_initWithParams(self):
		bounds = WIBound(23,56,1,48)
		bgColor = WIColor(1,2,3)
		tag = 42
		text = "Helloworld!"
		textColor = WIColor(42, 23, 18)
		fontSize = 12
	
		label = WILabel(bounds, bgColor, tag, text, textColor, fontSize)
		label.addSubview('testView')
		self.assertEqual(label.bounds.x, bounds.x)
		self.assertEqual(label.bounds.y, bounds.y)
		self.assertEqual(label.bounds.h, bounds.h)
		self.assertEqual(label.bounds.w, bounds.w)
		self.assertEqual(label.tag, tag)
		self.assertEqual(label.backgroundColor.red, bgColor.red)
		self.assertEqual(label.backgroundColor.green, bgColor.green)
		self.assertEqual(label.backgroundColor.blue, bgColor.blue)
		self.assertEqual(label.subviews, ['testView'])
		self.assertEqual(label.text, text)
		self.assertEqual(label.textColor, textColor)
		self.assertEqual(label.fontSize, fontSize)


if __name__ == '__main__':
	unittest.main()