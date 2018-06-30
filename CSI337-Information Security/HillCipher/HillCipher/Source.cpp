#include <iostream>
using namespace std;


//Hill Cipher encryption portion//
int main()
{
	int total = 0, counter1 = 0, counter2 = 0, counter3 = 0, counter4 = 0;

	//plain text array//
	//this is a fact//
	int arr1[3][4] = { {19,7,8,18},
					{8, 18, 0, 5},
					{0,2,19,25} };



	//key array
	int arr2[4][4] = { {9,7,11,13},
					{4,7,5,6},
					{2,21,14,9},
					{3,23,21,8} };



	int cipher[3][4];

	while (counter1 < 3)
	{
		while (counter2 < 4)
		{
			total += arr1[counter1][counter2] * arr2[counter2][counter3];
			counter2++;
		}

		cipher[counter1][counter3] = total % 26;
		total = 0;
		counter3++;
		counter2 = 0;

		if (counter3 > 3)
		{
			counter3 = 0;
			counter1++;

		}
	}


	for (int i = 0; i< 3; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cout << cipher[i][j]<<" ";
			counter4++;
			if (counter4 % 4 == 0)
			{
				cout << endl;
			}
		}
	}



	system("pause");

return 0;
}