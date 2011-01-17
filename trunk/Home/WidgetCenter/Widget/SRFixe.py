import SRView as SRView
import sys
sys.path[:0] = ['../../']
from GfCenter.GfCenter import *

class SRFixe(SRView.SRView):
		
	def onMove(self, Notif):
		pass
	
	def display(self):
		gf = GfCenter()
		# display image
		gf.drawMeSquare(self.x, self.y, self.w, self.h, self.color)
		for v in self.subView:
			v.display()
