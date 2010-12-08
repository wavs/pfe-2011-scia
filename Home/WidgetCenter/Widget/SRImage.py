import SRView as SRView


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
	
	def __init__(self, pos, size, tag, container, color, id, link):
		SRView.SRView.__init__(self, pos, size, tag, container, color, id)
		self.link = link
	
	def onMove(self, Notif):
		if not self.container is None:
			self.container.onClick(Notif)
	
	def display(self):
		gf = GfCenter()
		# display image
		#gf.drawMeSquare(self.x, self.y, self.w, self.h, self.color)
		for v in self.subView:
			v.display()
	
	def printInformation(self, n = 0):
		print "Widget [", self, "] id ",self.id, " floor ", n, " Node ", self.tag
		print "		Position[", self.x, ",", self.y, "] - Size[", self.w, ",", self.h, "]"
		print "		Tag[", self.tag, "] - Color[", self.color, "] - Image[", self.link, "]"
		print "		Container[", self.container, "]"
		for v in self.subView:
			v.printInformation(n + 1)