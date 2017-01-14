//Assignment: #12, Chapter 11, Problem B
//Name: Alan Thomas
//4/29/2015
//Purpose: Use overloaded equality operator
//        and copy constructor to duplicate user created array

using namespace std;
#include "student.h"
#include <iostream>

Student::Student(int n){
	number = n;
	scoreptr = new double[number]; //allocating number of students

	for (int i = 0; i < number; i++){
		cout << "Enter score for student #" << i + 1 << " :";
		cin >> scoreptr[i];
	}
}
//Copy constructor
Student::Student(Student &obj){
	number = obj.number;
	scoreptr = new double[number];
	for (int i = 0; i < number; i++){
		scoreptr[i] = obj.scoreptr[i];
	}

}

//code to copy one object to another
//Use programmer defined in attempt to allow for more flexibility
void Student::operator=(const Student &right){
	if (number > 0) delete[] scoreptr;
	number = right.number;
	scoreptr = new double[number];
	for (int i = 0; i < number; i++){
		scoreptr[i] = right.scoreptr[i];
	}

}

void Student::getgrade(){
	for (int i = 0; i < number; i++){
		cout << scoreptr[i] << endl;
	}
}


int Student::getnumber(){
	return number;
}
