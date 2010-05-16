from ListNotification.List import *

class MoveNotificationCenter (object):
	# Attribut statique de classe
	instance = None      
	notifications = List()
	followers = []

	def __new__(self):
		if self.instance is None:
			self.instance = object.__new__(self)
		return self.instance
	
	def getStr(self):
		return self.str
	
	def setStr(self, s):
		self.str = s
	
	def sendNotification(self, notif):
		self.notifications.addElt(notif)

	def handleNotification(self):
		if (self.notifications.isEmpty() == False):
			notif = self.notifications.popElt()
			print notif
		else:
			print "empty"