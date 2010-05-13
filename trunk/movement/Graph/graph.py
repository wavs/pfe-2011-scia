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
			print "Edge between ", edge.getNodeStart(), " and ", edge.getNodeEnd(), " with value", edge.getLabel()
	
	def addNode(self, v):
		if (self.hasNode(v) == False):
			self.listNode.append(Node(v))
			return True
		return False
		
	def addEdge(self, n1, n2, label):
		if (self.hasEdge(n1, n2, label) == False):
			self.listEdge.append(Edge(n1, n2, label))
			return True
		return False
	
	def initCurrentNode(self, n):
		for node in self.listNode:
			if (node.getValue() == n):
				self.currentNode = node
	
	def hasCurrentNode(self):
		return self.currentNode.getValue() != "nodeZero"

	def hasNode(self, n):
		for node in self.listNode:
			if (node.getValue() == n):
				return True
		return False

	def hasEdge(self, n1, n2, label):
		if (self.hasNode(n1) == True):
			if (self.hasNode(n2) == False):
				for edge in self.listEdge:
					if (edge.getNodeStart.getValue() == n1):
						if (edge.getNodeEnd.getValue() == n2):
							if (edge.getLabel() == label):
								return True
		return False
				