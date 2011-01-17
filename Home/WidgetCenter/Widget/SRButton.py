import SRView as SRView
import sys
sys.path[:0] = ['../../']
from GfCenter.GfCenter import *

class SRButton(SRView.SRView):
	
	def action():
	    doc = "The action property."
	    def fget(self):
	        return self._action
	    def fset(self, value):
	        self._action = value
	    def fdel(self):
	        del self._action
	    return locals()
	action = property(**action())
	
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
	
	def __init__(self, pos, size, tag, container, color, id, action, text = "click"):
		SRView.SRView.__init__(self, pos, size, tag, container, color, id)
		self.action = action
		self.text = text
	
	def onMove(self, Notif):
		if not self.container is None:
			self.container.onClick(Notif)
	
	def display(self):
		gf = GfCenter()
		# display image
		gf.drawMeSquare(self.x, self.y, self.w, self.h, (self.color[0], self.color[1], self.color[2]))
		#print self.tag, self.x, self.y, self.w, self.h
		for v in self.subView:
			v.display()

	def onClick(self, Notif):
		print "clickButton"
		print self.action
		self.action()