from Widget.Widget import *

class WidgetCenter:
	
	widgetList =[] 
	
	def __new__(self):
		if self.instance is None:
			self.instance = object.__new__(self)
		return self.instance
	
	def subscribeNewWidget(self, widget):
		self.widgetList.push(widget)

	def deleteWidget(self, widget):
		i = 0
		j = 0
		for w in self.widgetList:
			i += 1;
			if (w.getId() == widget.getId()):
				i = j
		if (j != 0):
			self.widgetList.pop(j)

	def examinNotif(self, notif):
		widgetNotified = None
		maxZ = 0
		for widget in self.widgetList:
			t = widget.clickInsideWidget(notif.getxy()[0], notif.getxy()[1])
			if (t[0] == True):
				if (maxZ < t[1]):
					widgetNotified = widget
					maxZ = t[1]
		return widgetNotified