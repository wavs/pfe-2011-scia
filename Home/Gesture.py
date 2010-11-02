from Board import *
from GfCenter.GfCenter import *
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

w = SRView((0, 0), (100, 100), "View1", None, (24, 34, 50), 1)

view1 = SRView((300, 300), (100, 100), "View1", None, (24, 34, 50), 1)
view2 = SRView((310, 310), (100, 100), "View2", view1, (30, 30, 30), 1)
view1.addSubView(view2)

g_center = GestureCenter()
w_center = WidgetCenter()
center = MoveNotificationCenter()
w_center.subscribeNewWidget(w)
w_center.subscribeNewWidget(view1)
gf_center = GfCenter()

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
		if (not notif is None) and (not widget is None):
				widget.setNotif(notif)
			
b = os.fork()
if b == 0:
	os.system("python ../test/servertest.py")
else:
	thread_a = threading.Thread(None,start_GestureCenter, None, (g_center,center,))
	thread_b = threading.Thread(None,start_WidgetCenter, None, (w_center,center,))

	thread_a.start()
	thread_b.start()
	board = Board(800, 600, "Test")
	board.InitBoard()