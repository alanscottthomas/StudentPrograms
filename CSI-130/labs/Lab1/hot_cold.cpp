#include <iostream>
using namespace std;

int main()
{
	int c = 0, f = 0;
	cout << "Enter a degree in Farenheit: " << endl;
	cin >> f;
	c = (f-32) * 5/9;
	
	if (c <= 0){
	cout << "Freezing";
}
	else if (c <= 10){
	cout << "Cold";
}
	else if (c <= 18){
	cout << "Cool";
}
	
	else if (c <= 28) {
	cout << "Warm";
}
	else{
	cout << "Hot";
}
}

