from Gestures import *
from math import *
class GestureCenter:
	
	def __init__(self):
		self.gestureList =[] 

	def addGesture(self, id, x, y):
		self.gestureList.append(Gestures(1, id, x, y))

	def newCoordonateForGesture(self, n, label, x, y):
		self.gestureList[n].addMove(label, x, y)

	def getGestureGraph(self, n):
		if (n >= len(self.gestureList)):
			return None
		else:
			return self.gestureList[n]

	def distance(self, x1, y1, x2, y2):
		return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));

	#n entre 1 et nbmax
	def newCoordonate(self, n, label, x = -1, y = -1):
		if (len(self.gestureList) < n):
			n = len(self.gestureList) + 1
			self.addGesture(n - 1, x, y)
		self.newCoordonateForGesture(n - 1, label, x, y)