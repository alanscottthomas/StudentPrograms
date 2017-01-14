//Assignment: #12, Chapter 11, Problem B
//Name: Alan Thomas
//4/29/2015
//Purpose: Use overloaded equality operator
//        and copy constructor to duplicate user created array

using namespace std;
#include "student.h"
#include <iostream>
#include <cstdlib>
int main(){
	int num;

	//Getting number of students for new_student object
	cout << "Enter number of students in the class: ";
	cin >> num;
	//creating object of Student with number of students
	Student first(num);
	Student second(0);
	
//Demonstrating overloaded equality
	cout << endl << "--OVERLOADED EQUALITY EXAMPLE--"<<endl;
	second = first;
	second.getgrade();

	
	//Demonstrating copy constructor
	Student third = first;
	cout << endl <<"--COPY CONSTRUCTOR--"<< endl;
	third.getgrade();

	system("pause");

	return 0;


}