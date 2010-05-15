from moveGraph import * 

class Moves:
	def __init__(self, nb, x = 0, y = 0):
		self.coordx = x
		self.coordy = y
		self.coordxo = -1
		self.coordyo = -1
		self.t = 0
		self.pixelMod = 5
		self.timeLimit = 25
		self.g = MoveGraph(nb)
		self.history = []
		self.moveLabel = ""
		self.moveCondition = ""
	
	def getCoordonate(self):
		return (self.coordx, self.coordy, self.coordxo, self.coordyo, self.t)

	def addMove(self,label, x = -1, y = -1):
		self.moveLabel = label
		self.history.append((x, y))
		if len(self.history) >= 25:
			self.history.pop()
		self.isPress(x, y)
		self.t = self.t + 1
		self.isLongTime()
		self.isUp()
		self.g.moveCurrentNode(self.moveLabel, self.moveCondition)

	def getCurrentNode(self):
		return self.g.getCurrentNode()

	def getMoveLabel(self):
		return self.moveLabel

	def isPress(self, x, y):
		if ((self.coordx <= x + self.pixelMod) and (self.coordx >= x - self.pixelMod) and
			(self.coordy <= y + self.pixelMod) and (self.coordy >= y - self.pixelMod)):
			self.moveCondition = ""
		else :
			self.moveCondition = "slide"
			self.coordxo = self.coordx
			self.coordyo = self.coordy
			self.coordx = x
			self.coordy = y
	
	def isUp(self):
		if self.moveLabel == "up":
			self.moveCondition = ""

	def isLongTime(self):
		if (self.moveCondition == ""):
			if (self.t >= self.timeLimit):
				self.moveCondition = "time"
			else:
				self.moveCondition = ""