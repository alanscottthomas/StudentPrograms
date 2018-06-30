#include <iostream>

using namespace std;



int main()
{
	int a, b, s1 = 1, s2 = 0, t1 = 0, t2 = 1, s, t, r, q;

	cout << "Please enter first number:";
	cin >> a;



	cout << endl << "Please enter second number";
	cin >> b;



	while (b > 0)
	{
		q = a / b;
		r = a - q*b;
		a = b;
		b = r;

		s = s1 - q*s2;
		s1 = s2;
		s2 = s;
		t = t1 - q*t2;

		
	}

	cout << endl << "The GCD is: " << a << endl;
	cout << "S is:" << s1 << endl;
	cout << "T is:" << t1 << endl;


	system("pause");
	return 0;





}