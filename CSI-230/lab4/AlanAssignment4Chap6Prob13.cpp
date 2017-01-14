//Alan Thomas
//Assignment#4 2/19/2015
//Chapter6 Problem 13

#include <iostream>
using namespace std;

//First Function
void First(int &ordered, int &stock, double &shipping){
	char ans;
	cout << "Number of spools to order: ";
	cin >> ordered;
	while (ordered<1){
		cout<<"Invalid input."<<endl;
		cout << "Number of spools to order: ";
		cin >> ordered;
	}
	cout << endl << "Number of spools in stock: ";
	cin >> stock;
	while(stock<0){
		cout<<"Invalid input."<<endl;
		cout << endl << "Number of spools in stock: ";
		cin >> stock;
	}
	
	cout << endl << "Any charges above the $10 S&H cost(Y/N): ";
	cin >> ans;
//Special Cost Decision
	if (ans == 'Y' || ans == 'y'){
		cout << "Enter special cost: ";
		cin >> shipping;
		while(shipping<0){
		cout<<"Invalid input."<<endl;
		cout << "Enter special cost: ";
		cin >> shipping;	
		}
	
	
	
	}

}

//Second Function
void Second(int &ordered, int &stock, double &shipping){
	int ready;
	if(stock>ordered){
	ready=ordered;
	cout<<"Ready to ship: "<<ready<<endl;
	cout<<"Number on backorder: 0"<<endl;
	cout<<"Total cost of spools: $"<<ready*100<<endl;
	cout<<"Total shipping and handling: $"<<shipping<<endl;
	cout<<"Total of the portion ready to ship: $"<<ready*100+shipping<<endl;
	}

	else if(ordered>stock){
		ready=stock;
		cout<<"Ready to ship: "<<ready<<endl;
		cout<<"Number on backorder: "<<ordered-stock<<endl;
		cout<<"Total cost of spools: $"<<ready*100<<endl;
		cout<<"Total shipping and handling: $"<<shipping<<endl;
		cout<<"Total of the portion ready to ship: $"<<ready*100+shipping<<endl;
	}

}

// Main Function
int main(){
	int ordered, stock;
	double shipping=10.00;

	First(ordered, stock, shipping);
	Second(ordered,stock,shipping);
	system("PAUSE");
return 0;
	}


