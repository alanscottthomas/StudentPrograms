//Alan Thomas / CSI 130 / LAB07 /10-09-14
#include <iostream>
using namespace std;

int main()
{
	int mm[256][8] = { { 0 } }, num=0, pc=0, i=0,pc_orig=0,j=0;
	char ans;

			cout << "8888ba.88ba           oo" << endl;
			cout << "88  `8b  `8b" << endl;
			cout << "88   88   88 .d8888b. dP 88d888b." << endl;
			cout << "88   88   88 88'  `88 88 88'  `88" << endl;
			cout << "88   88   88 88.  .88 88 88    88" << endl;
			cout << "dP   dP   dP `88888P8 dP dP    dP" << endl;


			cout << "8888ba.88ba" << endl;
			cout << "88  `8b  `8b" << endl;
			cout << "88   88   88 .d8888b. 88d8b.d8b. .d8888b.  88d888b.dP    dP" << endl;
			cout << "88   88   88 88ooood8 88'`88'`88 88'  `88 88' `88  88    88" << endl;
			cout << "88   88   88 88.  ... 88  88  88 88.  .88 88       88.  .88" << endl;
			cout << "dP   dP   dP `88888P' dP  dP  dP `88888P' dP       `8888P88" << endl;
			cout << "                                                       .88" << endl;
			cout << "                                                    d8888P" << endl;
			cout << "                                                              simulator....." << endl << endl << endl << endl;
	
	
	//Prompting user with a menu
	cout << "Type '1' to enter IS in a 8 bit binary code." << endl;
	cout << "Type '2' to enter IS in decimal form." << endl;
	cout << "Type '3' to print memory." << endl;
	cout << "Type '4' to exit the program." << endl;
	cout << ">";
	cin >> ans;
	//checking value of ans
	while (ans != '4')
	{
		//instructions to add 8bit binary number to mm array
		if (ans == '1')
		{
			cout << "Enter instructions in a 8 bit binary code." << endl << ">";
			cin >> num;
			i = 7;
			for (i = 7; i >=0; i = i - 1)
			{
				mm[pc][i] = num % 10;
				num = num / 10;
			}
			pc = pc + 1;
		}
		//instructions to change decimal into binary than into array mm
		if (ans == '2')
		{
			//getting opcode from user
			cout << "Enter an opcode 0-7 in decimal form." << endl << ">";
			num = 0;
			cin >> num;
			i = 2;
			for (i = 2; i >= 0; i = i - 1)
			{
				mm[pc][i] = num % 2;
				num = num / 2;
			}
			i = 7;
			//getting number from user
			cout << "Enter a number 0-15, in decimal form." << endl << ">";
			num = 0;
			cin >> num;
			for (i = 7; i >= 4; i = i - 1)
			{
				mm[pc][i] = num % 2;
				num = num / 2;
			}
			pc = pc + 1;
		}
		//print values from mm array
		if (ans == '3')
		{	//saving pc to pc_orig as to not overwrite pc's value
			pc_orig = pc;
			for (pc_orig = 0; pc_orig < 256;pc_orig=pc_orig+1)
			{
				cout << endl<<"LN#" << j << " in MM: ";
				j = j + 1;
				for (i = 0; i < 8; i=i+1)
				cout << mm[pc_orig][i];
			}
			cout << endl;
		}
		//setting counter for lines to 0
		j = 0;
		//reprinting menu and getting ans again
		cout << "Type '1' to enter IS in a 8 bit binary code." << endl;
		cout << "Type '2' to enter IS in decimal form." << endl;
		cout << "Type '3' to print memory." << endl;
		cout << "Type '4' to exit the program." << endl;
		cout << ">";
		cin >> ans;
	}
	return 0;
}
