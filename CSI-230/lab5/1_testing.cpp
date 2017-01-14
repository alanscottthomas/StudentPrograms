#include <iostream>
using namespace std;
//Creating class Airplane
class Airplane{
	private:
		int seats;
		double price;
	public:
		void setseats(int s);
		void setprice(double p);
		double getrevenue();
};
//Function Setprice
void Airplane::setprice(double p){
	price=p;
}
//Function Setseats
void Airplane::setseats(int s){
	seats=s;
}
//Function Getrevenue
double Airplane::getrevenue(){
	double revenue;
	revenue=seats*price;
	return revenue;
}
//Begin int main
int main(){
	int seats;
	double price;
	Airplane x;
	
	cout<<"Sold seats on the flight: ";
	cin>>seats;
	cout<<endl<<"Price per a seat: $";
	cin>>price;
	//setting instance of Airplane with user variables
	x.setprice(price);
	x.setseats(seats);
	//Printing profits
	cout<<endl<<"This flight made a profit of: $"<<x.getrevenue()<<endl;
	system("PAUSE");
	return 0;	
}
