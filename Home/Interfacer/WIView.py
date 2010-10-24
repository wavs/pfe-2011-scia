#!/usr/bin/env python
# encoding: utf-8
"""
WIView.py

Created by Thomas Ait-taleb on 2010-10-20.
Copyright (c) 2010 Projet Home. All rights reserved.
"""

from WIBound import *
from WIColor import *

## Class : WIView<br/>
## This object contains the properties of a UI element which represents a basic view.
##	
class WIView:
	
	## Funtion init<br/>
	## Arguments :<br/>
	##			  - bounds : the initial position and size of the view
	##		    - backgroundColor : the initial background color
	##			  - tag : the unique identifier of the view
	##			  - userDefined : a boolean true if the behaviour of the view is defined by the user<br/>
	## Return : the object itself
	##	
	def __init__(self, bounds=WIBound(), backgroundColor=WIColor(), tag=0, userDefined=False):
		self.bounds = bounds
		self.backgroundColor = backgroundColor
		self.tag = tag
		self.userDefined = userDefined
		self.subviews = []
		self.needsDiplay = True
	
	## Funtion getBounds<br/>
	## Arguments :no<br/>
	## Return : the current position and size of the view
	##	
	def getBounds(self):
		return self.bounds
	
	## Funtion setBounds<br/>
	## Arguments : the new position and new size of the view<br/>
	## Return :no
	##	
	def setBounds(self, bounds):
		self.bounds = bounds
	
	## Funtion getBackgroundColor<br/>
	## Arguments :no<br/>
	## Return : the current background color of the view
	##	
	def getBackgroundColor(self):
		return self.backgroundColor
	
	## Funtion setBackgroundColor<br/>
	## Arguments : the new background color of the view<br/>
	## Return :no
	##	
	def setBackgroundColor(self, color):
		self.backgroundColor = color
	
	## Funtion getTag<br/>
	## Arguments :no<br/>
	## Return : the unique identifier of the view
	##	
	def getTag(self):
		return self.tag
	
	## Funtion getUserDefined<br/>
	## Arguments :no<br/>
	## Note : true if the view behaviour is defined by the user
	## Return : the userDefined boolean of the view
	##	
	def getUserDefined(self):
		return self.userDefined
	
	## Funtion setUserDefined<br/>
	## Arguments : the new userDefined boolean of the view
	## Note : true if the view behaviour is defined by the user<br/>
	## Return :no
	##	
	def setUserDefined(self, userDefined):
		self.userDefined = userDefined
	
	## Funtion getNeedsDisplay<br/>
	## Arguments :no<br/>
	## Note : true if the view needs to be redrew<br/>
	## Return : the needsDisplay boolean of the view
	##	
	def getNeedsDisplay(self):
		return self.needsDiplay
	
	## Funtion setNeedsDisplay<br/>
	## Arguments : the new needsDisplay boolean of the view
	## Note : true if the view needs to be redrew<br/>
	## Return :no
	##	
	def setNeedsDisplay(self, needsDisplay):
		self.needsDisplay = needsDisplay

	## Funtion addSubview<br/>
	## Arguments :<br/>
	##				- subview : subview of the current view
	## Note : add a subview to the current view (hierarchical organization of the interface)<br/>
	## Return : no
	##	
	def addSubview(self, subview):
		self.subviews.append(subview)
	
	## Funtion prettyPrint<br/>
	## Arguments :<br/>
	##				- indent : indentation used by the pretty printer for hierarchical printing
	## Note : display the properties of the view <br/>
	## Return : no
	##	
	def prettyPrint(self, indent):
		print "\n#", indent, "WIView Element"
		print "#", indent, "Bounds: <", self.bounds.description(), ">"
		print "#", indent, "BackgroundColor: <", self.backgroundColor.description(), ">"
		print "#", indent, "Tag: <", self.tag, ">"
		print "#", indent, "User-defined: <", self.userDefined, ">"
		for subview in self.subviews:
			subview.prettyPrint(indent + "	")
		
		