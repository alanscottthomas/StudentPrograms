/*
Name: Alan Thomas
Class: CSI337 - Information Security
Assignment: Affine Cipher brute-force | Assignment#4
Professor: Dr. Dutta
Date: 2/7/18
Notes: No notes.
*/

//libraries//
#include<iostream>
#include<string>
#include<fstream>
#include<cstdlib>
#include<ctime>
using namespace std;
//--------------------//

//BRUTE-FORCE//
int main() {
	ifstream input("cipher12.txt");                                               //input cipher
	ofstream output("plaintext.txt");                                             //output of BF results
	string sentence;                                                              //string to store input
	                                                              
	int counter1 = 0, counter2 = 0, modnum;                                      //ints for counters and mod number result

	char *ptr;                                                                   //ptr to store characters from input
	
	
	char arr[] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };       //array of English alphabet
	int arr2[] = { 9,21,15,3,19,7,23 };                                         



//while to pull in input file//
	while (getline(input, sentence)) 
	{
		while (sentence[counter1] != '\0') 
		{
			counter1++;
		}
	}
//---------------------------//

	input.clear();                                                           //clear cache
	input.seekg(0, ios::beg);                                                //skip ahead

	ptr = new char[counter1];                                               //make ptr of size counter1

	//while loop to place contents of sentence into our pointer//
	while (getline(input, sentence)) 
	{
		while (sentence[counter2] != '\0') 
		{
			ptr[counter2] = sentence[counter2];

			counter2++;
		}
	}
	//------------------------------------//
	
	counter2 = 0;                                                        //increment counter2


	//brute-force logic//
	for (int j = 0; j < 7; j++)                                         //number to be used in modnum multiplication, we only goto 7
	{
		for (int k = 0; k < 26; k++)                                   //k will server as an increment in the alphabet
		{
			while (counter2 < counter1)                                //while counter2 is smaller than the size of out input string
			{
				for (int i = 0; i < 26; i++)                          //i to increment through the alphabet
				{
					if (toupper(ptr[counter2]) == toupper(arr[i]))     //comparing ptr value to arr value
					{
						modnum = (i - k) % 26;                         //set modnum equal to i-k mod 26
						if (modnum < 0)
						{
							modnum += 26; 
						}
						modnum = (modnum*arr2[j]) % 26;               //set modnum eqal to modnum multiplied arr[j] mod 26  
						ptr[counter2] = arr[modnum];                  //set ptr value to arr value
						break;
					}
				}
				output << ptr[counter2];                             //write to output file
				counter2++;                                          //increment counter2
			}
			output << endl;
			counter2 = 0;                                            //reset counter2 before we start loooping again
		}
	}
	//------------------------------//

	input.close();
	output.close();
	return 0;
}
//---------end program--------//
