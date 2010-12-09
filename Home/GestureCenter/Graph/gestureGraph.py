from graph import *

## Class : GestureGraph<br/>
## This is a graph specially design to represent Movement makable with N fingers
##
class GestureGraph :
	
	## Funtion init<br/>
	## Arguments :<br/>
	##			  - nb : number of finger<br/>
	## Note : currently there is only one finger GestureGraph available<br/>
	## Return : the object itself
	##	
	def __init__(self, nb):
		self.create_1_graph()

	## Funtion create_1_graph<br/>
	## Arguments :no<br/>
	## Return : a GestureGraph specially design to represent Movement makable with only one finger
	##
	def create_1_graph(self):
		self.g = Graph()
		self.g.addNode("Press")
		self.g.addNode("Click")
		self.g.addNode("Move")
		self.g.addNode("PressLong")
		self.g.addNode("ClickLong")
		self.g.addNode("trash")
		
		self.g.addEdge("Press", "Click", "up")
		self.g.addEdge("Click", "Press", "down")
		self.g.addEdge("Click", "trash", "up")
		self.g.addEdge("Press", "Press", "down")
		self.g.addEdge("Press", "Move", "down", "slide")
		self.g.addEdge("Move", "Move", "down")
		self.g.addEdge("Move", "trash", "up")
		self.g.addEdge("trash", "Press", "down")
		self.g.addEdge("Press", "PressLong", "down", "time")
		self.g.addEdge("PressLong", "PressLong", "down")
		self.g.addEdge("PressLong", "ClickLong", "up")
		self.g.addEdge("ClickLong", "Press", "down")
		
		self.g.initCurrentNode("Press")
		
		
	## Funtion getGraph<br/>
	## Arguments :no<br/>
	## Return : the graph
	##		
	def getGraph(self):
		return self.g

	## Funtion printGraph<br/>
	## Arguments :no<br/>
	## Note : print the graph on the standard output
	## Return : no <br/>
	##	
	def printGraph(self):
		self.g.printGraph()

	## Funtion getCurrentNode<br/>
	## Arguments :no<br/>
	## Return : the Node Object where the Movement is <br/>
	##	
	def getCurrentNode(self):
		return self.g.getCurrentNode();

	## Funtion MoveCurrentNode<br/>
	## Arguments :<br/>
	##			- label : the label the current Node must follow (down or up)<br/>
	##			- condition : extra label to go on specific Node<br/>
	## Return : the Node Object where the Movement is <br/>
	##	
	def moveCurrentNode(self, label, condition = ""):
		self.g.changeCurrentNode(label, condition)