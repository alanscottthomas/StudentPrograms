//Assignment: #12, Chapter 11, Problem B
//Name: Alan Thomas
//4/29/2015
//Purpose: Use overloaded equality operator
//        and copy constructor to duplicate user created array

#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>

class Student{
	private:
		std::string name;
		double *scoreptr;
		int number;
	public:
		Student(int);
		Student::Student(Student &obj); //copy constructor proto
		void operator=(const Student &right); //oveloading the = operator

		int getnumber();
		void getgrade();



};



























#endif