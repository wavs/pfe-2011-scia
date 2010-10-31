from Widget.SRView import *

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
		maxZ = 0
		if not notif is None:
			for widget in self.widgetList:
				w = widget.isInsideView(notif.getxy()[0], notif.getxy()[1])
				if not w is None:
					print w.tag
				else:
					print "No view inside"
		return w
	
	def displayOnGF(self):
		for w in self.widgetList:
			w.display()
	
	def getViewWithTag(self, tag):
		for w in self.widgetList:
			r = w.getSubViewWithTag(tag)
			if not r is None :
				return r
		return None