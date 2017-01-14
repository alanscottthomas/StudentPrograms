/*
AUTHOR: Alan Thomas
PROBLEM - Ch5 Problem 10
CLASS:CSI330
Professor:Dr. Pokorny
DATE CODED 10 / 17 / 2016.
------------------------------------------------------------------------------
USE: This program accepts integer input from a user and will present the list
once the user selects that function.

Notes: None
-----------------------------------------------------------------------------
*/

#include <iostream>
using namespace std;

struct NODE
{
	int data;
	NODE* link;
};


//Function to receive input from the user//
void GET_INPUT(NODE* &node)
{
	cout << "\nPlease enter your integers(-999 to exit): ";
	int n;
	cin >> n;
	if (n == -999) return; //returns user to the menu
						 
	if (node == NULL)
	{
		node = new NODE;
		node->data = n;
		node->link = NULL;
	}
	
	NODE* t; //creating node t to hold temp values
	t = node; //setting our t node to the node that 
	cin >> n;
	
	while (n != -999)  //while user input does not equal -999 continue placing ints into the list
	{
		t->link = new NODE;
		t = t->link;
		t->data = n;
		t->link = NULL;
		cin >> n;
	}
}
//---------------------------//

//Print function//
void PRINT(NODE* node)
{
	if (node == NULL) //checking if there's anything to print in our list
	{
		cout << "You have not placed any integers into the list.";
		return;
	}
	else
	{
		NODE* next;
		next = node;
		cout << "\nYou entered: ";
		while (next->link != NULL) //keep printing the data until our link is set to null
		{
			cout << next->data << " ";
			next = next->link;		
		}
		cout << next->data << "  ";
	}
}
//--------------------//

//Begin execution//
int main()
{
	NODE* node = NULL;  //making a new node and setting it to NULL
	char menuchoice;   //declaring a variable to accept user input
	//printing the menu for the user
	cout << "--Linked List Program for Integer Input--\n";
	cout << "(A) Place integers into the list\n";
	cout << "(B) Print the list\n";
	cout << "(Q) Exit\n";
	
	do {
		cout << "\n\nEnter selection: ";
		cin >> menuchoice;
		menuchoice = (char)toupper(menuchoice);
		switch (menuchoice)
		{
		//calls function to input integers into the linked list	
		case'A':
			GET_INPUT(node);
			break;

		//calls function to print our list	
		case 'B':
			PRINT(node);
			break;
		//user entered an invalid input
		default:
			cout << "\nInvalid input\n\n";
		}
	} while (menuchoice != 'Q'); //ending swith statement

	return 0;
}
//-------------------//