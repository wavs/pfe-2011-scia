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
	
	def subView():
	    doc = "The subView property."
	    def fget(self):
	        return self._subView
	    def fset(self, value):
	        self._subView = value
	    def fdel(self):
	        del self._subView
	    return locals()
	subView = property(**subView())
	
	def isDisplay():
	    doc = "The isDisplay property."
	    def fget(self):
	        return self._isDisplay
	    def fset(self, value):
	        self._isDisplay = value
	    def fdel(self):
	        del self._isDisplay
	    return locals()
	isDisplay = property(**isDisplay())
	
	def __init__(self, pos, size, tag, container, color, id):
		self.x = (float)(pos[0])
		self.y = (float)(pos[1])
		self.w = (float)(size[0])
		self.h = (float)(size[1])
		self.tag = tag
		self.color = ((float)(color[0]), (float)(color[1]), (float)(color[2]))
		self.refColor = self.color
		self.container = container
		self.subView = []
		self.id = id
		self.isDisplay = False

	def setDisplay(self, value):
		self.isDisplay = value
		for v in self.subView:
			v.setDisplay(value)

	def changeDisplayMode(self):
		if self.isDisplay == True:
			self.setDisplay(False)
		else:
			self.setDisplay(True)

	def printInformation(self, n = 0):
		print "Widget [", self, "] id ",self.id, " floor ", n, " Node ", self.tag
		print "		Position[", self.x, ",", self.y, "] - Size[", self.w, ",", self.h, "]"
		print "		Tag[", self.tag, "] - Color[", self.color, "]"
		print "		Container[", self.container, "]"
		print "		isDisplay : ", self.isDisplay
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
	
	def getOriginView(self):
		if not self.container is None:
			return self
		else:
			return self.container.getOriginView()
	

	def onPress(self, Notif):
		#self.color = (1.0, 1.0, 1.0)
		if not self.container is None:
			self.container.onPress(Notif)
	
	def onMove(self, Notif):
		#self.color = (1.0, 1.0, 1.0)
		if not self.container is None:
			self.container.onMove(Notif)
		else:
			(x, y) = Notif.getxy()
			(x0, y0) = Notif.getx0y0()
			dx = self.x
			dy = self.y
			self.x = x - self.w / 2
			self.y = y - self.h / 2
			for v in self.subView:
				v.move(self.x - dx, self.y - dy)
	
	def move(self, dx, dy):
		self.x += dx
		self.y += dy
		for v in self.subView:
			v.move(dx, dy)
	
	def onClick(self, Notif):
		print "Click on me"
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
			for v in reversed(self.subView):
				r = v.isInsideView(x, y)
				if not r is None:
					return r
			return self
		else:
			return None

	def getSubViewWithTag(self, tag):
		if self.tag == tag:
			return self
		for v in self.subView:
			r = v.getSubViewWithTag(tag)
			if not r is None:
				return r
		return None
			
	def setNotif(self, Notif):
		eval("self.on"+Notif.label+"(Notif)");

	def display(self):
		gf = GfCenter()
		gf.drawMeSquare(self.x, self.y, self.w, self.h, (self.color[0], self.color[1], self.color[2]))
		for v in self.subView:
			v.display()
	#	self.color = self.refColor
	
	def exit(self):
		if not self.container is None:
			self.container.onClick(Notif)
	
	def goBackColor(self):
		self.color = self.refColor