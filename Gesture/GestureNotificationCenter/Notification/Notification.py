class Notification:
	def __init__(self, label, x, y, x0, y0, id):
		self.idNotification = -1
		self.label = label
		self.x = x
		self.y = y
		self.x0 = x0
		self.y0 = y0
		self.id = id

	def getxy(self):
		return (self.x, self.y)
	
	def getx0y0(self):
		return (self.x0, self.y0)

	def setIdNotification(self, newid):
		self.idNotification = newid

	def setLabel(self, newlabel):
		self.label = newlabel

	def getLabel(self):
		return self.label

	def getAssociateGestureId(self):
		return self.id

	def setId(self, newid):
		self.idNotification = newid