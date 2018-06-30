/*
Name: Alan Thomas
Class: CSI337 - Information Security
Assignment: Hill Cipher Decrypt | part 1 of assignment # 5
Professor: Dr. Dutta
Date: 2/8/18
Notes: I initially made this program more difficult than it needed to be. I attempted to determine the inverse of the matrix by using code, and that
was incredibly more difficult than I had imagined. After determining you probably just wanted us to hardcode the inverse matrix it went quite a bit
more smoothly.
*/


#include<iostream>
using namespace std;

//-----begin execution---///
int main() {
	int total = 0, newtotal = 0, counter1 = 0, counter2 = 0, counter3 = 0, counter = 0;           //counters that will be used
	
	char arr[] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };   //alphabet array

	//PT:code is ready//
	int arr1[3][4] = { { 2,14,3,4 },                                                             //the matrix that holds the numerical value of our message
					   { 8,18,17,4 },
					   { 0,3,24,25 } };
	//-----------//

	//key//
	int arr2[4][4] = { { 9,7, 11, 13 },                                                         //the key that will be used to encrypt
					   { 4,7, 5,  6 },
					   { 2,21,14,9 },
					   { 3,23,21,8 } };
	//-------------//

	//cipher array//
	int arr3[3][4];                                                                            //the array that will store the encrypted number values
	//---------//

	//inverse of the key//
	int arr4[4][4] = { { 2,15, 22, 3 },                                                       //matrix that stores the multiplicative inverse of our key
	{ 15,0, 19,  3 },
	{ 9,9,3,11 },
	{ 17,0,4,7 } };
	//-------------//


	//Decrpyt Array//
	int arr5[3][4];                                                                           //array that will store the decrypted numerical values
	//-----------//


	//while loop to perform modulo math//
	while (counter1<3) 
	{
		while (counter2<4) 
		{
			total += arr1[counter1][counter2] * arr2[counter2][counter3];                  //setting total to the value of our key and PT array multiplied
			counter2++;                                                                    //increment counter2
		}
			
		arr3[counter1][counter3] = total % 26;                                            //set arr3[value][value] to total mod 26
		total = 0;                                                                        //reset total to 0
		counter3++;                                                                       //increment counter3 
		counter2 = 0;                                                                     //set counter2 to 0

		if (counter3>3)                                                                  //if we've gone past the column size do this
		{
			counter3 = 0;                                                                //set counter3 to 0
			counter1++;                                                                  //increment counter1
		}
	}
	//----------------------------------------//


	//print cipher values//
	cout << " \nCIPHER\n"<<"__________________________________________"<<endl;
	for (int i = 0; i<3; i++) 
	{
		for (int j = 0; j<4; j++) 
		{
			cout << arr3[i][j] << " ";
		}
		cout << endl;
	}
	//--------------------//

	
	//print ciphertext//
	cout << " \nCIPHERTEXT\n" << "__________________________________________" << endl;
	
	for (int i = 0; i < 3; i++) 
	{
		for (int j = 0; j < 4; j++) 
		{
			cout << arr[arr3[i][j]];
		}
		//cout << endl;	
	}
	//---------------//


	total = 0, newtotal = 0, counter1 = 0, counter2 = 0, counter3 = 0, counter = 0;                 //resetting out counter values to be used in decryption

	//while loop to perform modulo math//
	while (counter1<3) 
	{
		while (counter2<4)
		{
			total += arr3[counter1][counter2] * arr4[counter2][counter3];                  //setting total to the value of our inverse key and encrypted array multiplied
			counter2++;                                                                    //increment counter2
		}

		arr5[counter1][counter3] = total % 26;                                          //set arr4[value][value] to total mod 26
		total = 0;                                                                      //reset total to 0
		counter3++;                                                                     //increment counter3 
		counter2 = 0;                                                                   //set counter2 to 0

		if (counter3>3) 
		{                                                                              //if we've gone past the column size do this
			counter3 = 0;                                                              //set counter3 to 0
			counter1++;                                                                //increment counter1 
		}
	}
	//------------------------------------------//


	//print decrypted values of the matrix//
	cout << "\n\nDECRYPTED VALUES\n" << "__________________________________________" << endl;
	for (int i = 0; i<3; i++) 
	{
		for (int j = 0; j<4; j++) 
		{
			cout << arr5[i][j] << " ";
		}
		cout << endl;
	}
	//--------------------//


	//print plain text//
	cout << "\n\nPLAINTEXT\n" << "__________________________________________" << endl;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cout << arr[arr5[i][j]];
		}
		//cout << endl;
	}
	//---------------//

	cin.get();                                                                          //pausing for user to view results  
	return 0;
}
//--------------end program------------------//