import SRView as SRView


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
	
	def __init__(self, pos, size, tag, container, color, id, text):
		SRView.SRView.__init__(pos, size, tag, container, color, id)
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