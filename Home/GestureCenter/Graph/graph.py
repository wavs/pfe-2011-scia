from edge import *


## Class : Graph<br/>
## Graph Object, build Graph from Node and Edge
##
class Graph:
	
	
	## Funtion init<br/>
	## Arguments :<br/>
	##			  - name : the name of the graph<br/>
	## Return : the object itself
	##	
	def __init__(self, name = ""):
		self.listNode = []
		self.listEdge = []
		self.currentNode = Node("nodeZero")
		self.name = name


	## Funtion printGraph<br/>
	## Arguments :no<br/>
	## Note : go trought the graph and display it on the standard output
	## Return : no
	##	
	def printGraph(self):
		for node in self.listNode:
			print node.getValue()
		print
		for edge in self.listEdge:
			print "Edge between ", edge.getNodeStartValue(), " and ", edge.getNodeEndValue(), " with value", edge.getLabel(), edge.getCondition()

	## Funtion addNode<br/>
	## Arguments :<br/>
	##			  - v : value of the node<br/>
	## Return : True if the node is succefully added and false else
	##	
	def addNode(self, v):
		if (self.hasNode(v) == False):
			self.listNode.append(Node(v))
			return True
		return False
		
		
	## Funtion addEdge<br/>
	## Arguments :<br/>
	##			  - n1 : Node object, start of the edge<br/>
	##			  - n2 : Node object, end of the edge<br/>
	##			  - label : label value of the edge<br/>
	##			  - condition : condition value of the edge<br/>
	## Return : True if the edge is succefully added and false else
	##		
	def addEdge(self, n1, n2, label, condition = ""):
		if (self.hasEdge(n1, n2, label) == False):
			self.listEdge.append(Edge(n1, n2, label, condition))
			return True
		return False

	## Funtion initCurrentNode<br/>
	## Arguments :<br/>
	##			  - n : Node object, this node define the first node of the graph<br/>
	## Return : No
	##	
	def initCurrentNode(self, n):
		for node in self.listNode:
			if (node.getValue() == n):
				self.currentNode = node

	## Funtion getCurrentNode<br/>
	## Arguments :no<br/>
	## Return : Node Object, current node of the graph
	##	
	def getCurrentNode(self):
		return self.currentNode


	## Funtion hasCurrentNode<br/>
	## Arguments :no<br/>
	## Return : True if the current node is already setted, false else
	##	
	def hasCurrentNode(self):
		return self.currentNode.getValue() != "nodeZero"

	## Funtion hasNode<br/>
	## Arguments :<br/>
	##			 - n : Value in the node we're searching for<br/>
	## Return : True if n is in the graph, false else
	##
	def hasNode(self, n):
		for node in self.listNode:
			if (node.getValue() == n):
				return True
		return False
		
		
	## Funtion getNode<br/>
	## Arguments :<br/>
	##			 - n : Value in the node we're searching for<br/>
	## Return : the node associated to the value n
	##	
	def getNode(self, n):
		for node in self.listNode:
			if (node.getValue() == n):
				return node
		return self.currentNode


	## Funtion hasEdge<br/>
	## Arguments :<br/>
	##			 - n1 : Value in the start node<br/>
	##			 - n2 : Value in the end node<br/>
	## 			 - label : label of the edge we're searching for<br/>
	## Return : True if an edge has the paramaters, false else
	##
	def hasEdge(self, n1, n2, label):
		if (self.hasNode(n1) == True):
			if (self.hasNode(n2) == False):
				for edge in self.listEdge:
					if (edge.getNodeStartValue.getValue() == n1):
						if (edge.getNodeEndValue.getValue() == n2):
							if (edge.getLabel() == label):
								return True
		return False
	
	## Funtion changeCurrentNode<br/>
	## Arguments :<br/>
	##			 - label : label of the edge the current Node has to go throught<br/>
	##			 - condition : condition of the edge the current Node has to go throught<br/>
	## Return : True if the deplacement is a success, false else
	##
	def changeCurrentNode(self, label, condition):
		for edge in self.listEdge:
			if (edge.getNodeStartValue() == self.currentNode.getValue()):
				if (edge.getLabel() == label):
					if (edge.getCondition() == condition):
						self.currentNode = self.getNode(edge.getNodeEndValue())
						return True
		return False