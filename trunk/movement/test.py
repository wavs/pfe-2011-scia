#from moveGraph import *
from moveGraph import *
from moves import *
# g = MoveGraph(1)
# 
g = Moves(1, 10, 10)
g.addMove("down", 10, 10)
print g.getCurrentNode().getValue()
g.addMove("down", 12, 12)
print g.getCurrentNode().getValue()
g.addMove("down", 17, 18)
print g.getCoordonate()
print g.getCurrentNode().getValue()
g.addMove("up")
print g.getCurrentNode().getValue()

# g = MoveGraph(1)
# g.printGraph()
# print
# print g.getCurrentNode().getValue()
# g.moveCurrentNode("down")
# print g.getCurrentNode().getValue()
# g.moveCurrentNode("up")
# print g.getCurrentNode().getValue()
# g.moveCurrentNode("down")
# print g.getCurrentNode().getValue()
# g.moveCurrentNode("down", "slide")
# print g.getCurrentNode().getValue()
# g.moveCurrentNode("up")
# print g.getCurrentNode().getValue()