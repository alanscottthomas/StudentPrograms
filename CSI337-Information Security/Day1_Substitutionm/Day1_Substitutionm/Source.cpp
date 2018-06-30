//Name: Alan Thomas
//Class: CSI337 - Cyber Security
//Professor: Dr. Dutta
//Program: Program#1 Mono-Alphabetic Substitution Cipher
//Purpose: To decrypt a cipher that used mono-alphabetic substitution encryption
//Notes: I rearranged arr2 to troubleshoot some issues. It's simply the alphabet in reverse. 
//Additionally, I had to move the counter to the inside loop in order for the decryption to operate properly.

#include<iostream>
#include<string>
#include<fstream>
using namespace std;

//main function to decrypt//
int main() {
	string sentence;                                                                                                                 //string to hold the values of the input/output
	int counter = 0;                                                                                                                 //used to track where we are in the array
	char arr1[] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };       //English alphabet in standard order
	char arr2[] = { 'z','y','x','w','v','u','t','s','r','q','p','o','n','m','l','k','j','i','h','g','f','e','d','c','b','a' };       //English alphabet in reverse
	ifstream input("cipher2.txt");                                                                                                   //input for the cypher text
	ofstream output("decrypt.txt");                                                                                                  //output for decrypted data
	while (getline(input, sentence)) {                                                                                               //while to read in from input
		while (sentence[counter] != '\0') {                                                                                          //while we haven't encountered EOL continue
			for (int i = 0; i <= 26; i++) {                                                                                          //iterate through 26 till we find a match
				if (toupper(sentence[counter]) == toupper(arr2[i])) {                                                                //if our position in the string matches the arr[count] do this
					sentence[counter] = arr1[i];                                                                                     //replace the value in sent[counter] to arr1[i]
					counter++;                                                                                                       //increment counter by 1
				}
			}
		}
		output << sentence;                                                                                                          //write decrypted data to output file
	}
	input.close();                                                                                                                   //closing the input file
	output.close();                                                                                                                  //closing the output file
	return 0;
}
//--------------//





/*
//encrypt code saved for reference//
int main() {
string sentence;
int counter = 0;
char arr1[] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };
char arr2[] = { 'z','y','x','w','v','u','t','s','r','q','p','o','n','m','l','k','j','i','h','g','f','e','d','c','b','a' };
ifstream input("secret.txt");
ofstream output("cipher2.txt");
while (getline(input, sentence)) {
while (sentence[counter] != '\0') {
for (int i = 0; i <= 26; i++) {
if (toupper(sentence[counter]) == toupper(arr1[i])) {
sentence[counter] = arr2[i];
counter++;
}
}

}
output << sentence;
}
input.close();
output.close();
//system("pause");
return 0;
}
*/




