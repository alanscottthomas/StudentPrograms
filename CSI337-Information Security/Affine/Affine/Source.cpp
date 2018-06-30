#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>


using namespace std;



int main()
{
	ifstream input("secret.txt");
	ofstream output("cipher12.txt");
	ofstream keyfile("keyfile.txt");


	string sentence;

	int randnum1, randnum2, counter1 = 0, modnum, counter2 = 0;
	char letter;


	char *ptr;

	srand(time(0));

	char arr[] = { 'a','b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', };

	int arr1[] = { 3,5,7,9,11,15,17 };

	int arr2[] = { 9,21,15,3,19,7,23 };

	randnum1 = rand() % 26;
	randnum2 = rand() % 7;


	keyfile << randnum1 << '\t' << randnum2;

	while (getline(input, sentence))
	{
		while (sentence[counter1] != '\0')
		{
			counter1++;
		}
	}

	input.clear();
	input.seekg(0, ios::beg);
	ptr = new char[counter1];


	while (getline(input, sentence))
	{
		while (sentence[counter2] != '\0')
		{
			ptr[counter2] = sentence[counter2];
		}
	}
	counter2 = 0;

	while (counter2 < counter1)
	{
		for (int i = 0; i < 26; i++)
		{
			if (toupper(ptr[counter2]) == toupper(arr[i]))
			{
				modnum = (i*arr1[randnum2]) % 26;    //multiplicative cipher   
				modnum = (modnum + randnum1) % 26;   //additive cipher
				ptr[counter2] = arr[modnum];
				counter2++;


				break;
			}
		}
		output << ptr[counter2];
		counter2++;
	}

	return 0;
}