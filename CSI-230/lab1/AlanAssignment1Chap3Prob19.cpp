//Alan Thomas
//Assignment#1 1/12/2015
//Chapter3 Problem 19

#include <iostream>;
using namespace std;

int main()
{float a=0,b=0,pi=3.14;
int slices=0;
cout<<"Enter the diameter of the pizza in inches: ";
cin>>a;
a=pi*a*2;
b=a/14.125;
slices=b;
cout<<endl<<"You will have "<<slices<<" whole slices."<<endl;
}
