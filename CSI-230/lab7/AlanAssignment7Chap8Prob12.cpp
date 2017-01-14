//Alan Thomas
//Assignment#7 3/17/2015
//Chapter8 Problem 12

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
	int i,j;
	double info[20];
	ifstream file;
	file.open("payroll.txt");
	for(i=0;i<400;i++){
	file>>info[i];
}
	//for(i=0;i<20;i++){
	//cout<<endl<<info[i];

	Payroll New[7];
	
	for(i=0;i<12;i++){
		New[i].hours_(info[i],info[i+1]);
	}

j=0;
for(i=0;i<7;i++){
	cout<<endl<<"This employee earned: $"<<New[j].pay();
	j=j+2;
}

}
