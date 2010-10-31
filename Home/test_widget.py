from WidgetCenter.WidgetCenter import *
from GestureNotificationCenter.GestureNotificationCenter import *
from GestureCenter.GestureCenter import *
from GestureNotificationCenter.GestureNotificationCenter import *

view1 = SRView((0, 0), (100, 100), "View1", None, (24, 34, 50), 1)
view2 = SRView((10, 10), (50, 50), "View2", view1, (30, 30, 30), 1)
view1.addSubView(view2)

w_center = WidgetCenter()
w_center.subscribeNewWidget(view1)


g = GestureCenter()
center = MoveNotificationCenter()
g.newCoordonate(1, "down", 5, 200)

notif = center.handleNotification()
widget = w_center.examinNotif(notif)

w_center.printWidgetList()
notif.printInformation()
widget.setNotif(notif)