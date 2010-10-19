import time
import threading
import socket
import time
from os import *

HOST = 'localhost'
PORT = 5551

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.connect((HOST, PORT))
s.send("CONNEXION")
flag = 1
s.send('connection\n');

while 1:
	data = s.recv(1024)
	print data
	l = data.split(":")
	if (l[0] == "close"):
		flag = 0
	s.send("ok")
s.close()

