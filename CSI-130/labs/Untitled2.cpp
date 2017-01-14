#include <iostream>
using namespace std;

int main()
{
	int num1, num2, a[6] = { 0 }, b[6] = { 0 }, c[6] = { 0 }, carry = 0, i = 0;
	char ch;

	cout << "'+' to ADD 2 numbers." << endl;
	cout << "'a' to AND 2 numbers." << endl;
	cout << "'o' to OR 2 numbers." << endl;
	cout << "'q' to quit the program." << endl << endl << ">";
	cin >> ch;

	cout << "Enter your first number: ";
	cin >> num1;
	cout << "Enter your second number: ";
	cin >> num2;
	if (ch != 'q')
	{

		//saving num1 to array a
		i = 5;
		for (i = 5; i >= 0; i = i - 1)
		{
			a[i] = num1 % 10;
			num1 = num1 / 10;
		}
		//saving num2 to array b
		i = 5;
		for (i = 5; i >= 0; i = i - 1)
		{
			b[i] = num2 % 10;
			num2 = num2 / 10;
		}

		//begin adding operation
		if (ch == '+')
		{
			i = 5;
			for (i = 5; i >= 0; i = i - 1)
			{
				c[i] = a[i] + b[i] + carry;

				//checking value of c[i]
				if (c[i] == 3)
				{
					c[i] = 1;
					carry = 1;

				}
				else if (c[i] == 2)
				{
					c[i] = 0;
					carry = 1;

				}
				else if (c[i] == 1)
				{
					c[i] = 1;
					carry = 0;
				}
				else if (c[i] == 0)
				{
					c[i] = 0;
					carry = 0;
				}

			}
			cout <<"Answer: "<< c[1] << c[2] << c[3] << c[4] << c[5] << endl;;
		}

	}
}





