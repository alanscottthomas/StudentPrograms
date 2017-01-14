//Alan Thomas CSI 130 Lab 12:C++ Functions 11/19/2014

#include <iostream>
using namespace std;
//alphabetic ordering function
void Order()
{
	char a, b, c;
	cout << "Input three characters: " << endl;
	cin >> a >> b >> c;
	char temp;
	if (a>b)
	{
		temp = a;
		a = b;
		b = temp;
	}
	if (a > c)
	{
		temp = a;
		a = c;
		c = temp;
	}
	if (b > c)
	{
		temp = b;
		b = c;
		c = temp;
	}
	cout << "Your letters in order: " << a << " " << b << " " << c << endl << endl;
}
//binary conversion function
void Conversion()
{
	int ans, arr[8] = { 0 }, i = 0, power = 1,ans2=0;
	cout << "Enter a number between 0-255: ";
	cin >> ans;
	cout << endl << endl;
	cout << "The users original number: " << ans << endl;
	//converting answer to binary
	i = 0;
	for (i = 0; i <= 7; i++)
	{
		arr[i] = ans % 2;
		ans = ans / 2;
	}
	//printing binary number
	cout << "Your number in binary is: ";
	i = 7;
	for (i = 7; i >= 0; --i)
		cout << arr[i];
	cout << endl;
	//converting binary number to decimal form
	i = 0;
	power = 1;
	ans = 0;
	while (i <= 7)
	{
		ans = ans + arr[i] * power;
		power = power * 2;
		++i;
	}
	cout << "Binary to deciaml: " << ans << endl << endl << endl;;
	
}
//number adding function
void Escalate(int x)
{
	int num = 1,i=1;
	
	for (i = 1; i < x; ++i)
	{
		num = num + i;
	}
	--num;
	num = num + x;;
	cout << endl;
	cout << "Your number (" << x << ") combined with integers inbetween: " << num << endl << endl;
	}
//function to calculate volume
float Volume(float l, float h, float w)
{
	float ans = 0.0;
	ans = l*h*w;
	return ans;
}
//main function
int main()
{
	int ans, a = 0;
	float l = 0, h = 0, w = 0,ans2=0;
	//printing menu for user
	cout << "|1-Alpha Ordering|2-Binary Conversion|"<<endl<<"|3-Number Escalation|4-Volume Calculator|0-Quit|" << endl;
	cin >> ans;
	//checking answer against 0
	while (ans != 0)
	{
		if (ans == 1)
			Order();
		else if (ans == 2)
			Conversion();
		else if (ans == 3)
		{
			cout << "Enter a number: ";
			cin >> a;
			Escalate(a);
		}
		else if (ans == 4)
		{
			cout << "Enter Your length, height and width to determine volume: ";
			cin >> l >> h >> w;

			ans2 = Volume(l, h, w);
			cout << "Your volume is: " << ans2 << endl << endl;

		}
		//reprinting menu for user
		cout << "|1-Alpha Ordering|2-Binary Conversion|" << endl << "|3-Number Escalation|4-Volume Calculator|0-Quit|" << endl;
		cin >> ans;
	}
	
	return 0;
}