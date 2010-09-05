from GestureCenter.GestureCenter import *
from GestureNotificationCenter.GestureNotificationCenter import *
from WidgetCenter.WidgetCenter import *
import time
import threading
import socket

HOST = 'localhost'
PORT = 5554


i = 0;

g_center = GestureCenter()
w_center = WidgetCenter()
center = MoveNotificationCenter()


def start_GestureCenter(g_center, center):
	s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
	s.connect((HOST, PORT))
	s.send("CONNEXION")
	flag = 1
	while flag == 1:
		data = s.recv(1024)
		l = data.split(":")
		if (l[0] == "close"):
			flag = 0
		else:
			g_center.addNewInformation(l)
		s.send('OK')
	s.close()
	
		

def start_WidgetCenter(w_center, center):
	while (True):
		notif = center.handleNotification()
		w_center.examinNotif(notif)
		if not notif is None:
			print notif.getAssociateGestureId(), notif.getLabel()

thread_a = threading.Thread(None,start_GestureCenter, None, (g_center,center,))
thread_b = threading.Thread(None,start_WidgetCenter, None, (w_center,center,))
thread_a.start()
thread_b.start()