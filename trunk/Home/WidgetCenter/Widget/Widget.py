class Widget():
	def __init__(self, x, y, z, w, h, id):
		self.x = x
		self.y = y
		self.z = z
		self.w = w
		self.h = h
		self.alive = False
		self.id = id
		self.color = "white"
		self.defaultColor = self.color

	def defaultColor(self):
		self.color = self.getDefaultColor()

	def getColor(self):
		return self.color

	def getDefaultColor(self):
		return self.defaultColor

	def printWidget(self):
		print "x : ", self.x, " y : ", self.y, " color : ", self.color

	def getId(self):
		return self.id

	def setAlive (self, v):
		self.alice = v
	
	def getAlive (self):
		return self.alive
	
	def setxy(self, x, y):
		self.x = x
		self.y = y
	
	def getxy(self):
		return (self.x, self.y)

	def setz(self, z):
		self.z = z

	def getz(self):
		return self.z

	def setwh(self, w, h):
		self.w = w
		self.h = h

	def getwh(self):
		return (self.w, self.h)

	def clickInsideWidget(self, x, y):
		if ((x > self.x) and (x < self.x + self.w) and (y > self.y) and (y < self.y + self.h)):
			return (True, self.z)
		else:
			return (False, -1)
	
	def setNotif(self, notif):
		label = notif.getLabel()
		(x, y) = notif.getxy()
		(x0, y0) = notif.getx0y0()
		if (cmp(label, "press") == 0):
			self.color = "grey"
		else:
			if (cmp(label, "move") == 0):
				self.x = self.x + x - x0
				self.y = self.y + y - y0
			else:
				self.color = "white"
		self.printWidget()