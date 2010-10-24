#!/usr/bin/env python
# encoding: utf-8
"""
WIColor.py

Created by Thomas Ait-taleb on 2010-10-20.
Copyright (c) 2010 Projet Home. All rights reserved.
"""

import unittest

## Class : WIColor<br/>
## This object contains the three components of a color used in a widget UI element.
##	
class WIColor:
	
	## Funtion init<br/>
	## Arguments :<br/>
	##			  - r : red component
	##		    - g : green component
	##			  - b : blue component<br/>
	## Return : the object itself
	##	
	def __init__(self, r=0, g=0, b=0):
		self.red = r
		self.green = g
		self.blue = b
	
	## Funtion getRed<br/>
	## Arguments :no<br/>
	## Return : the current red component
	##	
	def getRed(self):
		return self.red
	
	## Funtion setRed<br/>
	## Arguments : the new red component<br/>
	## Return :no
	##	
	def setRed(self, r):
		self.red = r
	
	## Funtion getGreen<br/>
	## Arguments :no<br/>
	## Return : the current green component
	##	
	def getGreen(self):
		return self.green
	
	## Funtion setGreen<br/>
	## Arguments : the new green component<br/>
	## Return :no
	##	
	def setGreen(self, g):
		self.green = g
	
	## Funtion getBlue<br/>
	## Arguments :no<br/>
	## Return : the current blue component
	##	
	def getBlue(self):
		return self.blue
	
	## Funtion setBlue<br/>
	## Arguments : the new blue component<br/>
	## Return :no
	##	
	def setBlue(self, b):
		self.blue = b
	
	## Funtion description<br/>
	## Arguments :no<br/>
	## Note : display information about the three components of a color used in a UI element<br/>
	## Return : no
	##	
	def description(self):
		return str(self.red) + ',' + str(self.green) + ',' + str(self.blue)
