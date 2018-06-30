#Program: Port scanner
#Class: CSI337 - Information Security
#Student: Alan Thomas
#Instructor: Dr. Dutta
#Date: 3/2/2018
#Notes: I began writing this program with little to no experience in Python.
#Fortunately, I was able to find a tutorial that was able to guide me along
#with creating a framework that I morphed into a simple port scanner.
#Overall, I'm glad that you suggested I use Python. It's an incredibly flexible
#language, which isn't the case with some other languages. The only aspect
#that I wasn't able to accomplish was creating 'clickable' URLs when outputting
#the port information. I'm sure there's a way, but I wasn't able to come
#to a solution. After writing the program I think I favour Python over C++.



#---libs to import---
import sys
import socket
import subprocess
#--- end lib import ---

#--- printing title ---
print "_" *60
print "CSI337 Port Scanner"
print "Created by Alan Thomas"
print "For Dr. Dutta Spring 2018"
print "_" *60
print "\n"
#--- end print title ----


#---get the target ip/hostname from the user---
target    = raw_input("Enter a remote host to scan: ")
targetIP  = socket.gethostbyname(target)          #getting the IP of the server
#--- end get user input ---

#--- print a notifcation for the user letting them know that the scan has begun ---
print "Target set to: ", targetIP, "(",target,")"
#--- end scan notification ---



# Using the range function to specify ports (here it will scans all ports between 1 and 1024)
low_port1    = raw_input("Enter the beginning port to scan: ")
high_port1    = raw_input("Enter the port ending port to scan to: ")
#--- end get ports ---

#--- printing the user's selection of ports to scan ---
print "\nScanning ports from: ", low_port1," to ", high_port1
print "_" *60
#--- end print ports ---

#--- set raw_input values to ints and storing them in new variables ---
low_port=int(low_port1)
high_port=int(high_port1)
high_port+=1;                #I had to increment by one in order for the user to scan a single port.
#--- end conversion to int ---

port_array=[]       #array that we'll store ports we were able to connect to
port_counter=0;     #counter we'll use later in the program to print port_array


#--- try statement to ping ports ---
try:
    for port in range(low_port,high_port):                        #for loop to scan the user's range of IPs
        sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)  #create a socket that will be used to attempt to connect to the remote port
        result = sock.connect_ex((targetIP, port))                #save outcome of connecting to the remote port to result
        if result == 0:
            print "Port {}: 	 OPEN".format(port)               #print that n port was open
            port_array.append(port)                               #pushing the port number into the array
            port_counter += 1                                     #increment port+counter by 1

        if result != 0:                                           #print that n port was close
            print "Port {}: 	 CLOSED".format(port)
        sock.close()                                              #close the socket

#--- error handling ---
except KeyboardInterrupt:           #user terminated the scan
    print "Exit command executed"
    sys.exit()

except socket.gaierror:             #unable to ping ports
    print target, " appears to be down or not accepting ping request. Terminating the program."
    sys.exit()

except socket.error:                #unable to rearch the server
    print "Unable to connect to ", target
    sys.exit()
#--- end error handling ---
#--- end try statement ---

#--- letting the user know that the scan is complete ---
print "_" *60
print "\n"
print '---PORT SCAN COMPLETE---\n'
#--- end scan complete print ---

#--- ask user if they want to see links they can copy and paste to view detailed port info ---
port_info    = raw_input("To view links that relate to the ports press 1, to exit press 0: ")
print "\n"
#--- end get link answer ---

#--- loop to itirate through URLs for the open ports ---
#I wasn't able to find a solution to make URLs clickable, may be a Windows restriction and not so much on Python's end
if port_info == '1':       #user wants to see links
    print '\n---PORT INFORMATION LINKS---\n'
    if port_counter != 0:                   #if we found ports, print the info
        for x in range(0, port_counter):
            print "https://www.iana.org/assignments/service-names-port-numbers/service-names-port-numbers.xhtml?search=",port_array[x], "\n"
    if port_counter == 0:                   #if we didn't find open ports, let the user know
        print "No open ports were found during the scan."
    print "_" *60
    print "\n"
    raw_input("Press Enter to exit...")

#--- end URL print ---