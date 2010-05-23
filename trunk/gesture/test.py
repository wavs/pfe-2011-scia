#from moveGraph import *
from moveGraph import *
from gestures import *
from MoveCenter.MoveNotificationCenter import *

# utilisation d'un Moves (surcouche aux MoveGraphe permettant l'interpretation des mouvements)
g = Gestures(1, 10, 10)
g.addMove("down", 10, 10)
print g.getCurrentNode().getValue()
g.addMove("down", 12, 12)
print g.getCurrentNode().getValue()
g.addMove("down", 17, 18)
print g.getCoordonate()
print g.getCurrentNode().getValue()
g.addMove("up")
print g.getCurrentNode().getValue()


# Singleton MoveNotificationCenter : utilisation

center = MoveNotificationCenter()
center.handleNotification()
center.handleNotification()
center.handleNotification()
center.handleNotification()
center.handleNotification()
center.handleNotification()

# Utilisation d'un moveGraph a vide
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