//Assignment: #12, Chapter 11, Problem A
//Name: Alan Thomas
//4/29/2015
//Purpose: Use overloaded operators
//        to manipulate inventory information
#include <string>
#include <iostream>
#include <cstdlib>
#include "inventory.h"
using namespace std;


int main(){
	int num;
	string name;

	//Begin getting information for part name
	cout << "Part name: ";
	getline(cin, name);
	cout <<endl<< "Quantity of part: ";
	cin >> num;
	//creating mypart object
	Inventory mypart(num, name);
	
	
	//************START OVERLOADED + OPERAND****************
	//Asking for a number to add to mypart in order to demonstrate overloaded +
	cout << endl << "Enter a quantity to add to " << name << ": ";
	cin >> num;
	//creating object testing in order to demonstrate overloaded +
	Inventory testing(num, name);
	//adding the two objects together utilizing an overloaded + operator
	mypart = mypart + testing;
	//displaying the results
	cout <<endl<<mypart.getpartname()<<" quantity is: "<< mypart.getquantity()<<endl;
	//************END OVERLOADED + OPERAND****************

	
	
	//************START OVERLOADED - OPERAND****************
	//Asking for a number to add to mypart in order to demonstrate overloaded -
	cout << endl << "Enter a quantity to subtract from " << name << ": ";
	cin >> num;
	//creating object testing in order to demonstrate overloaded -
	Inventory testing_2(num, name);
	//utilizing an overloaded - operator
	mypart = mypart - testing_2;
	//displaying the results
	cout << endl << mypart.getpartname() << " quantity is: " << mypart.getquantity() << endl;
	//************END OVERLOADED - OPERAND****************
	
	//************START OVERLOADED ++ OPERAND****************
	mypart++;
	cout <<endl<<name<<" is "<< mypart.getquantity()<<" after being incremented."<<endl;
	system("pause");
	//************END OVERLOADED ++ OPERAND****************


	return 0;
}