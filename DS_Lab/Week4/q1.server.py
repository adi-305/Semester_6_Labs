import socket
import time
serversocket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
host = "127.0.0.1"
port = 20001
serversocket.bind((host, port))
while True:
	bytesAddressPair = serversocket.recvfrom(1024)
	message = bytesAddressPair[0]
	address = bytesAddressPair[1]
	print("Got a connection from %s" % str(address))
	currentTime = time.ctime(time.time()) + "\r\n"
	serversocket.sendto(currentTime.encode('ascii'),address)