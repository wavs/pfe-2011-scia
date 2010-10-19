from node import *

## Class : Edge<br/>
## represent edge inside Graph object
##
class Edge:

	## Funtion init<br/>
	## Arguments :<br/>
	##			  - n1 : node start<br/>
	##			  - n2 : node end<br/>
	## 			  - label : value of the edge<br/>
	## 			  - condition : second value for the edge<br/>
	## Return : the object itself
	##
	def __init__(self, n1, n2, label, condition = ""):
		self.nodeStart = n1
		self.nodeEnd = n2
		self.label = label
		self.condition = condition
	
	
	## Function getLabel<br/>
	## Arguments : no<br/>
	## Return : value of label attribute<br/>
	##
	def getLabel(self):
		return self.label
	
	## Function getNodeStartValue<br/>
	## Arguments : no<br/>
	## Return : node start object	<br/>
	##
	def getNodeStartValue(self):
		return self.nodeStart


	## Function getNodeEndValue<br/>
	## Arguments : no<br/>
	## Return : node end object<br/>	
	##	
	def getNodeEndValue(self):
		return self.nodeEnd
	
	## Function getCondition<br/>
	## Arguments : no<br/>
	## Return : value of condition attribute<br/>	
	##
	def getCondition(self):
		return self.condition