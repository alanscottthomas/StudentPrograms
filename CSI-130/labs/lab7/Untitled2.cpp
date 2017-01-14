#include <iostream>
using namespace std;

int main()
{
	int mm[8] = { 0 }, num=0, i = 0, pc = 0;
	char ans;
	
	//menu
	cout << "Type '1' to enter instructions in 8 bit binary code." << endl;
	cout << "Type '2' to enter instructions in decimal form." << endl;
	cout << "Type '3' to print memory." << endl;
	cout << "Type '4' to exit the program." << endl;
	cin >> ans;

	while (ans != '4')
	{
		
		//instructions to add 8bit binary number to mm array
		/*
        if (ans == '1')
		{
			cout << "Enter instructions in a 8 bit binary code." << endl;
			cin >> num;
			i = 7;
			for (i = 7; i >=0; i = i - 1)
			{
				mm[pc][i] = num % 10;
				num = num / 10;
			}
			pc = pc + 1;
		}
	*/
		/*
		//instructions for decimal into array
		if (ans == '2')
		{
			cout << "Enter opcode in 0-3 digit decimal form." << endl;
			num = 0;
			cin >> num;
			i = 2;
			for (i = 2; i >= 0; i = i - 1)
			{
				mm[pc][i] = num % 2;
				num = num / 2;
			}
			i = 7;
			cout << "Enter number 0-15 digit decimal form." << endl;
			num = 0;
			cin >> num;
			for (i = 7; i >= 4; i = i - 1)
			{
				mm[pc][i] = num % 2;
				num = num / 2;
			}
			pc = pc + 1;
		}
		*/
		
		//print values from mm array
		if (ans == '3')
		{
			
			
			i = 0;
				for (i = 0; i < 8; i=i+1)
				{
				cout << mm[i];
				}
			cout<<endl;
			
		}
		cout << "Type '1' to enter instructions in 8 bit binary code." << endl;
		cout << "Type '2' to enter instructions in decimal form." << endl;
		cout << "Type '3' to print memory." << endl;
		cout << "Type '4' to exit the program." << endl;
		cin >> ans;
	}






	return 0;

}
