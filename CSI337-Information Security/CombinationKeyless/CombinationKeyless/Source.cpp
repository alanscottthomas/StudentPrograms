/*
Name: Alan Thomas
Class: CSI337 - Information Security
Assignment: Combination Keyless+Keyed Transposition Cipher | Assignment#5 Part 2
Professor: Dr. Dutta
Date: 2/8/18
Notes: No notes.
*/

#include<iostream>
#include <string>
using namespace std;

int main() {
	char ar[4];
	char arr[4][4];
	char array[16];
	char arr2[4][4];
	int rem;
	string sentence;
	int counter1 = 0, counter2 = 0, counter3 = 0;
	char letter = 32;

	char arr_[4][4];

	cout << "Enter the secret message: ";
	getline(cin, sentence);
	cout << endl << endl;

	//Populate the array with non-space characters only
	while (sentence[counter1] != '\0') 
	{
		if (sentence[counter1] == ' ') 
		{
			counter1++;
		}
		else 
		{
			array[counter2] = sentence[counter1];
			counter1++;
			counter2++;
		}
	}
	//--------------------------//

	//Find the number of filler characters
	rem = 16 - counter2;


	//Add the filler at the end of string
	for (int i = counter2; i<counter2 + rem; i++) 
	{
		array[i] = '-';
	}
	//-----------------------//


	//Write the text to the two dimensional array by rows
	for (int i = 0; i<4; i++) 
	{
		for (int j = 0; j<4; j++) 
		{
			arr[i][j] = array[counter3];
			counter3++;
		}
	}
	//-----------------------//


	//Adjust counter3 to zero
	counter3 = 0;

	//Copy the second columns to separate array ar;
	for (int i = 1; i<2; i++) 
	{
		for (int j = 0; j<4; j++) 
		{
			ar[counter3] = arr[j][i];
			counter3++;
		}
	}
	//-----------------------//


	//Adjust counter3 to zero
	counter3 = 0;


	
	//copy col 4 to col 2
	for (int i = 3; i<4; i++) 
	{
		for (int j = 0; j<4; j++) 
		{
			arr[j][i - 2] = arr[j][i];  //copy col 4 to col 2
			counter3++;
		}
	}
	//-----------------------//



	//Adjusy counter3 to 0
	counter3 = 0;



	//copy col 2 to col 4
	for (int i = 3; i<4; i++) 
	{
		for (int j = 0; j<4; j++) 
		{
			arr[j][i] = ar[counter3];   //copy col 2 to col 4
			counter3++;
		}
	}
	//---------------------//


	cout << "CIPHERTEXT: ";

	//Read back the cipher from two dimensional array by cols
	for (int i = 0; i<4; i++) 
	{
		for (int j = 0; j<4; j++) 
		{
			cout << arr[j][i];
		}
	}
	//-----------------------//
	
//------------------------------------------DECRYPT BELOW----------------------------------------------------------//	



	counter3 = 0;                                                 //resetting counter3 to 0

	//Copy col 4 to arr//                                   
	for (int i = 3; i<4; i++)
	{
		for (int j = 0; j<4; j++)
		{
			ar[counter3] = arr[j][i];                          //copy column 4 to ar since column 4 is about to be copied over
			counter3++;                                        //increment counter3
		}
	}
	//-----------------------//

	counter3 = 0;                                               //resetting counter3 to 0

	//copy column 2 to column  4
	for (int i = 3; i<4; i++)
	{
		for (int j = 0; j<4; j++)
		{
			arr[j][i] = arr[j][i - 2];  //copy col 2 to col 4
			counter3++;
		}
	}
	//-----------------------//
	
	counter3 = 0;                                        //reset counter3 to 0


	//copy col 4 to  col 2
	for (int i = 1; i<2; i++)
	{
		for (int j = 0; j<4; j++)
		{
			arr[j][i] = ar[counter3];                  //copy col 4 to col 2 using the stored col 4 data from ar
			counter3++;
		}
	}
	//---------------------//


	cout << endl << endl;
//Read back the decrypted information from two dimensional array by cols
	cout << "DECRYPTED DATA: ";
	for (int i = 0; i<4; i++)
	{
		for (int j = 0; j<4; j++)
		{
			if (arr[i][j] == '-')
			{
				break;
			}
			else {
				cout << arr[i][j];
			}
		}
	}
	//-----------------------//
	cout << endl << endl << endl << endl << "Press ENTER to exit";
	cin.get();
	return 0;
}
//------------end of program-------------//