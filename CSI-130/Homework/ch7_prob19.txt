//Alan Thomas CSI 130 P7-38 Problem#19
#include <iostream>
using namespace std;

int High_low(float x)
{
	float ans;
	ans = (2 * x*x*x*x*x) - (4 * x*x*x) + (5 * x) - 8;
	return ans;
}

int main()
{
	float x;
	cout << "Enter 3 intergers:" << endl;
	cin >> x;
	High_low(x);
	x = High_low(x);
	cout << x;
	return 0;
}