#!/usr/bin/env python
# encoding: utf-8
"""
WILoader.py

Created by Thomas Ait-taleb on 2010-10-23.
Copyright (c) 2010 Projet Home. All rights reserved.
"""

import sys
import os
import xml.dom.minidom as parser
from WIView import *
from WIImageView import *
from WILabel import *
from WIBound import *
from WIColor import *

import unittest

## Class : WILoader<br/>
## This object loads an xml file and creates the hierarchical structure of the associated widget interface.
##	
class WILoader:
	
	## Funtion init<br/>
	## Arguments :no<br/>
	## Return : the object itself
	##	
	def __init__(self):
		pass
	
	## Funtion loadFile<br/>
	## Arguments :<br/>
	##				- filename : name of the file to load
	## Note : load an xml file<br/>
	## Return : the interface structure
	##	
	def loadFile(self, filename):
		dom = parser.parse(filename)
		interface = self.handleInterface(dom)
		return interface
	
	## Funtion handleInterface<br/>
	## Arguments :<br/>
	##				- interface : root element of the DOM object from the xml file
	## Note : handle the child nodes of the root element<br/>
	## Return : the root view
	##	
	def handleInterface(self, interface):
		main_wi_view = interface.getElementsByTagName("WIView")[0]
		if (main_wi_view):
			mainWiViewElement = self.handleView(main_wi_view)
		return mainWiViewElement
	
	## Funtion handleSubviews<br/>
	## Arguments :<br/>
	##				- currentView : current element of the DOM object
	## Note : handle the child nodes of the current element <br/>
	## Return : a list of the child views (subviews of the current view)
	##	
	def handleSubviews(self, currentView):
		listSubviews = []
		subviews = currentView.childNodes
		
		if (len(subviews) > 0):
			for subview in subviews:
				""" 1 == ELEMENT_NODE SYMBOLIC CONSTANT """
				if (subview.nodeType == 1):
					elt = self.handleView(subview)
					if (elt):
						listSubviews.append(elt)
		return listSubviews
	
	## Funtion getBounds<br/>
	## Arguments :<br/>
	##				- boundsString : formatted string representing bound informations
	## Note : convert a bound string to a bound object<br/>
	## Return : the associated bound object
	##	
	def getBounds(self, boundsString):
		elts = boundsString.split(':')
		position = elts[0].split(',')
		size = elts[1].split(',')
		x = position[0]
		y = position[1]
		w = size[0]
		h = size[1]
		return WIBound(x, y, w, h)
	
	## Funtion getColor<br/>
	## Arguments :<br/>
	##				- colorString : formatted string representing a color
	## Note : convert a color string to a color object<br/>
	## Return : no
	##	
	def getColor(self, colorString):
		colors = colorString.split(',')
		r = colors[0]
		g = colors[1]
		b = colors[2]
		return WIColor(r, g, b)
	
	## Funtion handleView<br/>
	## Arguments :<br/>
	##				- view : current element of the DOM object
	## Note : create the current view from the current DOM element and handle the child nodes<br/>
	## Return : the current view
	##	
	def handleView(self, view):
		""" Get attributes """
		boundsAttr = view.getAttribute('bounds')
		tagAttr = view.getAttribute('tag')
		backgroundColorAttr = view.getAttribute('backgroundColor')
		userDefinedAttr = view.getAttribute('user-defined')
		""" Convert objects """
		bounds = self.getBounds(boundsAttr)
		tag = int(tagAttr)
		backgroundColor = self.getColor(backgroundColorAttr)
		userDefined = None
		if (userDefinedAttr == '0'):
			userDefined = False
		else:
			userDefined = True
		
		viewElement = None
		if (view.tagName == "WIView"):
			viewElement = WIView(bounds, backgroundColor, tag, userDefined)
		
		if (view.tagName == "WIImageView"):
			imageFilename = view.getAttribute('image')
			viewElement = WIImageView(bounds, backgroundColor, tag, imageFilename, userDefined)
		
		if (view.tagName == "WILabel"):
			text = view.getAttribute('text')
			textColorAttr = view.getAttribute('textColor')
			fontSizeAttr = view.getAttribute('fontSize')
			textColor = self.getColor(textColorAttr)
			fontSize = int(fontSizeAttr)
			viewElement = WILabel(bounds, backgroundColor, tag, text, textColor, fontSize, userDefined)
		
		subviews = self.handleSubviews(view)
		if (len(subviews) > 0):
			for subview in subviews:
				viewElement.addSubview(subview)
		return viewElement
