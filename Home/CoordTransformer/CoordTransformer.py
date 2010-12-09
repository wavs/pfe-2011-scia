## Class : CoordTransformer<br/>
## This object transform coordonate from opencv to coordonnate widgets can utilized
##
class CoordTransformer:
	
	wIn = 0
	hIn = 0
	wOut = 0
	hOut = 0
	
	def __new__(self):
		if self.instance is None:
			self.instance = object.__new__(self)
		return self.instance
	
	def setInfo(self, wIn, hIn, wOut, hOut):
		self.wIn = wIn
		self.hIn = hIn
		self.wOut = wOut
		self.hOut = hOut

	def mirrorCoord(self, x, y):
		return (self.wIn - x, y)
	
	def toScreen(self, x, y):
		return (self.wOut * x / self.wIn, self.hOut * y / self.hIn)
	
	def newCoord(self, x, y):
		(x, y) = self.mirrorCoord(x, y)
		(x, y) = self.toScreen(x, y)
		return (x, y)