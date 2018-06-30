/*
Name: Alan Thomas
Class: CSI337 - Information Security
Assignment: Decryption of polyalphabetic substitution cipher - single pass
Professor: Dr. Dutta
Notes:
No notes; program works as intended.
*/


//includes&namespace//
#include<iostream>
#include<fstream>
#include<string>
#include<cstdlib>
#include<ctime>
using namespace std;
//-------------------//



//decrypt//
//begin execution//
int main() {
	int counter = 0, counter2 = 0, counter3 = 0;         //counters to track where we are in strings/iterations
	int revnum = 0;                                      //number held after reversing mod math    
	char *ptr1;                                          //ptr to store chars

	char arr1[] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };  //regular characters

	string sentence;                                    //sentence we'll pass chars into

	ifstream input("cipher15.txt");                     //encrypted data file
	ofstream output("decrypted.txt");                   //target decryption file

														
	//if can't open input file//
	if (!input) {
		cout << "File Not Found !";
		return 1;
	}
	//------------------------//

	//while loop to read input file//
	while (getline(input, sentence)) {
		while (sentence[counter] != '\0') {
			counter++;
		}
	}
	//---------------------------//


	input.clear();              //clear cache
	input.seekg(0, ios::beg);  //pull up the file counter back to beginning

	ptr1 = new char[counter];
	
	
	//while loop to read input file//
	while (getline(input, sentence)) {
		while (sentence[counter2] != '\0') {         //do until EOL
			ptr1[counter2] = sentence[counter2];    //populate first array
			counter2++;                             //increment counter
		}
	}
	//--------------------------//


	counter2 = 0;  // reset counter2 to 0 for reuse
	
				   
	//while to place chars into ptr then into outfile//
	while (counter2<counter) {
		for (int i = 0; i < 25; i++)
		{
			if (ptr1[counter2] == arr1[i])               //if ptr value is equal to array value
			{
				revnum = (i - counter3 + 25) % 25;      //reverse math
				if (revnum < 0)
				{
					revnum += 25;
				}
				ptr1[counter2] = arr1[revnum];         //set ptr to arr value
				counter3++;                           //increment counter
				break;
			}
		}
		output << ptr1[counter2];                   //output ptr to decrypt file
		counter2++;                                 //increment counter
	}

	input.close();
	output.close();                                //close files
	return 0;
}
//------------end decrpytion program-----------------//




//saved encryption code for reference//
/*
//encryption code//

int main() {
	int counter = 0, counter2 = 0, counter3 = 0;
	int randnum;
	char *ptr1;

	char arr1[] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };  //regular characters

	string sentence;

	ifstream input("secret.txt");
	ofstream output("cipher15.txt");

	if (!input) {
		cout << "File Not Found !";
		return 1;
	}

	while (getline(input, sentence)) {
		while (sentence[counter] != '\0') {
			counter++;
		}
	}

	input.clear();
	input.seekg(0, ios::beg);  //pull up the file counter back to beginning

	ptr1 = new char[counter];

	while (getline(input, sentence)) {
		while (sentence[counter2] != '\0') {
			ptr1[counter2] = sentence[counter2];    //populate first array
			counter2++;
		}
	}

	counter2 = 0;  // reset counter2 to 0 for reuse

	while (counter2<counter) {
		for (int i = 0; i<26; i++) {
			if (toupper(ptr1[counter2]) == toupper(arr1[i])) {
				randnum = (i + counter3) % 26;   // use modulo math to create the remainder of (i+counter3)%26 which will be from 0 to 25
				ptr1[counter2] = arr1[randnum];   //replace the original letter with a new letter based on value of randnum
				counter3++;
				break;
			}
		}

		output << ptr1[counter2];
		counter2++;
	}


	input.close();
	output.close();

	return 0;
}
*/