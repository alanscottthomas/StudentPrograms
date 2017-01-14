//Alan Thomas
//Assignment#6 3/10/2015
//Chapter7 Problem A

#include <iostream>
#include <string>
using namespace std;


//start component structure
struct Component{
	string name;
	double price;
};
//start inventory class
class Inventory{
private:
	int quantity;
	Component part;
public:
	//declaring constructor/ a little confused about this area, made it work however.
	Inventory::Inventory(string name_, int quantity_, double price_ = 15.25){
		part.name = name_;
		quantity = quantity_;
		part.price = price_;
	}
	double getamount();
	string getname();
};
//getamount function
double Inventory::getamount(){
	double total;

	total = part.price*quantity;
	return total;
}
//getname function
string Inventory::getname(){
	return part.name;

}

//begin execution
int main(){

	string part_name;
	int part_quantity;
	double price;
	char ans;
	//begin prompting using for information
	cout << "Name of part: ";
	cin >> part_name;
	cout << endl << "Quantity: ";
	cin >> part_quantity;
	cout << endl << "Would you like to specifiy a price or remain with the default price(y/n)?: ";
	cin >> ans;
	//checking to see if they want a different price fromdefault
	if (ans == 'y' || ans == 'Y'){
		cout << endl << "Price: $";
		cin >> price;
		Inventory newpart(part_name, part_quantity,price);
		cout << endl << "Part name is: " << newpart.getname();
		cout << endl << "Total price of inventory: $"<<newpart.getamount();
	}
	else{
		Inventory newpart(part_name, part_quantity);
		cout << endl <<"Part name is: "<< newpart.getname();
		cout << endl <<"Total price of inventory: $"<<newpart.getamount();
	}
	
	cout << endl << endl;
	//pausing system so user can view their results
	system("PAUSE");
	
	return 0;
}
