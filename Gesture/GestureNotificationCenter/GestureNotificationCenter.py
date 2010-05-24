from ListNotification.List import *
from Notification.Notification import *

class MoveNotificationCenter (object):
	# Attribut statique de classe
	instance = None      
	notifications = List()
	followers = []
	ticketId = 0;

	def __new__(self):
		if self.instance is None:
			self.instance = object.__new__(self)
		return self.instance
	
	def newNotifId(self):
		return self.ticketId + 1;
		
	def getStr(self):
		return self.str
	
	def setStr(self, s):
		self.str = s
	
	def sendNotification(self, notif):
		notif.setId(self.newNotifId())
		self.notifications.addElt(notif)
		self.ticketId += 1

	def handleNotification(self):
		if (self.notifications.isEmpty() == False):
			notif = self.notifications.popElt()
			print notif.getLabel()
		else:
			print "empty"