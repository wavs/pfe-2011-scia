from edge import *



class Graph:
	
	def __init__(self, name = ""):
		self.listNode = []
		self.listEdge = []
		self.currentNode = Node("nodeZero")
		self.name = name
	
	def printGraph(self):
		for node in self.listNode:
			print node.getValue()
		print
		for edge in self.listEdge:
			print "Edge between ", edge.getNodeStartValue(), " and ", edge.getNodeEndValue(), " with value", edge.getLabel(), edge.getCondition()
	
	def addNode(self, v):
		if (self.hasNode(v) == False):
			self.listNode.append(Node(v))
			return True
		return False
		
	def addEdge(self, n1, n2, label, condition = ""):
		if (self.hasEdge(n1, n2, label) == False):
			self.listEdge.append(Edge(n1, n2, label, condition))
			return True
		return False
	
	def initCurrentNode(self, n):
		for node in self.listNode:
			if (node.getValue() == n):
				self.currentNode = node
	
	def getCurrentNode(self):
		return self.currentNode
	
	def hasCurrentNode(self):
		return self.currentNode.getValue() != "nodeZero"

	def hasNode(self, n):
		for node in self.listNode:
			if (node.getValue() == n):
				return True
		return False
	
	def getNode(self, n):
		for node in self.listNode:
			if (node.getValue() == n):
				return node
		return self.currentNode

	def hasEdge(self, n1, n2, label):
		if (self.hasNode(n1) == True):
			if (self.hasNode(n2) == False):
				for edge in self.listEdge:
					if (edge.getNodeStartValue.getValue() == n1):
						if (edge.getNodeEndValue.getValue() == n2):
							if (edge.getLabel() == label):
								return True
		return False
	
	#change the current node by the next one according to label and condition
	#this work only if the graph is determinist
	def changeCurrentNode(self, label, condition):
		for edge in self.listEdge:
			if (edge.getNodeStartValue() == self.currentNode.getValue()):
				if (edge.getLabel() == label):
					if (edge.getCondition() == condition):
						self.currentNode = self.getNode(edge.getNodeEndValue())
						return True
		return False