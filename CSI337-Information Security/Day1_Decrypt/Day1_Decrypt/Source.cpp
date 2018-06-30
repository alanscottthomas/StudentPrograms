//caesar
#include <iostream>
#include <fstream>	
#include <string>


using namespace std;


int main()
{
	ifstream input("cipher.txt");
	ofstream output("decrypt.txt");
	int counter = 0;
	char letter;

	string sentence;

	while (input >> sentence)
	{
		while (sentence[counter] != '\0')
		{
			letter = sentence[counter];
			letter -= 3;
			sentence[counter] = letter;
			counter++;
		}
		output << sentence;

	}





	input.close();
	output.close();
	return 0;
}