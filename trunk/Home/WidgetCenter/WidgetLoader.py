import sys
import os
import xml.dom.minidom as parser
from Widget.SRView import SRView
from Widget.SRImage import SRImage
from Widget.SRLabel import SRLabel
from Widget.SRMovable import SRMovable
from Widget.SRFixe import SRFixe

## Class : WidgetLoader<br/>
## This object loads an xml file and creates the hierarchical structure of the associated widget interface.
##	
class WidgetLoader:
	
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
		main_wi_view = interface.getElementsByTagName("SRView")[0]
		if (main_wi_view):
			mainWiViewElement = self.handleView(main_wi_view, None)
		return mainWiViewElement
	
	## Funtion handleSubviews<br/>
	## Arguments :<br/>
	##				- currentView : current element of the DOM object
	## Note : handle the child nodes of the current element <br/>
	## Return : a list of the child views (subviews of the current view)
	##	
	def handleSubviews(self, currentView, currentViewElt):
		listSubviews = []
		subviews = currentView.childNodes
		
		if (len(subviews) > 0):
			for subview in subviews:
				""" 1 == ELEMENT_NODE SYMBOLIC CONSTANT """
				if (subview.nodeType == 1):
					elt = self.handleView(subview, currentViewElt)
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
		return (position, size)
	
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
		return colors
	
	## Funtion handleView<br/>
	## Arguments :<br/>
	##				- view : current element of the DOM object
	## Note : create the current view from the current DOM element and handle the child nodes<br/>
	## Return : the current view
	##	
	def handleView(self, view, father):
		""" Get attributes """
		boundsAttr = view.getAttribute('bounds')
		tagAttr = view.getAttribute('tag')
		backgroundColorAttr = view.getAttribute('backgroundColor')
		className = view.getAttribute('class')
		id = view.getAttribute('id')
		
		""" Convert objects """
		(position, size) = self.getBounds(boundsAttr)
		tag = int(tagAttr)
		backgroundColor = self.getColor(backgroundColorAttr)
		
		viewElement = None
		if (view.tagName == "SRView"):
			viewElement = SRView(position, size, tag, father, backgroundColor, id)
		
		if (view.tagName == "SRImageView"):
			imageFilename = view.getAttribute('imageFilename')
			viewElement = SRImage(position, size, tag, father, backgroundColor, id, imageFilename)
		
		if (view.tagName == "SRLabel"):
			text = view.getAttribute('text')
			textColorAttr = view.getAttribute('textColor')
			fontName = view.getAttribute('fontName')
			fontSizeAttr = view.getAttribute('fontSize')
			textColor = self.getColor(textColorAttr)
			fontSize = int(fontSizeAttr)
			viewElement = SRLabel(position, size, tag, father, backgroundColor, id, text)

		if (view.tagName == "SRMovable"):
			viewElement = SRMovable(position, size, tag, father, backgroundColor, id)
			
		if (view.tagName == "SRFixe"):
			viewElement = SRFixe(position, size, tag, father, backgroundColor, id)	

		subviews = self.handleSubviews(view, viewElement)
		if (len(subviews) > 0):
			for subview in subviews:
				viewElement.addSubView(subview)
		return viewElement

# TESTS
#wl = WidgetLoader()
#widget = wl.loadFile("/Users/wavs/Desktop/testFile.xml")
#widget.printInformation(0)
