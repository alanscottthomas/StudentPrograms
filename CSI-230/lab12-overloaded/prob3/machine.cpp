//Assignment: #12, Chapter 11, Problem C
//Name: Alan Thomas
//4/29/2015
//Purpose: Demonstrate knowledge of inheritance to 
//         input/print data. *I had some issues with this one
//         ended up creating the functions in the mother class.

#include "machine.h"
#include <iostream>
#include <string>
using namespace std;


//Machine class functions
void Machine::setmodel(string m){
	model = m;
}

void Machine::setmake(string m){
	make = m;
}

void Machine::setcolor(string c){
	color = c;
}

void Machine::setresolution(string r){
	resolution = r;
}

string Machine::getmodel(){
	return model;
}
string Machine::getmake(){
	return make;
}
string Machine::getcolor(){
	return color;
}
string Machine::getres(){
	return resolution;
}

//printer functions
string Printer::getcolortypes(){
	return colortype;
}

double Printer::getprice(){
	return price;
}

//scanner functions
string Scanner::getresolution(){
	return resolution;
}

double Scanner::getprice(){
	return price;
}

