#Evan Trout, Socket Programming TCP Client
#Submitted 09/25/18
from socket import *
serverPort = ''
serverName = ''
serverName = raw_input("Please enter a valid server address: ")
while (len(serverPort) < 4):
    serverPort = raw_input("Please enter a valid port of at least 4 digits: ")
serverPort = int(serverPort)
clientSocket = socket(AF_INET, SOCK_STREAM)
clientSocket.connect((serverName, serverPort))
while True:
    sentence = input('Input lowercase sentence:')
    clientSocket.send(sentence.encode())
    modifiedSentence = clientSocket.recv(1024)
    print('From server: ', modifiedSentence.decode())
clientSocket.close()
