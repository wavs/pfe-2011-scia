#!/usr/bin/env python
# encoding: utf-8
"""
WIImageViewTests.py

Created by Thomas Ait-taleb on 2010-10-23.
Copyright (c) 2010 Projet Home. All rights reserved.
"""

import unittest
from WIImageView import *

class WIImageViewTests(unittest.TestCase):
	def setUp(self):
		pass
	
	def test_initWithoutParams(self):
		imageView = WIImageView()
		self.assertEqual(imageView.bounds.x, 0)
		self.assertEqual(imageView.bounds.y, 0)
		self.assertEqual(imageView.bounds.h, 0)
		self.assertEqual(imageView.bounds.w, 0)
		self.assertEqual(imageView.backgroundColor.red, 0)
		self.assertEqual(imageView.backgroundColor.green, 0)
		self.assertEqual(imageView.backgroundColor.blue, 0)
		self.assertEqual(imageView.tag, 0)
		self.assertEqual(imageView.subviews, [])
		self.assertEqual(imageView.imageFilename, '')
	
	def test_initWithParams(self):
		bounds = WIBound(12,31,45,63)
		bgColor = WIColor(1,2,3)
		tag = 42
		filename = "clown.jpg"
		viewTest = "test"
	
		imageView = WIImageView(bounds, bgColor, tag, filename)
		imageView.addSubview(viewTest)
		self.assertEqual(imageView.bounds.x, bounds.x)
		self.assertEqual(imageView.bounds.y, bounds.y)
		self.assertEqual(imageView.bounds.h, bounds.h)
		self.assertEqual(imageView.bounds.w, bounds.w)
		self.assertEqual(imageView.backgroundColor.red, bgColor.red)
		self.assertEqual(imageView.backgroundColor.green, bgColor.green)
		self.assertEqual(imageView.backgroundColor.blue, bgColor.blue)
		self.assertEqual(imageView.tag, tag)
		self.assertEqual(imageView.subviews, [viewTest])
		self.assertEqual(imageView.imageFilename, filename)


if __name__ == '__main__':
	unittest.main()