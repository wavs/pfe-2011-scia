from Board import *
from GfCenter.GfCenter import *
from GestureCenter.GestureCenter import *
from GestureNotificationCenter.GestureNotificationCenter import *
from WidgetCenter.WidgetCenter import *
from CoordTransformer.CoordTransformer import *
import time
import threading
import socket
import time
import os
import sys

HOST = 'localhost'
PORT = 5546
#PORT = 5545
CAM_MOD = True
i = 0;

w = SRView((400, 300), (150, 150), "View1", None, (0.2, 0.2, 0.2), 1)

view1 = SRView((300, 300), (100, 100), "View1", None, (24, 34, 50), 1)
view2 = SRView((310, 310), (100, 100), "View2", view1, (30, 30, 30), 1)
view1.addSubView(view2)

g_center = GestureCenter()
w_center = WidgetCenter()
center = MoveNotificationCenter()
w_center.subscribeNewWidget(w)
#w_center.subscribeNewWidget(view1)
gf_center = GfCenter()
coord_center = CoordTransformer()
coord_center.setInfo(640, 480, 900, 550)


def connectToInputStream(filename = ""):
	if (filename != ""):
		try:
			f = open(filename, "r")
			return f
		except Exception as inst:
			print type(inst)
			print inst
			return connectToInputStream("")
	else:
		try:
			s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
			s.connect((HOST, PORT))
			s.send("CONNEXION")
			return s
		except Exception as inst:
			print type(inst)
			print inst 
			return -1
		
def getNextInput(d, filename = ""):
	if (filename ==""):
		return d.recv(1024)
	else:
		return d.read()
		
def endInputTurn(d, filename = ""):
	if (filename == ""):
		d.send("OK")

def start_GestureCenter(g_center, center, filename):
	time.sleep(2)
	logfile = open("entre.log", "w")
	inputDescriptor = connectToInputStream(filename)
	flag = 1
	while flag == 1 and inputDescriptor != -1:
		data = getNextInput(inputDescriptor, filename)
		logfile.write(data)
		logfile.write("\n")
		l = data.split(":")
		print l
		if (l[0] == "close") or (data == ""):
			flag = 0
		else:
			if len(l) == 4:
				g_center.addNewInformation(l, CAM_MOD)
	#	g_center.printGestures()
		g_center.destroyGesture()
		#w_center.returnToNormal()
		endInputTurn(inputDescriptor, filename)
	if inputDescriptor != -1:
		inputDescriptor.close()
	logfile.close()


def start_WidgetCenter(w_center, center):
	time.sleep(2)
	while (True):
		notif = center.handleNotification()
		widget = w_center.examinNotif(notif)
		if (not notif is None) and (not widget is None):
				widget.setNotif(notif)
			
b = os.fork()
filename = ""
if (len(sys.argv) > 1):
	if os.path.isfile(sys.argv[1]):
		print sys.argv[1]
		filename = sys.argv[1]

print "FILENAME : ", filename

if b == 0:
	if (CAM_MOD == False):
		if (filename == ""):
			os.system("python ../test/servertest.py")
		else:
			os.system("echo end")
	else:
		os.system("echo end")		
else:
	thread_a = threading.Thread(None,start_GestureCenter, None, (g_center,center,filename,))
	thread_b = threading.Thread(None,start_WidgetCenter, None, (w_center,center,))

	thread_a.start()
	thread_b.start()
	board = Board(800, 600, "Test")
	board.InitBoard()