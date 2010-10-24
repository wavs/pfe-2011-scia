#!/usr/bin/env python
# encoding: utf-8
"""
WIBound.py

Created by Thomas Ait-taleb on 2010-10-20.
Copyright (c) 2010 Projet Home. All rights reserved.
"""

import unittest

## Class : WIBound<br/>
## This object contains the position and the size of a widget UI element.
##	
class WIBound:
	
	## Funtion init<br/>
	## Arguments :<br/>
	##			  - x : the initial position x of the UI element
	##		    - y : the initial position y of the UI element
	##			  - w : the initial width of the UI element
	##			  - h : the initial height of the UI element<br/>
	## Return : the object itself
	##	
	def __init__(self, x=0, y=0, w=0, h=0):
		self.x = x
		self.y = y
		self.w = w
		self.h = h
	
	## Funtion getX<br/>
	## Arguments :no<br/>
	## Return : the current position x
	##	
	def getX(self):
		return self.x
	
	## Funtion setX<br/>
	## Arguments : the new position x<br/>
	## Return :no
	##	
	def setX(self, x):
		self.x = x

	## Funtion getY<br/>
	## Arguments :no<br/>
	## Return : the current position y
	##	
	def getY(self):
		return self.y
	
	## Funtion setY<br/>
	## Arguments : the new position y<br/>
	## Return :no
	##  
	def setY(self, y):
		self.y = y
	
	## Funtion getWidth<br/>
	## Arguments :no<br/>
	## Return : the current width
	##	
	def getWidth(self):
		return self.w
	
	## Funtion setWidth<br/>
	## Arguments : the new width x<br/>
	## Return :no
	##  
	def setWidth(self, w):
		self.w = w
	
	## Funtion getHeight<br/>
	## Arguments :no<br/>
	## Return : the current height
	##	
	def getHeight(self):
		return self.h
 	
	## Funtion setHeight<br/>
	## Arguments : the new height x<br/>
	## Return :no
	##	
	def setHeight(self, h):
		self.h = h
	
	## Funtion description<br/>
	## Arguments :no<br/>
	## Note : display information about the position and the size of a UI element<br/>
	## Return : no
	##	
	def description(self):
		return str(self.x) + ',' + str(self.y) + ':' + str(self.w) + ',' + str(self.h)
	