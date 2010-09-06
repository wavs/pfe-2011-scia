import socket

HOST = 'localhost'
PORT = 5554
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.connect((HOST, PORT))
while 1:
	s.send('down:10:10');
	data = s.recv(1024)
	print "received", repr(data)
	s.send
s.close()
