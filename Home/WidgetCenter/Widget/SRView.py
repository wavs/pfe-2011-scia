import sys
sys.path[:0] = ['../../']
from GfCenter.GfCenter import *

class SRView:
	
	def x():
	    doc = "The x property."
	    def fget(self):
	        return self._x
	    def fset(self, value):
	        self._x = value
	    def fdel(self):
	        del self._x
	    return locals()
	x = property(**x())
	
	def y():
	    doc = "The y property."
	    def fget(self):
	        return self._y
	    def fset(self, value):
	        self._y = value
	    def fdel(self):
	        del self._y
	    return locals()
	y = property(**y())
	
	def w():
	    doc = "The w property."
	    def fget(self):
	        return self._w
	    def fset(self, value):
	        self._w = value
	    def fdel(self):
	        del self._w
	    return locals()
	w = property(**w())	
	
	def h():
	    doc = "The h property."
	    def fget(self):
	        return self._h
	    def fset(self, value):
	        self._h = value
	    def fdel(self):
	        del self._h
	    return locals()
	h = property(**h())
	
	def tag():
	    doc = "The tag property."
	    def fget(self):
	        return self._tag
	    def fset(self, value):
	        self._tag = value
	    def fdel(self):
	        del self._tag
	    return locals()
	tag = property(**tag())

	
	def container():
	    doc = "The container property."
	    def fget(self):
	        return self._container
	    def fset(self, value):
	        self._container = value
	    def fdel(self):
	        del self._container
	    return locals()
	container = property(**container())
	
	def color():
	    doc = "The color property."
	    def fget(self):
	        return self._color
	    def fset(self, value):
	        self._color = value
	    def fdel(self):
	        del self._color
	    return locals()
	color = property(**color())
	
	
	def __init__(self, pos, size, tag, container, color, id):
		self.x = pos[0]
		self.y = pos[1]
		self.w = size[0]
		self.h = size[1]
		self.tag = tag
		self.color = color
		self.container = container
		self.subView = []
		self.id = id

	def printInformation(self, n = 0):
		print "Widget id ",self.id, " floor ", n, " Node ", self.tag
		for v in self.subView:
			v.printInformation(n + 1)
	
	def addSubView(self, newView):
		self.subView.append(newView)	
	
	def delSubViewByTab (self, tag):
		n = 0
		for v in self.subView:
			if v.tag == tag:
				self.subView.pop(n)
				return True
			return v.delSubViewByTab(tag)
		return False
	
	def onPress(self, Notif):
		if not self.container is None:
			self.container.onPress(Notif)
	
	def onMove(self, Notif):
		if not self.container is None:
			self.container.onMove(Notif)
		else:
			(x, y) = notif.getxy()
			(x0, y0) = notif.getx0y0()
			self.x = self.x + x - x0
			self.y = self.y + y - y0
	
	def onClick(self, Notif):
		if not self.container is None:
			self.container.onClick(Notif)
	
	def onPressLong(self, Notif):
		if not self.container is None:
			self.container.onPressLong(Notif)
				
	def onClickLong(self, Notif):
		if not self.container is None:
			self.container.onClickLong(Notif)
	
	def isInsideView(self, x, y):
		if ((x > self.x) and (x < self.x + self.w) and (y > self.y) and (y < self.y + self.h)):
			for v in self.subView:
				r = v.isInsideView(x, y)
				if not r is None:
					return r
			return self
		else:
			return None

	def setNotif(self, Notif):
		eval("self.on"+Notif.label+"(Notif)");

	def display(self):
		gf = GfCenter()
		gf.drawMeSquare(self.x, self.y, self.w, self.h, self.color)
		for v in self.subView:
			v.display()
	
	def exit(self):
		if not self.container is None:
			self.container.onClick(Notif)