#-------------------------------------------------------------------------------
# Name:        module1
# Purpose:
#
# Author:      Alan
#
# Created:     21/02/2018
# Copyright:   (c) Alan 2018
# Licence:     <your licence>
#-------------------------------------------------------------------------------

def main():
    pass

if __name__ == '__main__':
    main()


numstudents = int(input("Enter the number of students: "))
total=0
average=0.0
score=0


for i in range(numstudents):
    score=int(input("Enter score # {}".format(i+1)))
    total += score
average=total/numstudents
print "Average score for the students is", average
