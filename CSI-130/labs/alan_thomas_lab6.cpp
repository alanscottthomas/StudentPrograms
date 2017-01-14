//Alan Thomas CSI 130-01CA LAB6 10/03/2014
#include <iostream>
using namespace std;

int main(){
	//variable declarations. Made array size 6 to eliminate
	int num1, num2, a[5], b[5], c[5], carry = 0, i = 0;
	char ch;
    //Menu for user
	cout << "Type '+' to ADD 2 binary numbers." << endl;
	cout << "Type 'a' to AND 2 binary numbers." << endl;
	cout << "Type 'o' to OR 2 binary numbers." << endl;
	cout << "Type 'q' to quit the program." << endl << endl << ">";
	cin >> ch;

	//checking value of ch
	while (ch != 'q')
		{
		cout << "Enter a 4-bit binary numer: ";
		cin >> num1;
		cout << "Enter a 4-bit binary numer: ";
		cin >> num2;
		//saving num1 to array a
		i = 4;
		for (i = 4; i >= 0; i = i - 1)
		{
			a[i] = num1 % 10;
			num1 = num1 / 10;
		}
		//saving num2 to array b
		i = 4;
		for (i = 4; i >= 0; i = i - 1)
		{
			b[i] = num2 % 10;
			num2 = num2 / 10;
		}

		//begin adding operation
		if (ch == '+')
		{
			i = 4;
			for (i = 4; i >= 0; i = i - 1)
			{
				c[i] = a[i] + b[i] + carry;

				//checking value of c[i] for carry over operation
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
			//printing binary value of num1+num2
			cout << "The answer is: " << c[0] << c[1] << c[2] << c[3] << c[4] << endl << endl;
		}
		//AND operation begins
       if (ch == 'a')
		{
			if ((a[1] + a[2] + a[3] + a[4] == 0) && (b[1] + b[2] + b[3] + b[4] == 0))
			{
				cout << "AND is False" << endl << endl;
            }
			else
			{
				cout << "AND is True" << endl << endl;
			}
		}
		//OR operation begins
		if (ch == 'o')
		{
			if ((a[1] + a[2] + a[3] + a[4] != 0) || (b[1] + b[2] + b[3] + b[4] != 0))
			{
				cout << "OR is True" << endl << endl;
			}
			else
			{
				cout << "OR is False" << endl << endl;
			}
   
   
   }
		//Redisplaying menu for user to compare value of ch
		cout << "Type '+' to ADD 2 binary numbers." << endl;
		cout << "Type 'a' to AND 2 binary numbers." << endl;
		cout << "Type 'o' to OR 2 binary numbers." << endl;
		cout << "Type 'q' to quit the program." << endl << endl << ">";
		cin >> ch;
	
    
    }
	return 0;
}




