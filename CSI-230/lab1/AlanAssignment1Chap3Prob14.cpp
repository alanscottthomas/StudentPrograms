//Alan Thomas
//Assignment#1 1/12/2015
//Chapter3 Problem 14

#include <iostream>;
using namespace std;

int main()
{float tax=0,house_value=0,taxes=0;
cout<<"Please enter the value of the home in question: ";
cin>>house_value;
cout<<"Current tax rate in decimal form: ";
cin>>tax;
taxes=house_value*tax;
cout<<"You will owe the IRS yearly in taxes: "<<taxes<<endl;


}
