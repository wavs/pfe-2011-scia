from node import *

class Edge:
	def __init__(self, n1, n2, label):
		self.nodeStart = n1
		self.nodeEnd = n2
		self.label = label
	
	def getLabel(self):
		return self.label
	
	def getNodeStart(self):
		return self.nodeStart
	
	def getNodeEnd(self):
		return self.nodeEnd