import SRView as SRView
import sys
sys.path[:0] = ['../../']
from GfCenter.GfCenter import *

class SRMovable(SRView.SRView):

	def onClick(self, Notif):
		pass
		
	def onMove(self, Notif):
		(x, y) = Notif.getxy()
		(x0, y0) = Notif.getx0y0()
		dx = self.x
		dy = self.y
		self.x = x - self.w / 2
		self.y = y - self.h / 2
		for v in self.subView:
			v.move(self.x - dx, self.y - dy)
		#changer de container si on depasse les limites du siens
		#faire bipper le nouveau container
	
	def display(self):
		gf = GfCenter()
		# display image
		gf.drawMeSquare(self.x, self.y, self.w, self.h, self.color)
		for v in self.subView:
			v.display()
