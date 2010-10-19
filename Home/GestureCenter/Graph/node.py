## Class : Node<br/>
## Represent node inside Graph object
##
class Node:

	## Funtion init<br/>
	## Arguments <br/>
	##			  - v : value of the node<br/>
	## Return : the object itself
	##
	def __init__(self, v):
		self.value = v

	## Funtion init<br/>
	## Arguments :no<br/>
	## Return : the object itself<br/>
	##	
	def getValue(self):
		return self.value
		