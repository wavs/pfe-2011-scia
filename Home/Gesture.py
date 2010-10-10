from Board import *
from GestureCenter.GestureCenter import *
from GestureNotificationCenter.GestureNotificationCenter import *
from WidgetCenter.WidgetCenter import *
import time
import threading
import socket
import time
from os import *

HOST = 'localhost'
PORT = 5551

i = 0;

w = Widget(0, 0, 0, 100, 100, 1)

g_center = GestureCenter()
w_center = WidgetCenter()
center = MoveNotificationCenter()
w_center.subscribeNewWidget(w)
		

def start_GestureCenter(g_center, center):
	time.sleep(2)
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
			if len(l) == 4:
				g_center.addNewInformation(l)
		g_center.printGestures()
		s.send('OK')
	s.close()
	
		

def start_WidgetCenter(w_center, center):
	time.sleep(2)
	while (True):
		notif = center.handleNotification()
		widget = w_center.examinNotif(notif)
		if not notif is None:
			#print notif.getAssociateGestureId(), notif.getLabel()
			if not widget is None:
				widget.setNotif(notif)
			
b = os.fork()
if b == 0:
	os.system("python /Users/Alex/Documents/Programation/pfe/pfe-2011-scia/test/servertest.py")
else:
	thread_a = threading.Thread(None,start_GestureCenter, None, (g_center,center,))
	thread_b = threading.Thread(None,start_WidgetCenter, None, (w_center,center,))

	thread_a.start()
	thread_b.start()
	board = Board(800, 600, "Test")
	board.InitBoard()