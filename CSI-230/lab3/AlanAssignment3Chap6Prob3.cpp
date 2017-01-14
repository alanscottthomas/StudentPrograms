//Alan Thomas
//Assignment#2 2/05/2015
//Chapter6 Problem 3
#include <iostream>
using namespace std;

//fall funct
float fallingDistance(float temp){
	float x=0;
	
	x=.5*(9.8*temp*temp);
	return x;
	
}

//main funct
int main(){
	float i=0,x=0,y=0;
	cout<<"Time fallen in seconds: ";
	cin>>x;
	y=fallingDistance(x);
	cout<<y<<" meters"<<endl;
	//pausing program to let user view their result before table is displayed
	cin.clear();
	cin.ignore();
	cout<<endl<<"To view a table of distance fallen (1s-10s) press any key"<<endl;
	cin.get();
	//loop to demonstrate distance funct
	for(i=1;i<=10;i++){
		x=fallingDistance(i);
		cout<<i<<" seconds = "<<x<<" meters"<<endl;
	}
return 0;	
	
}
