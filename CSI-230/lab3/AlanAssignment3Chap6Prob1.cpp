//Alan Thomas
//Assignment#2 2/05/2015
//Chapter6 Problem 1
#include <iostream>
using namespace std;
//retail funct begin
float calculateRetail(float wholesale, float markup){
	float retail=0;
	retail=wholesale*markup;
	return retail;
}
//main funct
int main(){
	float wholesale=0,markup=0,retail=0;
	//getting wholesale price
	cout<<"Enter the wholesale price: ";
	cin>>wholesale;
	while(!cin || wholesale<=- 1){
	cin.clear();
	cin.ignore();
	cout<<"Enter the wholesale price: ";
	cin>>wholesale;	
	}
	
	//Getting markup percentage
	cout<<endl<<"Enter markup percentage as a deciaml value(ie 75% =.75): ";
	cin>>markup;
	while(!cin || markup<= -1){
	cin.clear();
	cin.ignore();
	cout<<endl<<"Enter markup percentage as a deciaml value(ie 75% =.75): ";
	cin>>markup;	
	}
	
	//passing wholesale+markup to retail funct
	retail=calculateRetail(wholesale,markup);
	
	cout<<"The retail price is: $"<<retail<<endl;
	//pausing so user can view output more easily
	system("PAUSE");
	return 0;
}
