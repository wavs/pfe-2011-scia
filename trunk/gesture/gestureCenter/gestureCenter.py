from gestures import *

class GestureCenter:
	
	def __init__(self):
		gestureList =[] 

	def addGesture(self, x, y):
		gestureList.append(gesture(1, x, y))

	def newCoordonateForGesture(self, n, label, x, y):
		if (n < len(self.gestureList)):
			self.gestureList[n].addMove(label, x, y)

	def getGestureGraph(self, n):
		if (n >= len(self.gestureList)):
			return None
		else:
			return self.gestureList[n]

	def distance(self, x1, y1, x2, y2):
		return sqrt(pow(x2 - x1) + pow(y2 - y1));

	def newCoordonate(self, label, x = -1, y = -1):
		n = 0;
		dist = self.distance(x, y, self.gestureList[n].getLastPos())
		if label == "down":
			self.addGesture(x, y)
		else:
			for i in xrange(len(self.gestureList)):
				subDist = self.distance(x, y, self.gestureList[i].getLastPos)
				if (subDist < dist):
					dist = subDist
					n = i
			self.newCoordonateForGesture(n, label, x, y)