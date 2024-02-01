import socket
serverAddressPort = ("127.0.0.1", 20001)
s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
host = socket.gethostname()
msg = "Hello, trying to establish a connection"
s.sendto(str.encode(msg),serverAddressPort)
tm = s.recvfrom(1024)
print(' Current time from Sever :', tm[0])
s.close()