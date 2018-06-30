#include <iostream>

using namespace std;


int main()

{
	int a,a1,b, b1, t1 = 0, t2 = 1, t, r, q, mod;
	mod = 0;



	cout << "Please enter the first number: ";
	cin >> a;
	a1 = a;

	cout << endl <<"Please enter the modulus: ";
	cin >> b;
	b1 = b;


	while (b >= 0)
	{
		q = a / b;
		r = a - q*b;
		a = b;
		b = r;
		t = t1 - q*t2;
		t1 = t2;

	}
	
	if (a == 1)      //GCD has to be '1' in order for there to be a multiplicative inverse
	{
		if(t1<0)
		{
			mod = (t1%a1) + a1;


		
	}

	else {
		mod = t1%a1;
		
		}
	}

	cout << "The multiplicative inverse of " << b << " is: " << mod << endl;
	system("pause");
}

