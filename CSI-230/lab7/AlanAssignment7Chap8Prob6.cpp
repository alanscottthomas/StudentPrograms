//Alan Thomas
//Assignment#7 3/17/2015
//Chapter8 Problem 6


#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(){
	int winningDigits[5],player[5],i=0,j=0;
	srand(time(NULL));
	//generating lottoerey number
	for(i=0;i<5;i++){
		winningDigits[i]=1+rand()%9;
	}
	//getting users numbers
	for(i=0;i<5;i++){
		cout<<endl<<"Enter a number: ";
		cin>>player[i];
		if(player[i]<0 || player[i]>9){
			cout<<endl<<"Invalid input";
			cout<<endl<<"Enter a number: ";
			cin>>player[i];
		}
	}
	//prining lottery numbers
	cout<<endl<<"Winning Numbers are: ";
	for(i=0;i<5;i++){
		cout<<winningDigits[i]<<":";
	}
	//printing what numbers the user picked
	cout<<endl<<"Your numbers were: ";
	for(i=0;i<5;i++){
		cout<<player[i]<<":";
	}
	//comparing player picks to the lottery numbers
	for(i=0;i<5;i++){
		if(player[i]==winningDigits[i]){
			j++;
		}
	}
	//printing winning numbers
	cout<<endl<<"You had "<<j<<" matches.";
	
	
	
}
