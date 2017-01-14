#include <iostream>
#include <fstream>
using namespace std;


class Payroll{
private:
	double rate, hours;
public:
	void hours_(double worked,double rate_);
	double pay();
};
void Payroll::hours_(double worked,double rate_){
	rate=rate_;
	hours = worked;
}
double Payroll::pay(){
	double total;
	total = rate*hours;
	return total;
}


int main(){
	char info[1000];
	int i = 0;
	ifstream file("payroll.txt");

	Payroll New[7];

	while (!file.eof() && i < 1000)
	{
		getline(line,file); //reading one character from file to array
		i++;
	}
	for (i = 0; i < 5; i++){
		New[1].hours_(info[i],info[i]);
	}
	cout<<New[1].pay();
	return 0;
}
