import socket
HOST = '172.16.59.18'
PORT = 31621
s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
name = input(str("\nEnter your name: "))
s.sendto(name.encode(), (HOST, PORT))
print("\nTrying to connect to ", HOST, "(", PORT, ")\n")
s_name, server = s.recvfrom(1024)
s_name = s_name.decode()
print(s_name, "has joined the chat room\nEnter [e] to exit chat room\n")
while True:
    message = input(str("Me : "))
    if message == "[e]":
        message = "Left chat room!"
        s.sendto(message.encode(), (HOST, PORT))
        print("\n")
        break
    s.sendto(message.encode(), (HOST, PORT))
    message, server = s.recvfrom(1024)
    message = message.decode()
    print(s_name, ":", message)
