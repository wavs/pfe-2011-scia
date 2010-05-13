from Graph.graph import *

class MoveGraph :
	
	def __init__(self, nb):
		self.create_1_graph()
		
	def create_1_graph(self):
		self.g = Graph()
		self.g.addNode("press")
		self.g.addNode("click")
		self.g.addNode("move")
		self.g.addNode("press_long")
		self.g.addNode("click_long")
		self.g.addNode("trash")
		
		self.g.addEdge("press", "click", "up")
		self.g.addEdge("click", "press", "down")
		self.g.addEdge("press", "press", "down")
		self.g.addEdge("press", "move", "down", "slide")
		self.g.addEdge("move", "move", "down")
		self.g.addEdge("move", "trash", "up")
		self.g.addEdge("trash", "press", "down")
		self.g.addEdge("press", "press_long", "down", "time")
		self.g.addEdge("press_long", "press_long", "down")
		self.g.addEdge("press_long", "click_long", "up")
		self.g.addEdge("click_long", "press", "down")
		
		self.g.initCurrentNode("press")
				
	def getGraph(self):
		return self.g
	
	def printGraph(self):
		self.g.printGraph()
	
	def getCurrentNode(self):
		return self.g.getCurrentNode();
	
	def moveCurrentNode(self, label, condition = ""):
		self.g.changeCurrentNode(label, condition)