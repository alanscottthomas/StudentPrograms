#include <iostream>
#include <string>
using namespace std;

int main()
{
	int acc[5] = { 0 }, ir[8] = { 0 }, pc = 0, mdr[8] = { 0 }, mar[8] = { 0 },
		ram[256][8] = { { 0 } }, opcode=0, operand = 0, i = 0, j = 0,
		carry = 0, idadd = 0, power = 1, pc_orig = 0, flag = 0, sop, soper;

	string opcode_string;
	opcode_string = "";

	//**************Printing the menu options for the user**************
	cout << "______________________________________" << endl;
	cout << "|      H.E.A.D.A.C.H.E. v1.0         |" << endl;
	cout << "|____________________________________|" << endl;
	cout << "| Highly Effective(ish) Arithmetic   |" << endl;
	cout << "|   Data Aggregator Computational    |" << endl;
	cout << "|       Hardware Enhancer            |" << endl;
	cout << "|____________________________________|" << endl << endl << endl;
	cout << "--Below are your options for the central processor simulator--" << endl;
	cout << "Enter a '0' or HALT to HALT" << endl;
	cout << "Enter a '1' or LOAD to LOAD IMMEDIATE" << endl;
	cout << "Enter a '2' or STORE to STORE DIRECT" << endl;
	cout << "Enter a '3' or LDID to LOAD INDRECT" << endl;
	cout << "Enter a '4' STID to STORE INDIRECT" << endl;
	cout << "Enter a '5' ADD to ADD" << endl;
	cout << "Enter a '6' CMPE to COMPARE" << endl;
	cout << "Enter a '7' or JMPE to JMPNE" << endl << endl << endl << "BEGIN CODE: ";
	//Getting opcode from user
	cin >> opcode_string;
	if (opcode_string == "HALT")
		opcode = 0;
	if (opcode_string == "LDID")
		opcode = 3;
	if (opcode_string == "CMPE")
		opcode = 6;
	if (opcode_string == "LDIM")
		opcode = 1;
	if (opcode_string == "STID")
		opcode = 4;
	if (opcode_string == "JMPNE")
		opcode = 7;
	if (opcode_string == "STORE")
		opcode = 2;
	if (opcode_string == "ADD")
		opcode = 5;
	sop = opcode;

	//**************storing opcodes and operands to ram array**************
	
	
	while (opcode != 0)
	{
		//options 3 and 4
		if (opcode == 3 || opcode == 4)
		{

			{//opcode and operand to binary conversion		

				pc_orig = pc;
				cout << "";
				cin >> operand;
				cout << "";
				cin >> idadd;

				soper = operand;
				sop = opcode;

			}
			if (opcode == 3)
			{
				i = 2;
				for (i = 2; i >= 0; i--)
				{
					ram[pc][i] = sop % 2;
					sop = sop / 2;
				}
				i = 7;
				for (i = 7; i >= 3; i--)
				{
					ram[pc][i] = soper % 2;
					soper = soper / 2;
				}
				i = 7;
				for (i = 7; i >= 0; i--)
				{
					ram[operand][i] = idadd % 2;
					idadd = idadd / 2;
				}
			}
			else if (opcode == 4)
			{
				i = 2;
				for (i = 2; i >= 0; i--)
				{
					ram[pc][i] = sop % 2;
					sop = sop / 2;
				}
				i = 7;
				for (i = 7; i >= 3; i--)
				{
					ram[pc][i] = soper % 2;
					soper = soper / 2;
				}
				i = 7;
				for (i = 7; i >= 0; i--)
				{
					ram[operand][i] = idadd % 2;
					idadd = idadd / 2;
				}

			}

		}




		//options 1-2-5-6-7
		//**************opcode to binary and store to mm**************
		else if (opcode == 1 || opcode == 2 || opcode == 5 || opcode == 6 || opcode == 7)
		{
			cout << "";
			cin >> operand;
			soper = operand;
			//opcode and operand to binary conversion
			i = 2;
			for (i = 2; i >= 0; i = i - 1)
			{
				ram[pc][i] = sop % 2;
				sop = sop / 2;
			}
			//operand to binary and store to ram
			i = 7;
			for (i = 7; i >= 3; i = i - 1)
			{
				ram[pc][i] = soper % 2;
				soper = soper / 2;
			}


		}
		//incrementing pc
		pc = pc + 1;
		//printing menu for user
		
		//Getting opcode from user
		cin >> opcode_string;
		if (opcode_string == "HALT")
			opcode = 0;
		if (opcode_string == "LDID")
			opcode = 3;
		if (opcode_string == "CMPE")
			opcode = 6;
		if (opcode_string == "LDIM")
			opcode = 1;
		if (opcode_string == "STID")
			opcode = 4;
		if (opcode_string == "JMPNE")
			opcode = 7;
		if (opcode_string == "STORE")
			opcode = 2;
		if (opcode_string == "ADD")
			opcode = 5;
		sop = opcode;
		//getting operand from user
	}



	//prompting user to press a key to print ram
	cout << endl << endl << "--PREPARING TO PRINT MAIN MEMORY--" << endl;
	system("PAUSE");

	//using pc_orig as to not overwrite actual PC value
	//printing main memory
	pc_orig = pc;
	for (pc_orig = 0; pc_orig < 256; pc_orig = pc_orig + 1)
	{
		cout << endl << "LN#" << j << " in RAM: ";
		j = j + 1;
		for (i = 0; i < 8; i = i + 1)
			cout << ram[pc_orig][i];
	}
	cout << endl;
	//resetting esthetic counter to 0
	j = 0;
	//halting execution till key press
	cout << "-Preparing to execute code-" << endl;
	system("PAUSE");









	//**************checking for HALT command in opcode**************
	j = 0;
	pc = 0;
	cout << endl << endl << "--EXECUTING CODE--";
	while (ram[pc][0] + ram[pc][1] + ram[pc][2] != 0)
	{
		for (i = 0; i < 8; i = i + 1)
			mdr[i] = ram[pc][i];
		for (i = 0; i < 8; i = i + 1)
			ir[i] = mdr[i];

		//Converting opcode to decimal
		i = 2;
		power = 1;
		opcode = 0;
		while (i >= 0)
		{
			opcode = opcode + ir[i] * power;
			power = power * 2;
			i = i - 1;
		}

		//**************(0)halt operation**************
		if (opcode == 0)
			cout << "Press any key to continue!";
		//**************(1)load indirect operation**************
		else if (opcode == 1)
		{
			//put last 5 bits of IR into ACC

			for (i = 0; i < 5; i = i + 1)
				acc[i] = ir[i + 3];
		}

		//**************(2) Store direct **************
		else if (opcode == 2)
		{
			//get address to store the contents of the add
			i = 7;
			power = 1;

			idadd = 0;
			while (i >= 3)
			{
				idadd = idadd + ir[i] * power;
				power = power * 2;
				i = i - 1;
			}
			//move contents of ACC to MDR
			for (i = 0; i < 5; i = i + 1)
				mdr[i + 3] = acc[i];
			//store contents of mdr in address idadd
			for (i = 0; i < 5; i = i + 1)
				ram[idadd][i] = mdr[i];
		}


		//**************(3)Load indirect**************
		else if (opcode == 3)
		{
			//get address
			i = 7;
			power = 1;
			idadd = 0;
			while (i >= 3)
			{
				idadd = idadd + ir[i] * power;
				power = power * 2;
				i = i - 1;
			}
			//get address of the operand
			i = 0;
			for (i = 0; i < 8; i = i + 1)
				mar[i] = ram[idadd][i];
			//converting address to decimal
			i = 7;
			power = 1;
			idadd = 0;
			while (i >= 0)
			{
				idadd = idadd + mar[i] * power;
				power = power * 2;
				i = i - 1;
			}
			//putting operand into MDR
			i = 0;
			for (i = 0; i < 8; i = i + 1)
				mdr[i] = ram[idadd][i];
			//put last 5 bits of MDR into ACC

			i = 0; for (i = 0; i < 5; i = i + 1)
				acc[i] = mdr[i + 3];

		}

		//**************(4)Store indirect**************
		else if (opcode == 4)
		{
			//get address
			i = 7;
			power = 1;

			idadd = 0;
			while (i >= 3)
			{
				idadd = idadd + ir[i] * power;
				power = power * 2;
				i = i - 1;
			}
			//get address to store value
			for (i = 0; i < 8; i = i + 1)
				mar[i] = ram[idadd][i];
			//converting address to decimal
			i = 7;
			power = 1;

			idadd = 0;
			while (i >= 0)
			{
				idadd = idadd + mar[i] * power;
				power = power * 2;
				i = i - 1;
			}
			//putting ACC into last 5 bits of MDR
			for (i = 0; i < 5; i = i + 1)
				mdr[i + 3] = acc[i];
			//put content of MDR into memory

			for (i = 0; i < 8; i = i + 1)
				ram[idadd][i] = mdr[i];
		}

		//**************(5)Add operation**************
		else if (opcode == 5)
		{
			carry = 0;
			i = 4;
			for (i = 4; i >= 0; i = i - 1)
			{
				acc[i] = ir[i + 3] + acc[i] + carry;
				if (acc[i] == 0 || acc[i] == 1)
					carry = 0;
				if (acc[i] == 2)
				{
					acc[i] = 0;
					carry = 1;

				}
				if (acc[i] == 3)
				{
					acc[i] = 1;
					carry = 1;
				}
			}
			acc[i] = carry + acc[i];
		}
		//**************(6)CMPE operation**************
		else if (opcode == 6)
		{
			i = 0;
			flag = 0;
			while (i < 5)
			{
				if (acc[i] != ir[i + 3])
				{
					flag = 1;
					i = i + 1;
				}
			}
			if (flag = 1)
				i = 0;
			for (i = 0; i < 5; i++)
				acc[i] = 0;

		}

		//****code portion for JMPNE operation*****
		else if (opcode == 7)
		{
			//comparing ACC to IR
			i = 0;
			flag = 0;
			while (i < 5)
			{
				if (acc[i] == ir[i + 3])
				{
					flag = 1;
				}
				i = i + 1;
			}
			//if statement to set PC to IR
			if (flag = 0)
			{
				i = 8;
				power = 1;
				pc = 0;
				while (i >= 5)
				{
					pc = ir[i] * power;
					power = power * 2;
					i = i - 1;
				}
			}
		}
		//printing registers(maybe(ish))

		cout << endl << endl;
		cout << "_________________" << endl;
		cout << "RAM#" << j << ": ";
		for (i = 0; i < 8; i = i + 1)
			cout << ram[pc][i];
		cout << endl;
		cout << "ACC: ";
		for (i = 0; i < 5; i = i + 1)
			cout << acc[i];
		cout << endl;
		cout << "MDR: ";
		for (i = 0; i < 8; i = i + 1)
			cout << mdr[i];
		cout << endl;
		cout << "MAR: ";
		for (i = 0; i < 8; i = i + 1)
			cout << mar[i];
		cout << endl;
		cout << "IR: ";
		for (i = 0; i < 8; i = i + 1)
			cout << ir[i];
		cout << endl;
		cout << "PC: ";
		cout << pc << endl;
		cout << "_________________" << endl;

		pc = pc + 1;
		j = j + 1;

	}
	cout << endl << "--EXECUTION COMPLETE--" << endl << "\a" << endl;
	system("PAUSE");
	//using pc_orig as to not overwrite actual PC value
	//printing main memory
	j = 0;
	pc_orig = pc;
	for (pc_orig = 0; pc_orig < 256; pc_orig = pc_orig + 1)
	{
		cout << endl << "LN#" << j << " in RAM: ";
		j = j + 1;
		for (i = 0; i < 8; i = i + 1)
			cout << ram[pc_orig][i];
	}
	cout << endl;
	system("PAUSE");
	return 0;
}


