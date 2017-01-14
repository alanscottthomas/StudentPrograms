//Alan Thomas
//Assignment#5 2/26/2015
//Chapter7 Problem b


#include <iostream>
#include <string>
using namespace std;

class Movie{
private:
	string title;
	int year;
	double cost, revenue;
public:
	Movie(string x, int z){
		 title = x;
		 year = z;
	}
	void setcost(double d);
	void setrevenue(double r);
	double getprofit();
	string gettitle();
	int getyear();
	
};

string Movie::gettitle(){
	
	return title;
}
int Movie::getyear(){
	return year;
}
void Movie::setcost(double d){
	cost = d;
}

void Movie::setrevenue(double r){
	 revenue = r;
}

double Movie::getprofit(){
	double total;

total=revenue-cost;

	return total;
}

int main(){
	string title;
	double profit, cost;
	int year;

	cout << "Title of the movie: ";
	getline(cin,title);
	
	cout << "Year movie was made: ";
	cin >> year;
	cout << "How much was made from this movie(0 if no profit): ";
	cin >> profit;
	cout << "Production cost of the movie: ";
	cin >> cost;
	Movie x(title,year);
	x.setcost(cost);
	x.setrevenue(profit);
	
    
	x.getprofit();
	
	cout<<endl<<x.gettitle()<<" was made in "<<x.getyear()<<", it made/loss $"<<x.getprofit()<<endl<<endl;
	
	
	system("PAUSE");

}
