#include <iostream>
using namespace std;

int main()
{
	int n[10], i = 0;
	//asking user for input to fill indices
	i = 0;
	for (i = 0; i<10; i = i + 1)
	{
		n[i]=i;
	}
	//print indices in reverse order
	i = 9;
	for (i = 9; i >= 0; i = i - 1)
	{
		cout << n[i] << endl;
	}
	return 0;
}

