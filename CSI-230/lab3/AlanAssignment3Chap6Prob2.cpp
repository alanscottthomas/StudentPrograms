//Alan Thomas
//Assignment#2 2/05/2015
//Chapter6 Problem 2
#include <iostream>
using namespace std;

//celsius funct
float celsius(float temp){
	float x=0;
	//[°C] = ([°F] - 32) × 5/9
	x=(temp-32) * .5555;
	return x;
	
}

//main funct
int main(){
	float i=0,x=0,y=0;
	cout<<"Degrees in Fahrenheit: ";
	cin>>x;
	y=celsius(x);
	cout<<y<<" celsius"<<endl;
	//pausing program to let user view their result before table is displayed
	cin.clear();
	cin.ignore();
	cout<<endl<<"To view a table of Fahrenheit(0F-20F) converted to Celsius press any key"<<endl;
	cin.get();
	//loop to demonstrate celsius funct
	for(i=0;i<=20;i++){
		x=celsius(i);
		cout<<x<<" celsius"<<endl;
	}
return 0;	
	
}
