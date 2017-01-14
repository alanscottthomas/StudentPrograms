/*
AUTHOR: Alan Thomas
PROBLEM: Chapter 13 Question 15
CLASS: CSI330
Professor: Dr. Pokorny
DATE CODED: 12 / 6 / 2016.
------------------------------------------------------------------------------
USE: This program will generate an array of size 100 and populate the indexes 
with numbers in the range of 1-150. Additionally, the ability to search for random numbers
utilizing binary search is present, this function will also print several statistics
related to the search algorithm and the searched array.

NOTES: I had planned to just copy and paste the code from question 13 and change the algorithm
for the search function, however, I wasn't able to pull that off. As a result, I had to use
a couple of extra functions to make things work. I feel as though the code is a bit convoluted
and more 'clunky' than need be. However, it works and maintains a certain degree of readability.
-----------------------------------------------------------------------------
*/
#include <iostream>
#include <ctime>                                   //for random numbers
using namespace std;

//FUNCTION TO BUILD THE ARRAY//
void build_array(int random_array[])
{
	cout << "\n";
	int indexvalue = 1;                           //setting indexvalue to 1
	bool flipper = false;                         //set bool to false,itirates the +2 and +1 specifications of the program
	for (int i = 0; i < 100; i++)                //loop to place numbers into the array
	{
		if (flipper == false)                  //if flipper is false
		{
			random_array[i] = indexvalue;      //placing a random into the ith index
			indexvalue = indexvalue + 2;       //add 2
			flipper = true;                    //set flipper to true
		}
		else if (flipper == true)              //if flipper is true
		{
			random_array[i] = indexvalue;      //placing an int into the ith index
			indexvalue = indexvalue + 1;       //plus 1 to the value
			flipper = false;                   //set flipper to false
		}
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

//FUNCTION TO PRINT SEARCH STATISTICS//
void statistics(int found,int searches,int test)
{
	cout << "Successful searches: " << found << "\n";
	cout << "Total searches: " << searches << "\n";
	cout << "Success rate: " << (float)found / (float)searches * 100 << "%" << "\n";         //determining our rate of success
	cout << "Average number of test per a search: " << (float)test / found << "\n";          //determine time between successful searches
}
//-----------------------------//


//BINARY SEARCH FUNCTION//
void search(int array[], int n, int target, bool reset)
{
	int index = -1, i = 0;                                     //set index to -1 and i to 0
	static int found_count = 0, searches = 1,test=0;           //using static ints to track our numbers from the calling function
	bool found = false;
	
	if (reset == false)                                       //check if a reset is required (last call from the calling function)
	{
		searches++;                                           //increment searches for tracking purposes
		while (i < n && !found)                               //while i value is less than n and target has not been found
		{
			if (array[i] == target)                          //if target has been found
				{
					index = i;                                   //set the index int to i
					found = true;                                //set found to true
					found_count++;                               //increment found count for tracking purposes
				}
			++i;                                            //increment i to conetinue our search 
			test++;                                          //increment test for tracking purposes
		}
		if (index == -1)                                    //target is not found in the array. We'll do nothing for this case.
		{
				;
		}
	}
	
		if(reset==true)
		{
			cout << "\n";
			statistics(found_count,searches,test);       //call the stats function with our tracking information
			found_count = 0, searches = 1, test = 0;     //reset our static variables
		}
}
//-----------------------//

//FUNCTION TO CALL SEARCH WITH RANDOM NUMBERS//
void random_number(int random_array[])
{
int target;
srand(time(NULL));                                         //seeding random number
for (int i = 0; i < 100; i++)                              //begin loop to call search function with random numbers
	{
		target = rand() % 150 + 1;						   //set target to a random number 1-150
		if (i < 99)                                       //if loop is not complete
		{                   
			search(random_array, 100, target, false);     //call search with array, size of array,target and reset as false
		}
		else                                              //on our last call
		{
			search(random_array, 100, target, true);     //call search with array, size of array,target and reset as true
		}
	}
}
//-----------------------------------------//


//BEGIN EXECUTION//
int main()
{
	int random_array[100];                                      //declaring an array of size 100
	build_array(random_array);                                  //calling the build function to insert initial numbers into our array
	char menuchoice;                                            //char to hold user's menu anwer
	int i = 0;

	cout << "--Sequential Sort Program--\n";                    //printing menu
	cout << "(A) Print contents of the array\n";
	cout << "(B) Perform Sequential sort analysis on array \n";
	cout << "(Q) to exit\n";

	do {                                          //WHILE STATEMENT FOR USER INPUT
		cout << "\nEnter selection: ";
		cin >> menuchoice;
		menuchoice = (char)toupper(menuchoice);   //MAKING INPUT UPPERCASE
		switch (menuchoice)                       //BEGIN SWITCH
		{
		case'A':                                  //case to print the array
			print_array(random_array);            //sending our array to the print function
			break;
		case'B':                                  //case to perform the binary search
			random_number(random_array);
			break;
		default:
			cout << "\nInvalid input\n\n";
			break;
		}
	} while (menuchoice != 'Q');                  //if q is entered exit the program
	return 0;
}
//---------------------//

