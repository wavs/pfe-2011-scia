## Class : Widget<br/>
## Abstract class for widgets
##
class Widget():
	
	## Funtion init<br/>
	## Arguments <br/>
	##	- x : x position of the bottom left corner
	##	- y : y position of the bottom left corner
	##	- z : z-index of the widget
	##	- w : weigth
	##	- h : heigth
	##	- id : id of the widget<br/>
	## Return : the object itself
	##
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

	## Funtion defaultColor<br/>
	## Arguments : no<br/>
	## Note : set the color to the default color<br/>
	## Return : no
	##
	def defaultColor(self):
		self.color = self.getDefaultColor()
		
		
	## Funtion getColor<br/>
	## Arguments : no<br/>
	## Return : color value attribute
	##
	def getColor(self):
		return self.color

	## Funtion getDefaultColor<br/>
	## Arguments : no<br/>
	## Return : default color value attribute
	##
	def getDefaultColor(self):
		return self.defaultColor

	## Funtion printWidget<br/>
	## Arguments : no<br/>
	## Note : display information about the widget on the standard output<br/>
	## Return : no
	##
	def printWidget(self):
		print "x : ", self.x, " y : ", self.y, " color : ", self.color

	## Funtion getId<br/>
	## Arguments : no<br/>
	## Return : id value attribute
	##
	def getId(self):
		return self.id

	## Funtion setId<br/>
	## Arguments :<br/>
	##	- v = true or false to say if the widget is alive or not<br/>
	## Return : no
	##
	def setAlive (self, v):
		self.alive = v

	## Funtion getId<br/>
	## Arguments : no<br/>
	## Return : alive value attribute
	##	
	def getAlive (self):
		return self.alive

	## Funtion setxy<br/>
	## Arguments :<br/>
	##	- x : x value
	##	- y : y value<br/>
	## Return : no
	##	
	def setxy(self, x, y):
		self.x = x
		self.y = y

	## Funtion getxy<br/>
	## Arguments : no<br/>
	## Return : (x, y) value attribute
	##	
	def getxy(self):
		return (self.x, self.y)

	## Funtion setz<br/>
	## Arguments :<br/>
	##	- z : z-index value<br/>
	## Return : no
	##
	def setz(self, z):
		self.z = z

	## Funtion getz<br/>
	## Arguments : no<br/>
	## Return : z-index value attribute
	##
	def getz(self):
		return self.z

	## Funtion setwh<br/>
	## Arguments :<br/>
	##	- w : weigth value<br/>
	##	- h : heigth value<br/>
	## Return : no
	##
	def setwh(self, w, h):
		self.w = w
		self.h = h


	## Funtion getwh<br/>
	## Arguments : no<br/>
	## Return : (weigth, heigth) value attribute
	##
	def getwh(self):
		return (self.w, self.h)


	## Funtion clickInsideWidget<br/>
	## Arguments :<br/>
	##	- x : x finger position<br/>
	##	- y : y finger position <br/>
	## Return : true if <x, y> is inside the widget, false else
	##
	def clickInsideWidget(self, x, y):
		if ((x > self.x) and (x < self.x + self.w) and (y > self.y) and (y < self.y + self.h)):
			return (True, self.z)
		else:
			return (False, -1)

	## Funtion setNotif<br/>
	## Arguments :<br/>
	##	- notif : Notif object<br/>
	## Note : take a notif and do things with it ;) <br/>
	## Return : no
	##	
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