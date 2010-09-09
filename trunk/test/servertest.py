import socket

HOST = "localhost"
PORT = 5554
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.bind((HOST, PORT))
s.listen(1)
conn, addr = s.accept()
print 'Cennected by', addr
#while 1:
data = conn.recv(1024)
#	if not data:break
#	print 'Received', repr(data)
#	conn.send(data)

conn.send('down:1:10:10')
data = conn.recv(1024)
print "received", repr(data)
conn.send('down:1:10:10')
data = conn.recv(1024)
print "received", repr(data)
conn.send('down:1:10:10')
data = conn.recv(1024)
print "received", repr(data)
conn.send('down:1:10:10')
data = conn.recv(1024)
print "received", repr(data)
conn.send('down:1:10:10')
data = conn.recv(1024)
print "received", repr(data)
conn.send('down:1:10:10')
data = conn.recv(1024)
print "received", repr(data)
conn.send('down:1:12:12')
data = conn.recv(1024)
print "received", repr(data)
conn.send('down:1:17:18')
data = conn.recv(1024)
print "received", repr(data)
conn.send('down:1:19:21')
data = conn.recv(1024)
print "received", repr(data)
conn.send('up:1')
data = conn.recv(1024)
print "received", repr(data)
conn.send("close")
data = conn.recv(1024)

conn.close()
