/*
Name: Alan Thomas
Class: CSI337 - Information Security
Assignment: Decryption of polyalphabetic substitution cipher - 2 pass
Professor: Dr. Dutta
Notes:
My implementation of this program isn't very eloquent; in fact, it could use a lot of refactoring.
However, it works. I simply copied the code from the first pass and renamed some variables for simplicity sake
and passed the data through a second time to decrypt the data that had gone through 2 passes of the encyrption algorithm.
*/

//includes&namespace//
#include<iostream>
#include<fstream>
#include<string>
#include<cstdlib>
#include<ctime>
using namespace std;
//-------------------//

//decrypt 1st pass//
//begin execution//
int main() {
	int counter = 0, counter2 = 0, counter3 = 0;    //counters to track where we are in strings/iterations
	int revnum = 0;                                 //number held after reversing mod math                                
	char *ptr1;                                     //ptr to store chars

	char arr1[] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };  //regular characters

	string sentence;                               //sentence we'll pass chars into

	ifstream input("cipher15.txt");                //encrypted data file
	ofstream output("decrypted.txt");              //target decryption file

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
		while (sentence[counter2] != '\0') {        //do until EOL
			ptr1[counter2] = sentence[counter2];    //populate first array
			counter2++;                             //increment counter
		}
	}
	//--------------------------//

	counter2 = 0;  // reset counter2 to 0 for reuse

	//while to place chars into ptr then into outfile//
	while (counter2<counter) {
		for (int i = 0; i < 26; i++)
		{
			if (ptr1[counter2] == arr1[i])            //if ptr value is equal to array value
			{
				revnum = (i - counter3 + 26) % 26;    //reverse math
				if (revnum < 0)
				{
					revnum += 26;
				}
				ptr1[counter2] = arr1[revnum];       //set ptr to arr value
				counter3++;                          //increment counter
				break;
			}
		}
		output << ptr1[counter2];                    //output ptr to decrypt file
		counter2++;                                  //increment counter
	} 
	input.close();
	output.close();                                 //close files
	//------------end decrypt 1st pass------------//

	
	
	//decrypt 2nd pass//
	counter = 0, counter2 = 0, counter3 = 0;    //counters to track where we are in strings/iterations
	revnum = 0;                                 //number held after reversing mod math
	char *ptr2;                                 //ptr to store chars


	string sentence2;                          //sentence we'll pass chars into
	ifstream input2("decrypted.txt");          //encrypted data file
	
	//if can't open input file//
	if (!input2) {
		cout << "File Not Found !";
		return 1;
	}
	//------------------------//
	
	//while loop to read input file//
	while (getline(input2, sentence2)) {
		while (sentence2[counter] != '\0') {
			counter++;
		}
	}
	//---------------------------//

	input2.clear();              //clear cache
	input2.seekg(0, ios::beg);  //pull up the file counter back to beginning

	ptr2 = new char[counter];
	
	
	//while loop to read input file//
	while (getline(input2, sentence2)) {
		while (sentence2[counter2] != '\0') {         //do until EOL
			ptr2[counter2] = sentence2[counter2];    //populate first array
			counter2++;                              //increment counter
		}
	}
	//--------------------------//

	input2.close();                                 //closing input file so we can use it for second pass
	ofstream output2("decrypted.txt");              //output file
	counter2 = 0;  // reset counter2 to 0 for reuse
	
//while to place chars into ptr then into outfile//
	while (counter2<counter) {
		for (int i = 0; i < 26; i++)
		{
			if (ptr2[counter2] == arr1[i])           //if ptr value is equal to array value
			{
				revnum = (i - counter3 + 26) % 26;   //reverse math
				if (revnum < 0)
				{
					revnum += 26;
				}
				ptr2[counter2] = arr1[revnum];      //set ptr to arr value
				counter3++;                          //increment counter
				break;
			}
		}
		output2 << ptr2[counter2];                 //output ptr to decrypt file
		counter2++;                               //increment counter
	}
	output2.close();                             //close files
	return 0;
}
//-----end 2nd pass decrpt-----//





//saved the encryption code for testing purposes
/* 
//encryption 2 pass code//

int main() {
	int counter = 0, counter2 = 0, counter3 = 0;
	int randnum;
	char *ptr1;
	string sentence;

	char arr1[] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };  //regular characters

	

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


	counter = 0, counter2 = 0, counter3 = 0;
	randnum=0;
	char *ptr2;
	string sentence2;



	ifstream input2("cipher15.txt");
	


	if (!input2) {
		cout << "File Not Found !";
		return 1;
	}

	while (getline(input2, sentence2)) {
		while (sentence[counter] != '\0') {
			counter++;
		}
	}

	input2.clear();
	input2.seekg(0, ios::beg);  //pull up the file counter back to beginning

	ptr2 = new char[counter];

	while (getline(input2, sentence2)) {
		while (sentence2[counter2] != '\0') {
			ptr2[counter2] = sentence2[counter2];    //populate first array
			counter2++;
		}
	}
	input2.close();
	ofstream output2("cipher15.txt");
	counter2 = 0;  // reset counter2 to 0 for reuse

	while (counter2<counter) {
		for (int i = 0; i<26; i++) {
			if (toupper(ptr2[counter2]) == toupper(arr1[i])) {
				randnum = (i + counter3) % 26;   // use modulo math to create the remainder of (i+counter3)%26 which will be from 0 to 25
				ptr2[counter2] = arr1[randnum];   //replace the original letter with a new letter based on value of randnum
				counter3++;
				break;
			}
		}

		output2 << ptr2[counter2];
		counter2++;
	}


	
	output2.close();



	return 0;
}
*/