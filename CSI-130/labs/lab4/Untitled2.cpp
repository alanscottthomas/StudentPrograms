#include <iostream>
using namespace std;

int main()
{
	float ans;
	int num1, num2, num3, num4, num5, num6;
	
	cout << "Enter 6 numbers:" << endl;
	cin >> num1 >> num2 >> num3 >> num4 >> num5 >> num6;
	ans = (num1+num2+num3+num4+num5+num6)/6.0;
	
	// if statements
	if (ans > 60 && ans < 70)
		cout << "That's middle" << endl;
 	else if (ans > 70 && ans < 80)
		cout << "High" << endl;
	 else if(ans < 50 && ans > 20)
		cout << "Low" << endl;
 	else if (ans > 0 && ans < 19 || ans > 80 && ans < 100)
		cout << "Wow" << endl;
return 0;
}
