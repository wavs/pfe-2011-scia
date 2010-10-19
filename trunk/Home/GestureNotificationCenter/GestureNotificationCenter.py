from ListNotification.List import *
from Notification.Notification import *

## Class : MoveNotificationCenter<br/>
## This object handle notifications (receive and send it to the right widget)
##
class MoveNotificationCenter (object):

	instance = None      
	notifications = List()
	followers = []
	ticketId = 0;

	## Funtion new<br/>
	## Arguments : no<br/>
	## Note : Singleton<br/>
	## Return : the object itself
	##
	def __new__(self):
		if self.instance is None:
			self.instance = object.__new__(self)
		return self.instance

	## Funtion isAlive<br/>
	## Arguments : no<br/>
	## Return : "oui"
	##	
	def isAlive(self):
		return "Oui"
		
	## Funtion newNotifId<br/>
	## Arguments : no<br/>
	## Return : an Id for the next Notif
	##	
	def newNotifId(self):
		return self.ticketId + 1;

	# def getStr(self):
	# 	return self.str
	# 
	# def setStr(self, s):
	# 	self.str = s

	## Funtion sendNotification<br/>
	## Arguments : Notification Object<br/>
	## Return : no
	##	
	def sendNotification(self, notif):
		notif.setId(self.newNotifId())
		self.notifications.addElt(notif)
		self.ticketId += 1

	## Funtion handleNotification<br/>
	## Arguments : no<br/>
	## Return : return the first Notification of the list and delete it, return None object if the list is empty
	##
	def handleNotification(self):
		if (self.notifications.isEmpty() == False):
			notif = self.notifications.popElt()
			return notif
		else:
			return None