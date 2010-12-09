from Graph.gestureGraph import * 
import sys
sys.path[:0] = ['../']
from GestureNotificationCenter.GestureNotificationCenter import *

## Class : Gesture<br/>
## This object contains the gestureGraph of one movement and the operations to operate it
##
class Gestures:
	
	## Funtion init<br/>
	## Arguments :<br/>
	##			  - nb : number of finger
	##		      - id : id will be use to identified the movement
	##			  - x : the initial position x of the movement
	##			  - y : the initial position y of the movement<br/>
	## Return : the object itself
	##
	def __init__(self, nb, id, x = 0, y = 0):
		self.id = id
		self.coordx = x
		self.coordy = y
		self.coordxo = -1
		self.coordyo = -1
		self.t = 0
		self.pixelMod = 1
		self.timeLimit = 25
		self.g = GestureGraph(nb)
		self.history = []
		self.moveLabel = ""
		self.moveCondition = ""
		self.nbUpMax = 5
		self.nbCurrentUp = 0

	## Funtion printGesture<br/>
	## Arguments :no<br/>
	## Note : display information about the movement on the standard output<br/>
	## Return : no
	##	
	def printGesture(self):
		print self.id, "<",self.coordx,",",self.coordy,">", "<",self.coordxo,",",self.coordyo,">", self.g.getCurrentNode().getValue()

	## Funtion getCoordonate<br/>
	## Arguments :no<br/>
	## Return : the current movement coordonates and the type
	##	
	def getCoordonate(self):
		return (self.coordx, self.coordy, self.coordxo, self.coordyo, self.t)

	def changeCurrentUp(self, label):
		if label == "up":
			self.nbCurrentUp += 1
		else:
			self.nbCurrentUp = 0

	## Funtion addMove<br/>
	## Arguments :<br/>
	##		- label : label of the next Edge to cross<br/>
	##		- x : value x of the move<br/>
	##		- y : value y of the move <br/>
	## Note : Add a movement is just move the current Node of the Gesture Graph to the next Node according to the label <br/>
	## Return : no
	##
	def addMove(self, label, x = -1, y = -1):
		#self.changeCurrentUp(label)
		#if (label != "up") or (self.nbCurrentUp == self.nbUpMax and label == "up"):
		self.moveLabel = label
		self.history.append((x, y))
		if len(self.history) >= 25:
			self.history.pop()
		self.isPress(x, y)
		self.t = self.t + 1
		self.isLongTime()
		self.isUp()
		self.g.moveCurrentNode(self.moveLabel, self.moveCondition)
		self.sendNotificationMove()
	
	
	## Funtion sendNotificationMove<br/>
	## Arguments :no<br/>
	## Note : get the instance of MoveNotificationCenter and create a new notification<br/>
	## Return : no
	##
	def sendNotificationMove(self):
		center = MoveNotificationCenter()
		if (self.g.getCurrentNode().getValue() != "trash"):
			center.sendNotification(Notification(self.g.getCurrentNode().getValue(), self.coordx, self.coordy, self.coordxo, self.coordyo, self.id))

	## Funtion getId<br/>
	## Arguments :no<br/>
	## Return : the id attribute value
	##
	def getId(self):
		return self.id


	## Funtion getCurrentNode<br/>
	## Arguments :no<br/>
	## Return : the current Node value
	##
	def getCurrentNode(self):
		return self.g.getCurrentNode()


	## Funtion getMoveLabel<br/>
	## Arguments :no<br/>
	## Return : the current moveLabel
	##
	def getMoveLabel(self):
		return self.moveLabel

	## Funtion isPress<br/>
	## Arguments :<br/>
	##	- x : the x position of a movement we have to study<br/>
	##	- y : the y position of a movement we have to study<br/>
	## Note : put the moveCondition to "slide" if the new movement allow a real deplacement
	## Return : no
	##
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
			
			
	## Funtion isUp<br/>
	## Arguments :no<br/>
	## Note : change the movecondition to "" if the moveLabel is "up"
	## Return : no
	##	
	def isUp(self):
		if self.moveLabel == "up":
			self.moveCondition = ""

	## Funtion isLongTime<br/>
	## Arguments :no<br/>
	## Note : change the movecondition to "time" if there is no real movement for 25 time clock
	## Return : no
	##
	def isLongTime(self):
		if (self.moveCondition == ""):
			if (self.t >= self.timeLimit):
				self.moveCondition = "time"
			else:
				self.moveCondition = ""
				
				
	## Funtion getLastPos<br/>
	## Arguments :no<br/>
	## Return : the last position of the current move
	##
	def getLastPos(self):
		if (len(self.history) > 1):
			return self.history[len(self.history) - 1]
		else:
			return (-1, -1)