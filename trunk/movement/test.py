#from moveGraph import *
from moveGraph import *

g = MoveGraph(1)

g.printGraph()
print
print g.getCurrentNode().getValue()
g.moveCurrentNode("down")
print g.getCurrentNode().getValue()
g.moveCurrentNode("up")
print g.getCurrentNode().getValue()
g.moveCurrentNode("down")
print g.getCurrentNode().getValue()
g.moveCurrentNode("down", "slide")
print g.getCurrentNode().getValue()
g.moveCurrentNode("up")
print g.getCurrentNode().getValue()