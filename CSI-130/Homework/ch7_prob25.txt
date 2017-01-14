//Alan Thomas CSI 130 P7-38 Problem#25
#include <iostream>
using namespace std;

void High_low(int &a, int &b, int &c)
{
	int temp;
	if (a<b)
	{
		temp = a;
		a = b;
		b = temp;
	}
	if (a < c)
	{
		temp = a;
		a = c;
		c = temp;
	}
	if (b < c)
	{
		temp = b;
		b = c;
		c = temp;

	}

}

int main()
{
	int a, b, c;
	cout << "Enter 3 intergers:" << endl;
	cin >> a >> b >> c;
	High_low(a, b, c);
	cout << a << " " << b << " " << c << endl;

	return 0;
}