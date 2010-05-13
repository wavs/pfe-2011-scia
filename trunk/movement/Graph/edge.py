from node import *

class Edge:
	def __init__(self, n1, n2, label, condition = ""):
		self.nodeStart = n1
		self.nodeEnd = n2
		self.label = label
		self.condition = condition
	
	def getLabel(self):
		return self.label
	
	def getNodeStartValue(self):
		return self.nodeStart
	
	def getNodeEndValue(self):
		return self.nodeEnd

	def getCondition(self):
		return self.condition