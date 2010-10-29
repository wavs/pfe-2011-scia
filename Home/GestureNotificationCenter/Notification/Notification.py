## Class : Notification<br/>
## Represent a notification sent from the gesture center in attention to the widget
##
class Notification:
	
	## Funtion init<br/>
	## Arguments :<br/>
	##	- label : label associate with the notification
	##	- x : value x of the notification
	##	- y : value y of the notification
	##	- x0 : x of the last position
	##	- y0 : y of the last position
	##	- id : id of the notification <br/>
	## Return : the object itself
	##
	def __init__(self, label, x, y, x0, y0, id):
		self.idNotification = -1
		self.label = label
		self.x = x
		self.y = y
		self.x0 = x0
		self.y0 = y0
		self.id = id
		
		
	## Funtion getxy<br/>
	## Arguments :no<br/>
	## Return : value x and value y
	##
	def getxy(self):
		return (self.x, self.y)

	## Funtion getx0y0<br/>
	## Arguments :no<br/>
	## Return : value x0 and value y0
	##
	def getx0y0(self):
		return (self.x0, self.y0)

	## Funtion setIdNotification<br/>
	## Arguments :<br/>
	##	- newid : value of the new id
	## Return : no
	##
	def setIdNotification(self, newid):
		self.idNotification = newid

	## Funtion setLabel<br/>
	## Arguments :<br/>
	##	- newlabel : value of the new label
	## Return : no
	##
	def setLabel(self, newlabel):
		self.label = newlabel

	## Funtion getLabel<br/>
	## Arguments : no<br/>
	## Return : the label value
	##
	def getLabel(self):
		return self.label

	## Funtion getAssociateGestureId<br/>
	## Arguments : no<br/>
	## Return : the id of the gesture associate with
	##
	def getAssociateGestureId(self):
		return self.id

	## Funtion setId<br/>
	## Arguments :<br/>
	##	- newid : value of the id<br/>
	## Return : no
	##
	def setId(self, newid):
		self.idNotification = newid
		
	def printInformation(self):
		print "Notif :", self.id
		print "   x : ", self.x
		print "   y : ", self.y
		print "   x0 : ", self.x0
		print "   y0 : ", self.y0
		print "   label : ", self.label