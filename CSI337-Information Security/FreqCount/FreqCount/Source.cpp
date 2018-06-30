/*
Name: Alan Thomas
Class: CSI337 - Information Security
Assignment: Determine the frequency of characters in a text (exam 1: chapter 3 problem a)
Professor: Dr. Dutta
Notes:
No notes; program works as intended.
*/


//includes&namespace//
#include<iostream>
#include<fstream>
#include<string>
#include<cstdlib>
#include<iomanip>
using namespace std;
//-------------------//

//template to be used in printing in tabular form//
const char separator = ' ';
template<typename T> void printElement(T t, const int& width)
{
	cout << left << setw(width) << setfill(separator) << t;
}
//template to be used in printing in tabular form//

//begin execution//
int main() {
	int counter = 0, counter2 = 0, counter3 = 0;         //counters to track where we are in strings/iterations
	char *ptr1;                                          //ptr to store chars
	const int nameWidth = 8;                             //default width to be used for tabular print
	
	char arr1[] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };  //English alphabet array
	int arr2[26] = { 0 };								//array to store occurences of alphabet characters

	string sentence;                                    //sentence we'll pass chars into

	ifstream input("ourfile.txt");                     //file to check frequency of

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
		while (sentence[counter2] != '\0') {                 //do until EOL
			ptr1[counter2] = tolower(sentence[counter2]);    //populate first array
			counter2++;                                      //increment counter
		}
	}
	//--------------------------//


	counter2 = 0;  // reset counter2 to 0 for reuse


 //while to place chars into ptr then into outfile//
	while (counter2<counter) {
		for (int i = 0; i < 26; i++)
		{
			if (ptr1[counter2] == arr1[i])               //if ptr value is equal to array value
			{
				arr2[i] = arr2[i] + 1;                  //add 1 to the count of letter we are currently on
			}
		}
		counter2++;                                    //increment counter
	}
//---------------------------------------//

	cout << "Letter frequencies in your text"<<endl;
	cout << "_____________________________________________________"<<endl;



//while to print alphabet array//
	for (int i = 0; i < 26; i++)
	{
		printElement(arr1[i], nameWidth);
	}
//-------------------------//
	cout << endl;

//while to print occurences of character in the text//
	for (int i = 0; i < 26; i++)
	{
		printElement(arr2[i], nameWidth);
	}
//-----------------------------------------------//	
	
	cout << endl<<"_____________________________________________________"<<endl<<endl<<"Press ENTER to exit";
	
	cin.get();                           //pause so user can view results
	input.close();                       //close input file
	
	return 0;
}
//------------end frequency program-----------------//
