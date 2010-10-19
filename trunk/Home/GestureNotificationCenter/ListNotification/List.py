## Class : List<br/>
## Represent a notification sent from the gesture center in attention to the widget
##
class List:
	
	## Funtion init<br/>
	## Arguments : no<br/>
	## Return : the object itself
	##
	def __init__(self):
		self.fifo = []

	## Funtion addElt<br/>
	## Arguments :<br/>
	##	- elt : add this element to the list
	## Return : no
	##
	def addElt(self, elt):
		self.fifo.append(elt)

	## Funtion popElt<br/>
	## Arguments : no<br/>
	## Return : the first of the list
	##
	def popElt(self):
		if (len(self.fifo) > 0):
			return self.fifo.pop(0)
			
			
	## Funtion isEmpty<br/>
	## Arguments : no<br/>
	## Return : True if the list is empty, false else
	##
	def isEmpty(self):
		return len(self.fifo) == 0


	## Funtion getElt<br/>
	## Arguments : no<br/>
	## Return : return the first element of a list without delete it
	##
	def getElt(self):
		if (len(self.fifo) > 0):
			return self.fifo[0]
		