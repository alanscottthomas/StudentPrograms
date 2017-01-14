//Alan Thomas
//Assignment#2 1/30/2015
//Chapter4 Problem 22 Part1
#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>

using namespace std;
//global variable for the customers name
string first_name, last_name;


//Package A function
void package_a(){
	int hours = 0;
	float bill = 0.0;
	ofstream myfile ("bill.txt");
    int main();
	cout << "How many hours were used this month: ";
	cin >> hours;
	while (hours > 744){
		cout << "Hours exceeded." << endl;
		cout << "How many hours were used this month: ";
		cin >> hours;
	}
	hours = hours - 10;
	bill = (hours*2.00) + 9.95;
	cout << first_name << " " << last_name << " used " << hours + 10 << " hours of internet and has a bill of $" << bill << " this month." << endl;
    myfile << first_name << " " << last_name << " used " << hours + 10 << " hours of internet and has a bill of $" << bill << " this month." << endl;
	myfile.close();
    system("PAUSE");
	main();
}
//Package B function
void package_b(){
	int hours = 0;
		ofstream myfile ("bill.txt");
    float bill = 0.0;
	int main();
	cout << "How many hours were used this month: ";
	cin >> hours;
	while (hours > 744){
		cout << "Hours exceeded." << endl;
		cout << "How many hours were used this month: ";
		cin >> hours;
	}
	hours = hours - 20;
	bill = (hours*1.00) + 14.95;
	cout << first_name << " " << last_name << " used " << hours + 20 << " hours of internet and has a bill of $" << bill << " this month." << endl;
	myfile << first_name << " " << last_name << " used " << hours + 20 << " hours of internet and has a bill of $" << bill << " this month." << endl;
	myfile.close();
    system("PAUSE");
	main();
}
//Package C function
void package_c(){
	int main();
	ofstream myfile ("bill.txt");
    cout << first_name << " " << last_name << " is using the C package which is a flat rate of $19.95 a month."<<endl;
    myfile << first_name << " " << last_name << " is using the C package which is a flat rate of $19.95 a month."<<endl;
	myfile.close();
    system("PAUSE");
	main();
}
//Main function
int main(){
	char package;
	//Prompting user for name and package
	cout << "Please enter the customers first and last name: ";
	cin >> first_name >> last_name;
	cout << endl << "Please enter the package option(A,B,C)or 'Q' to quit: ";
	cin >> package;
	//changing input to upper
	package = (char)toupper(package);
	//while loop to ensure an operate package is selected
	while (!(package == 'B' || package == 'A' || package == 'C' || package == 'Q')){
		cout << "Invalid Input";
		cin.clear();
		cin.ignore();
		cout << endl << "Please enter the package option(A,B,C): ";
		cin >> package;
		package = (char)toupper(package);
	}
	//if statements to bring user to appropiate package function
	if (package == 'A'){
		package_a();
	}
	if (package == 'B'){
		package_b();
	}
	if (package == 'C'){
		package_c();
	}
	if (package == 'Q'){
		return 0;
	}
}

