#include <iostream>
#include<string>

using namespace std;



int main()
{
	char arr[4][4];
	char array2[16];
	int rem;

	string sentence;

	int counter1 = 0, counter2 = 0, counter3 = 0, counter4 = 0;

	cout << "Enter the secret message: ";
	getline(cin, sentence);

	//populate array with non-space characters//
	while (sentence[counter1] != '\0')
	{
		if (sentence[counter1] == ' ')
		{
			counter1++;
		}
		else {
				array2[counter2] = sentence[counter1];


				counter1++;
				counter2++;
			}
		}

	rem = 16 - counter2;
	if (rem > 0)
	{
		for (int i = counter2; i < counter2 + rem; i++)
		{
			array2[i] = '-';
		}
	}

	//write to the array by row
	for (int i= 0; i < 4; i++)
	{
		for (int j = 0; i < 4; i++)
		{
			arr[i][j] = array2[counter3];
			counter3++;
		}
	}
	
	
	//cipher is reading back by column
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; i < 4; j++)
		{
			counter4++;
			cout << arr[j][i];
			
			if (counter4 % 4 == 0)
			{
				cout << endl;
			}
		}
	}
	system("pause");
	return 0;
	}



	
