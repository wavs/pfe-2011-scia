#!/usr/bin/env python
# encoding: utf-8
"""
WIImageView.py

Created by Thomas Ait-taleb on 2010-10-20.
Copyright (c) 2010 Projet Home. All rights reserved.
"""

import unittest

from WIBound import *
from WIColor import *
from WIView import *

## Class : WIImageView<br/>
## This object contains the properties of a UI element which represents a view containing an image.
##	
class WIImageView(WIView):
	
	## Funtion init<br/>
	## Arguments :<br/>
	##			  - bounds : the initial position and size of the view
	##		    - backgroundColor : the initial background color
	##			  - tag : the unique identifier of the view
	##			  - imageFilename : the name of the image containing in the view
	##			  - userDefined : a boolean true if the behaviour of the view is defined by the user<br/>
	## Return : the object itself
	##	
	def __init__(self, bounds=WIBound(), backgroundColor=WIColor(), tag=0, imageFilename='', userDefined=False):
		WIView.__init__(self, bounds, backgroundColor, tag, userDefined)
		self.imageFilename = imageFilename

	## Funtion getImageFilename<br/>
	## Arguments :no<br/>
	## Return : the current name of the image file
	##	
	def getImageFilename(self):
		return self.imageFilename
	
	## Funtion setImageFilename<br/>
	## Arguments : the new name of the image file<br/>
	## Return :no
	##	
	def setImageFilename(self, imageFilename):
		self.imageFilename = imageFilename
	
	## Funtion prettyPrint<br/>
	## Arguments :<br/>
	##				- indent : indentation used by the pretty printer for hierarchical printing
	## Note : display the properties of the view <br/>
	## Return : no
	##	
	def prettyPrint(self, indent):
		print "\n#", indent, "WIImageView Element"
		print "#", indent, "Bounds: <", self.bounds.description(), ">"
		print "#", indent, "BackgroundColor: <", self.backgroundColor.description(), ">"
		print "#", indent, "Tag: <", self.tag, ">"
		print "#", indent, "User-defined: <", self.userDefined, ">"
		print "#", indent, "ImageFilename: <\'", self.imageFilename, "\'>"
		for subview in self.subviews:
			subview.prettyPrint(indent + "	")
		