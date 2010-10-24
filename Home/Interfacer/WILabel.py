#!/usr/bin/env python
# encoding: utf-8
"""
WILabel.py

Created by Thomas Ait-taleb on 2010-10-20.
Copyright (c) 2010 Projet Home. All rights reserved.
"""

import unittest
from WIView import *
from WIColor import *

## Class : WILabel<br/>
## This object contains the properties of a UI element which represents a view containing a text label.
##	
class WILabel(WIView):
	
	## Funtion init<br/>
	## Arguments :<br/>
	##			  - bounds : the initial position and size of the view
	##		    - backgroundColor : the initial background color
	##			  - tag : the unique identifier of the view
	##			  - text : the initial text containing in the label
	##				- textColor : the initial color of the text
	##				- fontSize : the initial size of the font used by the label to write the text
	##			  - userDefined : a boolean true if the behaviour of the view is defined by the user<br/>
	## Return : the object itself
	##	
	def __init__(self, bounds=WIBound(), backgroundColor=WIColor(), tag=0, text='', textColor=WIColor(), fontSize=10, userDefined=False):
		WIView.__init__(self, bounds, backgroundColor, tag, userDefined)
		self.text = text
		self.textColor = textColor
		self.fontSize = fontSize
	
	## Funtion getText<br/>
	## Arguments :no<br/>
	## Return : the current text of the view
	##	
	def getText(self):
		return self.text
	
	## Funtion setText<br/>
	## Arguments : the new text of the view file<br/>
	## Return :no
	##	
	def setText(self, text):
		self.text = text
	
	## Funtion getTextColor<br/>
	## Arguments :no<br/>
	## Return : the current color of the text
	##	
	def getTextColor(self):
		return self.textColor
	
	## Funtion setTextColor<br/>
	## Arguments : the new color of the text<br/>
	## Return :no
	##	
	def setTextColor(self, textColor):
		self.textColor = textColor
	
	## Funtion getFontSize<br/>
	## Arguments :no<br/>
	## Return : the current size of the font
	##	
	def getFontSize(self):
		return self.fontSize
	
	## Funtion setFontSize<br/>
	## Arguments : the new size of the font<br/>
	## Return :no
	##	
	def setFontSize(self, fontSize):
		self.fontSize = fontSize
	
	## Funtion prettyPrint<br/>
	## Arguments :<br/>
	##				- indent : indentation used by the pretty printer for hierarchical printing
	## Note : display the properties of the view <br/>
	## Return : no
	##	
	def prettyPrint(self, indent):
		print "\n#", indent, "WILabel Element"
		print "#", indent, "Bounds: <", self.bounds.description(), ">"
		print "#", indent, "BackgroundColor: <", self.backgroundColor.description(), ">"
		print "#", indent, "Tag: <", self.tag, ">"
		print "#", indent, "User-defined: <", self.userDefined, ">"
		print "#", indent, "Text: <\'", self.text, "\'>"
		print "#", indent, "TextColor: <", self.textColor.description(), ">"
		print "#", indent, "FontSize: <", self.fontSize, ">"
		for subview in self.subviews:
			subview.prettyPrint(indent + "	")
		