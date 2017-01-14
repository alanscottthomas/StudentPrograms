#include <iostream>
#include <fstream>
#include <ctype.h>

using namespace std;

int main()
{
	char c[1000];

	ifstream ifp;
	ofstream ifp2;
	int cnt_alpha = 0, cnt_num = 0, cnt_punc = 0, i = 0;

	//opening input.dat
	ifp.open("C:\\input.dat");
	ifp2.open("C:\\output.dat");
	if (!ifp)
		cout << "No Such File";

	//reading input.dat into char array ifp
	while (ifp.getline(c, 1000))
	{
		cout << c;
	}
	cout << endl;

	//looping c till # character
	i = 0;
	while (c[i] != '#')
	{
		if (isalpha(c[i]))
		{
			++cnt_alpha;
		}
		else if (ispunct(c[i]))
		{
			++cnt_punc;
		}
		else if (isdigit(c[i]))
		{
			++cnt_num;
		}
		++i;
	}
	cout <<"Alpha characters: "<< cnt_alpha << endl;
	cout <<"Digits: "<< cnt_num << endl;
	cout <<"Punctuation: "<< cnt_punc << endl;
	cout << endl << endl;
	ifp2 << "Alpha characters: " << cnt_alpha << endl;
	ifp2 << "Digits: " << cnt_num << endl;
	ifp2 << "Punctuation: " << cnt_punc << endl;
	ifp2 << endl << endl;
	ifp2.close();
	ifp.close();
	return 0;
}