from Gestures import *
from math import *


## Class : GestureCenter<br/>
## This object managed a set of Gestures
##
class GestureCenter:
	
	## Funtion init<br/>
	## Arguments :no<br/>
	## Return : the object itself
	##
	def __init__(self):
		self.gestureList =[] 

	## Funtion init<br/>
	## Arguments :no<br/>
	## Note : display the different Gestures on the standard output<br/>
	## Return : no
	##
	def printGestures(self):
		print "NB : ", len(self.gestureList)
		for g in self.gestureList:
			print "GRAPH ", g.getId(), g.printGesture()

	## Funtion addGesture<br/>
	## Arguments :<br/>
	##	- id : id of the gesture
	##	- x : x position of the new movement
	##	- y : y position of the movement<br/>
	## Return : no
	##	
	def addGesture(self, id, x, y):
		self.gestureList.append(Gestures(1, id, x, y))

	## Funtion addNewInformation<br/>
	## Arguments :<br/>
	##	- l : list of element (id, x, y, down/up)<br/>
	## Note : add the new coordonate to the right gestures
	## Return : no
	##
	def addNewInformation(self, l):
		i = int(l[1])
		typ = l[0]
		x = -1.
		y = -1.
		if (len(l) > 2):
		 	x = int(l[2])
		 	y = int(l[3])
		d = 0.
		maxd = -1.
		if len(self.gestureList) == 0:
			self.newCoordonate(i, typ, x, y)
		else:
			for g in self.gestureList:
				(sx, sy, sx0, sy0, t) = g.getCoordonate()
				g.printGesture()
				d = self.distance(x, y, sx, sy)
				if d <= maxd or maxd == -1:
					maxd = d
					i = g.getId()
			self.newCoordonate(i, typ, x, y)
		
	## Funtion newCoordonateForGesture<br/>
	## Arguments :<br/>
	##	- n : id of the gesture
	##  - label : label of the next edge cross 
	##	- x : x position of the new movement
	##	- y : y position of the movement<br/>
	## Return : no
	##
	def newCoordonateForGesture(self, n, label, x, y):
		self.gestureList[n].addMove(label, x, y)

	## Funtion getGestureGraph<br/>
	## Arguments :<br/>
	##	- n : id of the gesture<br/>
	## Return : the gesture graph of the n-th gesture
	##
	def getGestureGraph(self, n):
		if (n >= len(self.gestureList)):
			return None
		else:
			return self.gestureList[n]

	## Funtion distance<br/>
	## Arguments :<br/>
	##	- x1 : position x of the first point
	##	- y1 : position y of the first point
	##	- x2 : position x of the second point
	##	- y2 : position y of the second point<br/>
	## Return : the euclidian distance between the first and the second points
	##
	def distance(self, x1, y1, x2, y2):
		return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));

	## FuntionnewCoordonate<br/>
	## Arguments :<br/>
	##	- n : gesture id
	##	- label :label of the next edge
	##	- x : position x 
	##	- y : position y <br/>
	## Note : add coordonate to gesture or create one if the id is greater than the current number of gesture
	## Return : no
	##
	def newCoordonate(self, n, label, x = -1, y = -1):
		if (len(self.gestureList) < n):
			n = len(self.gestureList) + 1
			self.addGesture(n - 1, x, y)
		self.newCoordonateForGesture(n - 1, label, x, y)