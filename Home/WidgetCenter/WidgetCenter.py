from Widget.SRView import *
from Widget.SRButton import *
from Widget.SRImage import *
import glob

## Class : WidgetCenter<br/>
## This class handle the widgets
##
class WidgetCenter:
	
	widgetList = [] 
	
	## Funtion new<br/>
	## Arguments : no<br/>
	## Note : Singleton
	## Return : the object itself
	##	
	def __new__(self):
		if self.instance is None:
			self.instance = object.__new__(self)
		return self.instance

	## Funtion subscribeNewWidget<br/>
	## Arguments :<br/>
	##	- widget : Widget Object<br/>
	## Return : no
	##	
	def subscribeNewWidget(self, widget):
		self.widgetList.append(widget)

	## Funtion printWidgetList<br/>
	## Arguments : no<br/>
	## Note : display widgets information on the standard output<br/>
	## Return : no
	##
	def printWidgetList(self):
		for w in self.widgetList:
			w.printInformation()

	## Funtion getWidgetList<br/>
	## Arguments : no<br/>
	## Return : the widget list
	##
	def getWidgetList(self):
		return self.widgetList

	## Funtion deleteWidget<br/>
	## Arguments :<br/>
	##	- widget : widget object that has to be deleted<br/>
	## Return : no
	##
	def deleteWidget(self, widget):
		i = 0
		j = 0
		for w in self.widgetList:
			i += 1;
			if (w.getId() == widget.getId()):
				i = j
		if (j != 0):
			self.widgetList.pop(j)

	## Funtion examinNotif<br/>
	## Arguments :<br/>
	##	- notif : the notif object bringing new information<br/>
	## Return : The widget that has been notified
	##
	def examinNotif(self, notif):
		widgetNotified = None
		w = None
		if not notif is None:
			for widget in reversed(self.widgetList):
				if not widget is None:
					w = widget.isInsideView(notif.getxy()[0], notif.getxy()[1])
					return w
		return None
	
	def displayOnGF(self):
		listOfw = []
		for w in self.widgetList:
			if not w is None:
				if w.isDisplay == True:
					listOfw.append(w)
		while (len(listOfw) > 0):
			w = listOfw.pop(0)
			w.display()
			for subview in w.subView:
				listOfw.append(subview)
	
	def getViewWithTag(self, tag):
		for w in self.widgetList:
			r = w.getSubViewWithTag(tag)
			if not r is None :
				return r
		return None
	
	def returnToNormal(self):
		for w in self.widgetList:
			w.goBackColor()

	def getWidgetMenu(self):
		viewPrincipal = SRView.SRView((0,0), (800, 80), "Menu", None, (0.4, 0.4, 0.4), 1)
		x = 1
		i = 200
		files = glob.glob("../Widgets/WidgetsIcons/*")
		nb = 0;
		for w in self.widgetList:
			image = SRImage([x, 1], (50, 50), "Image"+files[nb], viewPrincipal, (0, 0, 0), i+100, files[nb])
			viewPrincipal.addSubView(image)
			def clickOnWidget():
				w.changeDisplayMode()
				w.printInformation()
			b = SRButton([x , 52], (50, 28), "Button"+str(i), viewPrincipal, (1, 1, 1), i, clickOnWidget, w.tag)
			i += 1
			x += 52
			nb += 1
			viewPrincipal.addSubView(b)
		viewPrincipal.setDisplay(True)
		return viewPrincipal