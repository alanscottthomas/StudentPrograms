//Assignment: #11, Chapter 11, Problem A
//Name: Alan Thomas
//4/21/2015
//Purpose: Calculate profits and taxes paid by a bank


#include "bigmoney.h"
#include <iostream>
#include <cstdlib>
using namespace std;
int main(){
	double profit;
	Bigmoney branches[3];
	Bigmoney headoffice[1];
	Overseas overseas[1];
	
	//Getting profits for each branch
	for (int i = 0; i < 3; i++){
		cout << "Profit for branch " << i+1 << ":";
		cin >> profit;
		branches[i].setprofit(profit);
	}
	//Getting profit
	profit = 0;
	cout << endl << "Profit for overseas branch: ";
	cin >> profit;
	overseas[0].setprofit(profit);

	//Printing profits for each branch
	for (int i = 0; i < 3; i++){
		cout << "Profit for branch #" << i + 1 << ": " << branches[i].getprofit() << endl;
	}
        //printing total profit
	cout <<endl<<"Total profit: "<< Bigmoney::totalprofit_()<<endl;

	//Getting and calculating tax rate
	profit = 0;
	cout << endl << "Tax rate(15%=.15 etc): ";
	cin >> profit;
	cout << endl << "Tax paid by the bank: " << Bigmoney::tax(profit) << endl<<endl;




	system("pause");
return 0;
}
