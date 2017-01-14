/*
AUTHOR: Alan Thomas
PROBLEM: Chapter 13 Question 13
CLASS: CSI330
Professor: Dr. Pokorny
DATE CODED: 12 / 1 / 2016.
------------------------------------------------------------------------------
USE: This program will generate an array of size 100 and populate the indexes with
a random number 1-200. Additionally, the ability to search for random numbers
utilizing sequential search is present, this function will also print several statistics
related to the search algorithm and the searched array.

NOTES: Only issue was with random numbers not generating correctly. After a quick Google
search I learned that I needed to include srand(time(NULL)) inorder to
improve the randomness.
-----------------------------------------------------------------------------
*/
#include <iostream>
#include <ctime>                                   //for random numbers
using namespace std;

//FUNCTION TO BUILD THE ARRAY//
void build_array(int random_array[])
{
	cout << "\n";
	srand(time(NULL));                           //generating random number w/o the system clock so the numbers are more like to be all unique
	for (int i = 0; i < 100; i++)                //loop to place random numbers into the array
	{
		random_array[i] = rand() % 200 + 1;      //placing a random into the ith index
	}
}
//--------------------------//

//FUNCTION TO PRINT CURRENT ARRAY//
void print_array(int random_array[])
{
	cout << "\n\n";
	for (int i = 0; i < 100; i++)               //loop to walk our array
	{
		cout << random_array[i] << " ";        //printing the value at the ith index
	}
	cout << "\n\n";
}
//-----------------------------//

//FUNCTION TO SEARCH ARRAY//
void search(int random_array[])
{
	int target=0;                               //int that will hold the random target value
	int searches=0;                             //counter to track number of searches performed
	int target_found=0;                         //counter that will track how many keys we are able to find
	int test = 0;                               //value to hold the number of test iterations inbetween finding targets
	srand(time(NULL));                          //disabling system clock for random seed
	
	for (int i = 0; i < 100; i++)               //loop to walk through the array
	{
		searches++;                             //increment search
		
	for (int k = 0; k < 100; k++)               //loop to iterate through the number of tries as prescribed by the text
		{
			target = rand() % 200 + 1;	        //assigning a random number to target
			if (target == random_array[i])      //comparing target against the ith value of the array
			{
				target_found++;			        //if our target is found, increment target found by 1
			}
			else {                              //if we don't find the key
				test++;                         //increment test to keep track of how many tries before we find a key
			}
				}
	}
	
	cout << "Successful searches: " << target_found << "\n";                                //printing how many keys we found in the random search
	cout << "Total searches: " << searches << "\n";                                         //print how many search were made
	cout << "Success rate: " <<(float)target_found / (float)searches * 100 << "%" <<"\n";   //dividing how many we found by the number of search to determine our success rate
	cout << "Average number of test per a search: " << (float)test /target_found<<"\n";     //dividing how many iterations by targets found to determine avg test performed before finding a key
	return;
}
//-----------------------//

//BEGIN EXECUTION//
int main()
{
	int random_array[100];                                      //declaring an array of size 100
	build_array(random_array);                                  //calling the build function to insert initial random numbers into our array
	char menuchoice;                                            //char to hold user's menu anwer
	
	cout << "--Sequential Sort Program--\n";                    //printing menu
	cout << "(A) Build random array\n";
	cout << "(B) Print contents of the array\n";
	cout << "(C) Perform Sequential sort analysis on array \n";
	cout << "(Q) to exit\n";

	do {                                          //WHILE STATEMENT FOR USER INPUT
		cout << "\nEnter selection: ";
		cin >> menuchoice;
		menuchoice = (char)toupper(menuchoice);   //MAKING INPUT UPPERCASE
		switch (menuchoice)                       //BEGIN SWITCH
		{

		case'A':                                  //case to insert new random numbers into the array
			build_array(random_array);            //calling the build function to insert random numbers into our array
			cout << "--Array build complete--\n";
			break;
		case'B':                                  //case to print the array
			print_array(random_array);            //sending our array to the print function
			break;
		case'C':                                  //case to perform the sequential search
			search(random_array);                 //calling search function with the array
			break;
		default:
			cout << "\nInvalid input\n\n";
			break;
		}
	} while (menuchoice != 'Q');                  //if q is entered exit the program
	
	return 0;
}
//---------------------//