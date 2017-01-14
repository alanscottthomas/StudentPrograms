#include <iostream>
using namespace std;

int main()
{
	int num = 0, ans = 0, pow = 1, i = 0;
	int b[5] = { 0 };

	//get two's number as input
	cout << "Enter a 5 digit Twos Complement Number" << endl << "Your Number: ";
	cin >> num;
	
	//number to binary form...
	i = 4;
	for (i = 4; i >= 0; i = i - 1)
	{
		b[i] = num % 10;
		num = num / 10;
	}

	//converting to decimal form
	i = 4;
	pow = 1;
	ans = 0;
	for (i = 4; i >= 0; i = i - 1)
	{
		ans = ans + b[i] * pow;
		pow = pow * 2;
	}

	i = 0;
	for (i = 0; i >= 0; i = i - 1)
	{
		ans = ans - (b[i] * pow);
		
	}
	
	cout << endl;
	cout << "Decimal Form: " << ans << endl;


	return 0;

}
