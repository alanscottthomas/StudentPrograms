#include <iostream>
#include <string>

using namespace std;

int main()
{

	int arr[] = { 1,3,5,7,9,11,15,17,19,21,23,25 };

	for (int i = 0; i < 12; i++)
	{
		for (int j = 0; j < 12; j++)
		{
			if (arr[i] == arr[j])
			{
				continue;
			}
			if ((arr[i] * arr[j]) % 26 == 1)
			{
				cout << arr[i] << " " << arr[j] << endl;
			}
		}
	}
	system("pause");
}
