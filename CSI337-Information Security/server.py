#!/usr/bin/python

#SERVER CODE THAT WILL LISTEN FOR INCOMING CONNECTIONS#

import socket

s = socket.socket()
host = "192.168.154.1"    #IP address that this script is being ran on
port = 12345             #Port that you want to listen on for incoming connections
s.bind((host, port))

s.listen(1)              #Number of clients we'll allow to this server, I think we need to use threads to have more than one conversation
c = None


while True:              #while loop to wait for a client to connect
   if c is None:
       # Halts
       print '[Waiting for connection...]'
       c, addr = s.accept()
       print 'Got connection from', addr


   else:                  #a client has connected and we are chatting
       print '[Waiting for response...]'
       print c.recv(1024)
       q = raw_input("Enter something to this client: ")
       c.send(q)