#Evan Trout, Socket Programming TCP Server
#Submitted 09/25/18
from socket import *
serverPort = ''
while (len(serverPort) < 4):
    serverPort = raw_input("Please enter a valid port of at least 4 digits: ")
serverPort = int(serverPort)
serverSocket = socket(AF_INET, SOCK_STREAM)
serverSocket.bind(('', serverPort))
serverSocket.listen(1)
print('The server is ready to receive')
connectionSocket, addr = serverSocket.accept()
while True:
    sentence = connectionSocket.recv(1024).decode()
    print sentence
    capitalizedSentence = sentence.upper()
    connectionSocket.send(capitalizedSentence.encode())
connectionSocket.close()
