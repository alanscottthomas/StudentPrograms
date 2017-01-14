//Assignment: #12, Chapter 11, Problem A
//Name: Alan Thomas
//4/29/2015
//Purpose: Use overloaded operators
//        to manipulate inventory information


#ifndef INVENTORY_H
#define INVENTORY_H

#include <iostream>
#include <string>

//Was having issues with declarations in the header file.
// Moved using std portion to main cpp and seems to have
// resolved the issue


//start Inventory class
class Inventory{
	private:
		int quantity;
		std::string partname;

	public:

		//Inventory();
		Inventory(int,std::string);
		int getquantity();
		std::string getpartname();
		int temp;


		 Inventory operator+(Inventory);
		 Inventory operator-(Inventory);


		Inventory operator++(int);
};
#endif
