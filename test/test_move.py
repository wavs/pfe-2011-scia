#placer le fichier à la racine du dossier Home pour qu'il fonctionne

from GestureCenter.GestureCenter import *
from GestureNotificationCenter.GestureNotificationCenter import *

# utilisation d'un Moves (surcouche aux MoveGraphe permettant l'interpretation des mouvements)
g = GestureCenter()
g.newCoordonate(1, "down", 10, 10)
g.newCoordonate(2, "down", 10, 10)
g.newCoordonate(3, "down", 10, 10)
g.newCoordonate(3, "down", 20, 10)

#print g.getCurrentNode().getValue()
g.newCoordonate(1, "down", 12, 12)
#print g.getCurrentNode().getValue()
g.newCoordonate(1, "down", 17, 18)
g.newCoordonate(1, "down", 19, 21)
#print g.getCoordonate()
#print g.getCurrentNode().getValue()
g.newCoordonate(1, "up")
#print g.getCurrentNode().getValue()


# Singleton MoveNotificationCenter : utilisation

center = MoveNotificationCenter()
center.handleNotification()
center.handleNotification()
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