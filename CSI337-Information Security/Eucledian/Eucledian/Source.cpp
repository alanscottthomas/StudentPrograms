#include <iostream>


using namespace std;





int main()
{




	int a, n, r=1, a1, n1;        //a1 and n1 original values

	//get dividened//
	cout << "Enter the dividended as a positive int. only: ";
	cin >> a;
	while (cin.fail()) {
		cin.clear();
		cin.ignore(300,'\n');
		cout << "Enter the dividended as a positive int. only: ";
		cin >> a;
	}

	
	//get divisor//
	cin.ignore(300, '\n'); //skipping ahead in buffer incase user submitted float
	cout << "Enter number of divisor as a positive int only: ";
	cin >> n;
	while (cin.fail() || n <= 0) {
		cin.clear();
		cin.ignore(300, '\n');
		cout << "Enter number of divisor as a positive int only: ";
		cin >> n;
	}
	//-------------//
	a1 = a;
	n1 = n;


	while (r > 0)
	{
		r = a%n;

		a = n;
		n = r;
	}

	cout << "GCD of " << a1 << " and " << n1 << "is:" << a<<endl<<endl;

	if (a == 1)
	{
		cout << a1 << " and " << n1 << " are prime";
	}
	system("pause");
	return 0;

}