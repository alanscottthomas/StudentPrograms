//Name: Alan Thomas
//Class: CSI337 - Cyber Security
//Professor: Dr. Dutta
//Program: Program#2 Transposition Cipher Decrypt
//Date: 1/22/18
//Purpose: To decrypt a cipher that used transposition.
//Notes: I followed the instructions in the text (p84) in order to obtain the decryption key. Below are the steps I followed and the results.

//2 4 0 1 3 5 6 7 | ADD
//0 1 2 3 4 5 6 7 | INDEX
//0 1 2 3 4 5 6 7 | SWAP
//2 4 0 1 3 5 6 7
//sort line 10 by line 11 numbers
//2 3 0 4 1 5 6 7 | DECRYPT KEY


#include<iostream>
#include<fstream>
#include<string>
#include<cstdlib>
using namespace std;

int main() {
	ifstream input("cipher2.txt");
	ofstream output("decrypted.txt");
	if (!input) {
		cout << "File not found!";
		system("pause");
		return 1;
	}

	string sentence;
	int remdiv, addchar;
	char *ptr, *ptr2;
	int num;
	int counter1 = 0, counter2 = 0, counter3 = 0;
	//int trans[8] = { 2,4,0,1,3,5,6,7 }; //encrypt key
	int trans[8] = { 2,3,0,4,1,5,6,7 }; //decrypt key
	while (getline(input, sentence)) {
		while (sentence[counter1] != '\0') {
			counter1++;
		}
	}

	remdiv = counter1 % 8;  //find whats the diff between actual characters and characters divisible by 8
	addchar = 8 - remdiv;   // This is the number of chars(x) to add to existing text to make no. of characters divisible by 8
	counter1 += addchar;   // find size of array

	ptr = new char[counter1];  // need two arrays. using same array does not work
	ptr2 = new char[counter1];
	input.clear();              // clear input object
	input.seekg(0, ios::beg);   // bring file pointer back to first location

	while (getline(input, sentence)) {
		while (sentence[counter2] != '\0') {
			for (int i = 0; i < counter1 - addchar; i++) {
				ptr[i] = sentence[counter2];  //populate the array;
				ptr2[i] = sentence[counter2];    //populate second array with same values;
				counter2++;
			}
		}
	}
	
	for (int i = counter1 - addchar; i<counter1; i++) {     // add filler 'x' to existing array to make no of chars divisible by 8
		ptr[i] = 'x';
		ptr2[i] = 'x';
	}
	

	counter2 = 0;   // reset counter2 to 0
	while (counter2<counter1) {
		for (int i = 0; i<8; i++) {
			ptr[counter2] = ptr2[trans[i] + counter3];   // this code will make sure that we are copying from correct locations of right side array ptr2
			output << ptr[counter2];
			counter2++;
		}
		counter3 += 8;  // adjust third counter to shift reading point in ptr2 array
	}

	input.close();
	output.close();


	return 0;
}








//encryption code saved for reference//
/*

//Transposition cipher
//make sure that secret.txt file has no empty spaces (no spacebar). All text is next to each other.


#include<iostream>
#include<fstream>
#include<string>
#include<cstdlib>
using namespace std;

int main() {
ifstream input("secret2.txt");
ofstream output("cipher2.txt");
if (!input) {
cout << "File not found!";
system("pause");
return 1;
}

string sentence;
int remdiv, addchar;
char *ptr, *ptr2;
int num;
int counter1 = 0, counter2 = 0, counter3 = 0;
int trans[8] = { 2,4,0,1,3,5,6,7 };
while (getline(input, sentence)) {
while (sentence[counter1] != '\0') {
counter1++;
}
}

remdiv = counter1 % 8;  //find whats the diff between actual characters and characters divisible by 8
addchar = 8 - remdiv;   // This is the number of chars(x) to add to existing text to make no. of characters divisible by 8
counter1 += addchar;   // find size of array

ptr = new char[counter1];  // need two arrays. using same array does not work
ptr2 = new char[counter1];
input.clear();              // clear input object
input.seekg(0, ios::beg);   // bring file pointer back to first location

while (getline(input, sentence)) {
while (sentence[counter2] != '\0') {
for (int i = 0; i < counter1 - addchar; i++) {
ptr[i] = sentence[counter2];  //populate the array;
ptr2[i] = sentence[counter2];    //populate second array with same values;
counter2++;
}
}
}

for (int i = counter1 - addchar; i<counter1; i++) {     // add filler 'x' to existing array to make no of chars divisible by 8
ptr[i] = 'x';
ptr2[i] = 'x';
}


counter2 = 0;   // reset counter2 to 0
while (counter2<counter1) {
for (int i = 0; i<8; i++) {
ptr[counter2] = ptr2[trans[i] + counter3];   // this code will make sure that we are copying from correct locations of right side array ptr2
output << ptr[counter2];
counter2++;
}
counter3 += 8;  // adjust third counter to shift reading point in ptr2 array
}

input.close();
output.close();


return 0;
}




*/
