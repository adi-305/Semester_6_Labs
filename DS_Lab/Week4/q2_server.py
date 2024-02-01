import socket
HOST = "172.16.59.18"
PORT = 31621
s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
s.bind((HOST, PORT))
print("\nWaiting for incoming connections...\n")
name, client = s.recvfrom(1024)
name = name.decode()
print(name, "has connected to the chat room\nEnter [e] to exit chat room\n")
s.sendto(name.encode(), client)
while True:
    message, client = s.recvfrom(1024)
    message = message.decode()
    print(name, ":", message)
    message = input(str("Me : "))
    if message == "[e]":
        message = "Left chat room!"
        s.sendto(message.encode(), client)
        print("\n")
        break
    s.sendto(message.encode(), client)
