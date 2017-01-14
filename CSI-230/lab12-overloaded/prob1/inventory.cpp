//Assignment: #12, Chapter 11, Problem A
//Name: Alan Thomas
//4/29/2015
//Purpose: Use overloaded operators
//        to manipulate inventory information

using namespace std;
#include <iostream>
#include "inventory.h"



Inventory::Inventory(int q,string pn){
	quantity = q;
	partname = pn;
}

//function to get the quantity

int Inventory::getquantity(){
	return quantity;
}

//function to get partname
string Inventory::getpartname(){
	return partname;
}

Inventory Inventory::operator-(Inventory b){
	Inventory new_inventory(b.quantity, b.partname);
	new_inventory.quantity = quantity - b.quantity;
	return (new_inventory);
}

Inventory Inventory::operator+(Inventory b){
	Inventory new_inventory(b.quantity,b.partname);
	new_inventory.quantity = quantity + b.quantity;
	return (new_inventory);
}

Inventory Inventory::operator++(int){
	Inventory temp = *this;
	quantity++;
	return temp;
} 