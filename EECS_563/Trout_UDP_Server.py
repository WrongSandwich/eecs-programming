from socket import *
serverPort = ''
while (len(serverPort) < 4):
    serverPort = raw_input("Please enter a valid port of at least 4 digits: ")
serverPort = int(serverPort)
print serverPort
serverSocket = socket(AF_INET, SOCK_DGRAM)
serverSocket.bind(('', serverPort))
print("The server is ready to receive")
while True:
    message, clientAddress = serverSocket.recvfrom(2048)
    print message
    modifiedMessage = message.decode().upper()
    serverSocket.sendto(modifiedMessage.encode(), clientAddress)
