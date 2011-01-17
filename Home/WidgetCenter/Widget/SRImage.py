import SRView as SRView
import sys
sys.path[:0] = ['../../']
from GfCenter.GfCenter import *

class SRImage(SRView.SRView):
	
	def link():
	    doc = "The text property."
	    def fget(self):
	        return self._link
	    def fset(self, value):
	        self._link = value
	    def fdel(self):
	        del self._link
	    return locals()
	link = property(**link())
	
	def idImage():
	    doc = "The idImage property."
	    def fget(self):
	        return self._idImage
	    def fset(self, value):
	        self._idImage = value
	    def fdel(self):
	        del self._idImage
	    return locals()
	idImage = property(**idImage())
	
	def __init__(self, pos, size, tag, container, color, id, link):
		SRView.SRView.__init__(self, pos, size, tag, container, color, id)
		self.link = link
		gf = GfCenter()
		self.idImage = 0
		gf.registerToLoadTexture(self)

	def onMove(self, Notif):
		if not self.container is None:
			self.container.onClick(Notif)
	
	def display(self):
		gf = GfCenter()
		gf.drawMeTexturedSquare(self.x, self.y, self.w, self.h, self.color, self.idImage)
		for v in self.subView:
			v.display()
	
	def printInformation(self, n = 0):
		print "Widget [", self, "] id ",self.id, " floor ", n, " Node ", self.tag
		print "		Position[", self.x, ",", self.y, "] - Size[", self.w, ",", self.h, "]"
		print "		Tag[", self.tag, "] - Color[", self.color, "] - Image[", self.link, "]"
		print "		Container[", self.container, "]"
		for v in self.subView:
			v.printInformation(n + 1)