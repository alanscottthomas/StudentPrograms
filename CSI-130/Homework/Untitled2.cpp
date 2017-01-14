//Alan Thomas CSI130-01CA p4-30 Problem#15
#include <iostream>
//#include <iomanip>
using namespace std;

int main()
{
	//using long long to eliminate garbage in last fib numbers
	//array size set to 53 to eliminate out of bounds error.
	//Used 2 arrays for the fib numbers to increase readability.Eliminated scientific notation and provided float for division. 
	int i, j;
	float f[53] = { 0, 1 };
    float ans = 0, h[53] = { 0, 1 };
	
	//fib sequence begins
	i = 0;
	j = 0;
	for (i = 0; i <= 50; i = i + 1)
	{
		f[i + 2] = f[i] + f[i + 1];
		h[i + 2] = h[i] + h[i + 1];
		cout << "Fib#" << j <<": "<< f[i] << endl;
		j = j + 1;
	}
	
	//fib numbers in reverse order
	cout << endl << endl << endl << "Fibonacci numbers in reverse:"<<endl;
	i = 50;
	j = 50;
	for (i = 50; i >= 0; i = i - 1)
	{
		cout << "Fib#" << j << ": " << f[i] << endl;
		j = j - 1;
	}
	
	//dividing fib numbers
	cout << endl << endl << endl << "Fibonacci numbers divided:" << endl;
	i = 2;
	for (i = 2; i <= 50; i = i + 1)
	{
		ans = h[i]/h[i-1];
		//cout << setprecision(30);
		//Precision is set to 6 digits by default. Uncommenting the header and setprecision would allow for more digits in this division problem.
		cout << ans << endl;
		}	
system("PAUSE");
	return 0;
}
