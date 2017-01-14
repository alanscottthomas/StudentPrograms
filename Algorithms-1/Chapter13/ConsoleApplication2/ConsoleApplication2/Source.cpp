#include <iostream>
using namespace std;

int Function1(int a, int& b) {
	int c = 3;
	a += c;
	b -= c;
	return a;
}

void Function2(int i) {
	i = i + 5;
	cout << "F2:" << i << " ";
}



int main()
{
	int a = 5, b = 10, c;
	while (b > 0) {
		Function2(b);
		b -= 4;
	}


	return 0;
}

