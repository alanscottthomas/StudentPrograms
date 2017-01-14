//Alan Thomas
//Assignment#2 1/30/2015
//Chapter4 Problem 22 Part2
#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>

using namespace std;
//global variable for the customers name
string first_name, last_name;


//Package A function
void package_a(){
	int hours = 0,hours_b=0;
	float bill = 0.0,bill_b=0.0,c=19.95,bill_copy=0.0;
	ofstream myfile ("bill.txt");
    int main();
	//begin asking for user input
    cout << "How many hours were used this month: ";
	cin >> hours;
	//checking to ensure hours doesn't exceed 744
    while (hours > 744){
		cout << "Hours exceeded." << endl;
		cout << "How many hours were used this month: ";
		cin >> hours;
	}
	//copying number of hours for B and C compare
    hours_b=hours-20;
	bill_b=hours*1.00+14.95;
    hours = hours - 10;
	bill = (hours*2.00) + 9.95;
	bill_copy = (hours*2.00) + 9.95;
         	//comparing bills to determine if they could save money
             if(bill>bill_b){
                    cout <<endl<< first_name << " " << last_name << " used " << hours + 10 << " hours of internet and has a bill of $" << bill << " this month." << endl;
	                myfile << first_name << " " << last_name << " used " << hours + 10 << " hours of internet and has a bill of $" << bill << " this month." << endl;
	                bill=bill-bill_b;
	                cout<<endl<<first_name<<" could have saved $"<<bill<< " if they had been on the B package."<<endl<<endl;
	                myfile<<endl<<first_name<<" could have saved $"<<bill<< " if they had been on the B package."<<endl<<endl;
                    }
//comparing to C package
if(bill_copy>c){
                bill_copy=bill_copy-c;
	                cout<<endl<<first_name<<" could have saved $"<<bill_copy<< " if they had been on the C package."<<endl<<endl;
	                myfile<<endl<<first_name<<" could have saved $"<<bill_copy<< " if they had been on the C package."<<endl<<endl;
                    myfile.close();
                   
	                
}
//if they cannot save money their default bill will be printed
else cout << first_name << " " << last_name << " used " << hours + 10 << " hours of internet and has a bill of $" << bill << " this month." << endl;
	
                    myfile << first_name << " " << last_name << " used " << hours + 10 << " hours of internet and has a bill of $" << bill << " this month." << endl;
	                myfile.close();
                    system("PAUSE");
	                main();
}


//Package B function
void package_b(){
	int hours = 0;
		ofstream myfile ("bill.txt");
    float bill = 0.0,c=19.95;
	int main();
	cout << "How many hours were used this month: ";
	cin >> hours;
	//checking to ensure hours does not exceed 744
    while (hours > 744){
		cout << "Hours exceeded." << endl;
		cout << "How many hours were used this month: ";
		cin >> hours;
	}
	hours = hours - 20;
	bill = (hours*1.00) + 14.95;
	//comparing package b bill to c bill
    if (bill>c){
    cout << first_name << " " << last_name << " used " << hours + 20 << " hours of internet and has a bill of $" << bill << " this month." << endl;
	myfile << first_name << " " << last_name << " used " << hours + 20 << " hours of internet and has a bill of $" << bill << " this month." << endl;
	bill=bill-c;
    cout<<endl<<first_name<<" could have saved $"<<bill<< " if they had been on the C package."<<endl<<endl;
    myfile<<endl<<first_name<<" could have saved $"<<bill<< " if they had been on the C package."<<endl<<endl;
    myfile.close();
    system("PAUSE");
	main();
                }
    //statement to execute if no money could have been saved
    else cout << first_name << " " << last_name << " used " << hours + 20 << " hours of internet and has a bill of $" << bill << " this month." << endl;
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
	cout<<"ISP BILL TOOL v.01"<<endl;
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
	//if statements to bring user to appropiate package function or to exit the program
	if (package == 'Q'){
		return 0;
	}
    if (package == 'A'){
		package_a();
	}
	if (package == 'B'){
		package_b();
	}
	if (package == 'C'){
		package_c();
	}
}

