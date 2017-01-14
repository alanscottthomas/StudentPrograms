//Assignment: #12, Chapter 11, Problem C
//Name: Alan Thomas
//4/29/2015
//Purpose: Demonstrate knowledge of inheritance to 
//         input/print data. *I had some issues with this one
//         ended up creating the functions in the mother class.
#include "machine.h"
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;


int main(){
	string make,model,colortype,resolution;
	double price;

	
	
	cout << endl << "--BEGIN FIRST OBJECT--" << endl;
	cout << "Make for first object: ";
	getline(cin, make);

	cout << endl << "Model of first object: ";
	getline(cin, model);

	cout << endl << "Color of first object: ";
	getline(cin, colortype);

	cout << endl << "Resolution(High,medium, low): ";
	getline(cin, resolution);

	cout <<endl<< "Price of first object: ";
	cin >> price;

	//first object
	Scanner one(resolution, price);
	one.setcolor(colortype);
	one.setmake(make);
	one.setmodel(model);
	cin.clear();
	cin.ignore();

	cout <<endl<<endl<<"--BEGIN SECOND OBJECT--"<<endl<<endl<< "Make for second object: ";
	getline(cin, make);

	cout << endl << "Model of second object: ";
	getline(cin, model);

	cout << endl << "Color of second object: ";
	getline(cin, colortype);

	cout << endl << "Resolution(High,medium, low): ";
	getline(cin, resolution);

	cout <<endl<< "Price of second object: ";
	cin >> price;

	//creating second object
	Printer two(colortype, price);
	two.setmake(make);
	two.setmodel(model);
	two.setresolution(resolution);

	//printing first obj information
	cout << "--OBJECT ONE INFORMATION--" << endl;
	cout << one.getmake() << endl << one.getmodel() << endl << one.getcolor() << endl << one.getresolution() << endl << one.getprice() << endl;

	//printing second object information
	cout <<endl<< "--OBJECT TWO INFORMATION--" << endl;
	cout << two.getmake() << endl << two.getmodel() << endl << two.getcolortypes() << endl << two.getres() << endl << two.getprice() << endl;
	
	

	system("pause");
	return 0;
}