/*
AUTHOR: Alan Thomas
PROBLEM - Chapter 12 program
CLASS:CSI330
Professor:Dr. Pokorny
DATE CODED 11 / 26 / 2016.
------------------------------------------------------------------------------
USE: This program will dynamically size an array according to the user's input.
Additionally, the user has the ability to print the array in a number of sorting
methods, including the ability to continue building upon the arrat with additional
integers.

NOTES: I had a fair bit of trouble getting the quicksort to work. After looking
at different algorithms and coming to the conclusing I had built my array incorrectly,
I was able to remedy the errors and produce a working version.
-----------------------------------------------------------------------------
*/
#include <iostream>
using namespace std;


//FUNCTION TO INSERT INTS INTO THE ARRAY//
int build_array(int* intarray, int* intarray_original, int counter)
{
	int user_number;                                                        //int to hold the user's value
	cout << "Enter integer to place into the array (-999 to exit) : ";
	cin >> user_number;                                                     //accepting user input

	while (user_number != -999)                                            //while statement to determine when to terminate loop
	{
		intarray[counter] = user_number;                                   //placing user's value into the array that will be sorted
		intarray_original[counter] = user_number;						   //placing the user's value into appropiate index location
		counter++;														   //incrementing counter 
		cout << "Enter integer to place into the array (-999 to exit) : ";
		cin >> user_number;                                                //prompting user once more to enter a value	
	}
	return counter;														   //returning the count number to keep track of array size. 
}
//----------------------------------//

//FUNCTION TO PRINT THE ORIGINAL ARRAY W/O SORTING//
void print_array(int* intarray_original, int counter)
{
	if (counter == 0)                                  //checking if the array is empty
	{
		cout << "The array is empty \n";
		return;
	}

	for (int i = 0; i < counter; i++)            //iterating i against the index count
	{
		cout << intarray_original[i] << " ";     //printing the countents of the unsorted array
	}
}
//-----------------------------------------------//


//FUNCTION FOR SELECTION SORT//
void selection_sort(int* intarray, int counter)
{
	int i = 0, k = 0;                                //ints to iterate through our index locations

	if (counter == 0)                                //checking if the array is empty
	{
		cout << "The array is empty\n";
		return;
	}

	for (k = 0; k < counter - 1; k++)               //incrementing j value until counter         
	{
		int min = k;                                //setting minumum value to k value
		for (i = k + 1; i < counter; i++) {         //loop to begin comparing index locations 
			if (intarray[i] < intarray[min]) {      //if the index at min is larger than i 
				min = i;                            //set minimum value to that of i
			}
		}
		if (min != k)                               //if the minimum value isn't equal to k
		{
			int temp_k = intarray[k];              //storing value at index k
			int temp_min = intarray[min];          //storing min value at min index
			intarray[k] = temp_min;                //set array index k to the min value
			intarray[min] = temp_k;                //set array min index to k value
		}
	}

	int walk = 0;
	cout << "The array sorted via selection sort is: ";

	while (walk < counter)                        //printing the sorted array
	{
		cout << intarray[walk] << " ";            //printing value at index walk
		walk++;                                   //increment walk
	}
}
//------------------------//


//INSERTION SORT//
void insertion_sort(int* intarray, int counter) {
	int k, temp;                                           //declaring variables to use in iterating through index locations

	if (counter == 0)                                      //checking if the array is empty
	{
		cout << "The array is empty\n";
		return;
	}

	for (int i = 0; i < counter; i++) {                   //begin loop to sort
		k = i;                                            //setting k to the value of i

		while (k > 0 && intarray[k] < intarray[k - 1]) { //looping while value of k is larger than 0 and index at j is smaller than value at index location - 1
			temp = intarray[k];                          //storing index value at index k to a temp value
			intarray[k] = intarray[k - 1];               //setting index value at k to k-1
			intarray[k - 1] = temp;                      //set k-1 to the previously stored index k value
			k--;                                         //decrement k
		}
	}

	int walk = 0;                                        //declaring value to use in printing sorted array
	cout << "The array sorted via insertion sort is: ";
	while (walk < counter)                               //loop to print the array
	{
		cout << intarray[walk] << " ";                   //print value at index walk
		walk++;                                          //incrementing walk
	}
}
//--------------------------//


//FUNCTION FOR BUBBLE SORT//
void bubble_sort(int* intarray, int counter)
{
	int i = 0, j = 0;
	if (counter == 0)                                //checking if the array is empty
	{
		cout << "The array is empty\n";
		return;
	}

	for (i = 0; i < counter; i++)                  //begin loop to compare index values
		for (j = i + 1; j < counter; j++)          //while j is smaller than our index count do this
			if (intarray[j] < intarray[i])         //if the adjacent value to i is smaller do this 
			{
				int temp;                          //temp int to store index i
				temp = intarray[i];                //store value of index i to temp
				intarray[i] = intarray[j];         //set index i to index j
				intarray[j] = temp;                //set index j to the stored value from temp
			}

	int walk = 0;                                  //declaring value to walk through array
	cout << "The array sorted via insertion sort is: ";
	while (walk < counter)                         //while counter is larger than walk
	{
		cout << intarray[walk] << " ";            //printing value located at index walk
		walk++;                                   //increment walk
	}
}
//------------------------------------//


//FUNCTION FOR QUICKSORT//
void quicksort(int* intarray, int left, int counter) {


	int right = counter;                              //set right value equal to our count
	int i = left, k = right;                          //setting i and k to left and right       
	int tmp;
	if (counter == 0)                                //checking if the array is empty
	{
		cout << "The array is empty\n";
		return;
	}

	int middle = intarray[(left + (right - left) / 2)]; //determining our middle value
	while (i <= k) {                                  //loop to begin checking left&right portion of array
		while (intarray[i] < middle)                  //while left value is smaller than the middle
			i++;                                      //increment i
		while (intarray[k] > middle)                  //while right value is larger than the middle value
			k--;                                      //decrement k
		if (i <= k) {                                 //if right value is larger than left value
			tmp = intarray[i];                        //set temp to index i
			intarray[i] = intarray[k];                //set index i to index k
			intarray[k] = tmp;                        //store value of index k to tmp
			i++;                                      //increment i
			k--;                                      //decrement k
		}
	}

	if (left < k)                                    //if the left value is smaller than value of k
	{
		quicksort(intarray, left, k);                //recursivley call quicksort with the array with left value and k
	}
	if (i < right)                                   //if i is smaller than the right
	{
		quicksort(intarray, i, right);               //recursivley call quicksort with the array with i value and right value 
	}
}
//-----------------------------------//

int main()
{
	typedef int myarray[100];                     //declaring myarray which will dynmaially hold our array values
	char menuchoice;
	int counter = 0;
	int *intarray = new myarray;                  //declaring int pointer to an array to store the sorted array
	int *intarray_original = new myarray;         //declaring int pointer to an array to store the users unsorted array

	cout << "--Array Sort Program--\n";           //printing the menu for the user
	cout << "(A) Insert integers into the array\n";
	cout << "(B) Print array w/o any sorting\n";
	cout << "(C) Selection sort\n";
	cout << "(D) Insertion sort\n";
	cout << "(E) Bubble sort\n";
	cout << "(F) Quicksort\n";
	cout << "(Q) to exit without printing the queue\n";

	do {                                                            //WHILE STATEMENT FOR USER INPUT
		cout << "\nEnter selection: ";
		cin >> menuchoice;
		menuchoice = (char)toupper(menuchoice);                    //MAKING INPUT UPPERCASE
		switch (menuchoice)                                         //BEGIN SWITCH
		{
		case'A':                                                //case to insert a value into the array
			counter = build_array(intarray, intarray_original, counter);//saving our updated counter & calling the build function to insert integers
			break;
		case'B':                                               //case to print the array w/o any sorting
			cout << "The array without sorting is: \n";
			print_array(intarray_original, counter);           //calling print function
			break;
		case'C':
			selection_sort(intarray, counter);                //call selection sort with array and count value
			break;
		case'D':
			insertion_sort(intarray, counter);                //call insertion sort with array and count value
			break;
		case'E':
			bubble_sort(intarray, counter);                   //call bubble sort with array and count value
			break;
		case'F':
			cout << "The array sorted via quicksort sort is: ";
			quicksort(intarray, 0, counter - 1);               //call quicksort with array and count-1 value
			print_array(intarray, counter);                  //calling print function
			break;
		default:
			cout << "\nInvalid input\n\n";
		}
	} while (menuchoice != 'Q');							  //if q is entered exit the program

	delete[] intarray;                                           //deleting intarray that held sorted values
	delete[] intarray_original;									 //deleting intarray that held unsorted values
	return 0;

}