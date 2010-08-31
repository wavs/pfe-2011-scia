from GestureCenter.GestureCenter import *
from GestureNotificationCenter.GestureNotificationCenter import *
from WidgetCenter.WidgetCenter import *
import time
import threading

i = 0;

g_center = GestureCenter()
w_center = WidgetCenter()
center = MoveNotificationCenter()


def start_GestureCenter(g_center, center):
	while (True):
		print ""
		

def start_WidgetCenter(w_center, center):
	while (True):
		notif = center.handleNotification()
		w_center.examinNotif(notif)
		if notif is None:
			print "No notification"
		else :
			print notif.getAssociateGestureId(), notif.getLabel()

thread_a = threading.Thread(None,start_GestureCenter, None, (g_center,center,))
thread_b = threading.Thread(None,start_WidgetCenter, None, (w_center,center,))
thread_a.start()
thread_b.start()