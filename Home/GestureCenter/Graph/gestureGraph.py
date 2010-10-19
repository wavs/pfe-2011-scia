from graph import *

## Class : GestureGraph<br/>
## This is a graph specially design to represent movement makable with N fingers
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
	## Return : a GestureGraph specially design to represent movement makable with only one finger
	##
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
	## Return : the Node Object where the movement is <br/>
	##	
	def getCurrentNode(self):
		return self.g.getCurrentNode();

	## Funtion moveCurrentNode<br/>
	## Arguments :<br/>
	##			- label : the label the current Node must follow (down or up)<br/>
	##			- condition : extra label to go on specific Node<br/>
	## Return : the Node Object where the movement is <br/>
	##	
	def moveCurrentNode(self, label, condition = ""):
		self.g.changeCurrentNode(label, condition)