class Notification:
	def __init__(self, label, x, y, x0, y0):
		self.idNotification = -1
		self.label = label
		self.x = x
		self.y = y
		self.x0 = x0
		self.y0 = y0

	def setIdNotification(self, newid):
		self.idNotification = newid

	def setLabel(self, newlabel):
		self.label = newlabel

	def getLabel(self):
		return self.label

	def setId(self, newid):
		self.idNotification = newid