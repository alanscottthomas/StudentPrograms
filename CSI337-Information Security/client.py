#!/usr/bin/python

#CLIENT CODE THAT WILL CONNECT TO THE SERVER#

import socket

s = socket.socket()
host = "166.170.223.63"    #IP address that you want to connect to
port = 12345             #port that the server is using to wait for connections

s.connect((host, port))
print 'Connected to', host

while True:
    z = raw_input("Enter something for the server: ")
    s.send(z)
    # Halts
    print '[Waiting for response...]'
    print s.recv(1024)