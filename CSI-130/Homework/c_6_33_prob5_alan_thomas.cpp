/*
Alan Thomas
CSI 130
Chapter6-33 Question#5
*/
#include <iostream>
using namespace std;

struct comparerator{
	int a, b, z, ap;
};

int main()
{
	comparerator comp[110];
	int i = 0, j = 0, count = 0;

	//setting b values
	j = -50;
	i = 0;
	for (i = 0; i <= 100; ++i)
	{
		comp[i].b = j;
		++j;
	}
	//setting z values
	j = 1;
	i = 0;
	for (i = 0; i <= 50; ++i)
	{
		comp[i].z = j;
		++j;
	}
	//setting a
	j = 1;
	i = 0;
	for (i = 0; i <= 50; ++i)
	{
		comp[i].a = j;
		++j;
	}

	//setting Ap
	comp[0].ap = 2, comp[1].ap = 3, comp[2].ap = 5, comp[3].ap = 7, comp[4].ap = 11, comp[5].ap = 13, comp[6].ap = 17, comp[7].ap = 19, comp[8].ap = 23, comp[9].ap = 29, comp[10].ap = 31,
		comp[11].ap = 37, comp[12].ap = 41, comp[12].ap = 43, comp[13].ap = 47;


	//comparing A and B for intersections
	j = 0;
	i = 0;
	cout << "A and B intersections = {";
	for (i = 0; i <= 100; ++i)
		for (j = 0; j <= 100; ++j)
		{
		if (comp[i].a == comp[j].b)
		{
			cout << comp[i].a << ",";
		}
		}
	cout << "}" << endl;
	cout << "PRESS A KEY TO CONTINUE\n";
	cin.get();
	cin.clear();

	//comparing A and B for union
	j = 0;
	i = 0;
	cout << "A and B union = {";
	for (i = 0; i <= 100; ++i)
	{
		if (comp[i].a == comp[i].b)
		{
			cout << comp[i].a << ",";
		}
		else if (comp[i].a != comp[i].b)
		{
			cout << comp[i].b << ",";
		}
	}
	cout << "}" << endl;
	cout << "PRESS A KEY TO CONTINUE\n";
	cin.get();
	cin.clear();
	cout << endl << endl;






	//comparing Ap and |B|3 for union
	i = 0;
	j = 48;
	cout << "Relation Ap X |B|3 = {";
	for (i = 0; i < 14; ++i)
	{
		for (j = 48; j< 53; ++j)
		{
			cout << "(" << comp[i].ap << "," << comp[j].b << ") ,";

		}
	}
	cout << "}"<<endl;
	cout << "PRESS A KEY TO CONTINUE\n";
	cin.get();
	cin.clear();
	return 0;
}

