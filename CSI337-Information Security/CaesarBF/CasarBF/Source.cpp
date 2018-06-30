#include <iostream>



using namespace std;


int main()
{
	char arr[] = { 'a','b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', };


	string sentence = "UVACLYFZLJBYL";

	int shift[] = { 1,2,3,4,5,6,7,8,9,10 };

	int counter1 = 0, modnum, counter2 = 0, counter3 = 0;



	for (int k = 0; k < 10; k++)
	{
		counter1 = 0;
		while (sentence[counter1] != '\0')
		{
			for (int i = 0; i < 26; i++)
			{
				if (sentence[counter1] == toupper(arr[i]))
				{

					for (int j = 0; j <= 10; j++)
					{
						modnum = (i - shift[j]) % 26;
						if (modnum < 0)
						{
							modnum += 26;
						}

						sentence[counter1] = arr[modnum];
						cout << sentence[counter1];
						break;



					}
					counter1++;
				}


			}

		}
	}
	system("pause");
	}
	







