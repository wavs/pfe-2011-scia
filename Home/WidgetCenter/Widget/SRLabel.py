import SRView as SRView
import sys
sys.path[:0] = ['../../']
from GfCenter.GfCenter import *

class SRLabel(SRView.SRView):
	
	def text():
	    doc = "The text property."
	    def fget(self):
	        return self._text
	    def fset(self, value):
	        self._text = value
	    def fdel(self):
	        del self._text
	    return locals()
	text = property(**text())
	
	def __init__(self, pos, size, tag, container, color, id, z, text):
		SRView.SRView.__init__(self, pos, size, tag, container, color, id, z)
		self.text = text
	
	def onMove(self, Notif):
		if not self.container is None:
			self.container.onClick(Notif)
	
	def display(self):
		gf = GfCenter()
		# display text
		#gf.drawMeSquare(self.x, self.y, self.w, self.h, self.color)
		for v in self.subView:
			v.display()
	
	def printInformation(self, n = 0):
		print "Widget [", self, "] id ",self.id, " floor ", n, " Node ", self.tag
		print "		Position[", self.x, ",", self.y, "] - Size[", self.w, ",", self.h, "]"
		print "		Tag[", self.tag, "] - Color[", self.color, "] - Text[", self.text, "]"
		print "		Container[", self.container, "]"
		for v in self.subView:
			v.printInformation(n + 1)