import socket

HOST = 'localhost'
PORT = 5542
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.connect((HOST, PORT))
s.send('connection\n');

while 1:
	data = s.recv(1024)
	print "received", repr(data)
	s.send("ok\n")
s.close()
