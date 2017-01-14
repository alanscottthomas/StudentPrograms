//Assignment: #11, Chapter 11, Problem B
//Name: Alan Thomas
//4/21/2015
//Purpose: Calculate profits and and cars sold by four dealerships

#include "car.h"
#include <cstdlib>
using namespace std;
int main(){
	double x;
	
	//generating array of 4 for lots
	Car lots[4];

	//Getting vehciles sold and profits
	for (int i = 0; i < 4; i++){
		cout << "Number of vehicles sold for dealership #" << i + 1 << " :";
		cin >> x;
		lots[i].setcarsold(x);
		x = 0;
		cout << "Number of profits for dealership #" << i + 1 << " :";
		cin >> x;
		lots[i].setprofit(x);
		x = 0;
	}
	//printing totals for profits and cars sold
	cout << endl << "Total vhehicles: " << Car::getcarsold() << endl << "Total profit for all dealerships: " << Car::getprofit() << endl;


	system("pause");
	return 0;

}