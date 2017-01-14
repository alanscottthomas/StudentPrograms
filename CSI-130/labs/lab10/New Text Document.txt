#include <iostream>
#include <string>

using namespace std;

struct SymTab{
	string identifier;
	int address;
};

int main()
{
	SymTab st[25];
	int Adder = 255, i = 0, k = 0, ans, flag = 0;
	string userio;

	cout << "1-Input value to array | 2-Check for string | 3-Quit" << endl;
	cin >> ans;
	while (ans != 3)
	{
		if (ans == 1)
		{
			cout << "Enter a value to input into the array" << endl << ">";
			cin >> st[i].identifier;
			st[i].address = Adder;
			
			++i;
			--Adder;

		}
		else if (ans == 2)
		{
			cout << "Enter a string to search for: ";
			cin >> userio;
			
			for (k = 0; k <i; ++k)
			{
				if (userio == st[k].identifier)
					cout << "Identifier: " << st[k].identifier << endl;
				cout << "Address: " << st[k].address << endl;
				cout << "Identifier: " << k << endl;

				
			}

		}
			cout << "1-Input value to array | 2-Check for string | 3-Quit" << endl;
			cin >> ans;

		}
		}