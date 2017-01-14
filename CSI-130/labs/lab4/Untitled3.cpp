#include <iostream>
using namespace std;

int main()
{
	float num, sum;
	
		cout << "Enter your numbers: " << endl;
		cin >> num;
		sum = sum + num;
	
	while ( sum < 100 && num >= 0)
{	
		cout << "Enter your numbers: " << endl;
		cin >> num;
		sum = sum + num;
}

cout <<"Your sum is:" << sum << endl;
return 0;		
	

}
