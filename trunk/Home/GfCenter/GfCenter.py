import sys
sys.path[:0] = ['../']
import Board as b

class GfCenter (object):

	instance = None      
	
	def __new__(self):
		if self.instance is None:
			self.instance = object.__new__(self)
		return self.instance

	def drawMeSquare(self, x, y, w, h, color):
		b.drawBox(x, y, w, h, color, False)