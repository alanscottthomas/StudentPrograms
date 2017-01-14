//Alan Thomas
//Assignment#6 3/10/2015
//Chapter7 Problem 14

#include <iostream>
using namespace std;

class Tips{
	private:
		double taxrate;
	
	public:
		Tips(double taxrate_=0.065){
		taxrate=taxrate_;
		}
		double computetip(double totalbill,double tiprate);
};

double Tips::computetip(double totalbill, double tiprate){
	double total,tip;
	
	total=totalbill-(totalbill*taxrate);
	tip=(total*tiprate);
	return tip;
	
	
}


int main(){
	double taxrate,total,tiprate;
	char ans,ans2;
	
	
	cout<<"Press any letter to computer your tip, type Q to exit"<<endl;
	cin>>ans;
	while(!(ans == 'q' || ans == 'Q')){
		cout<<"Bill total: $";
		cin>>total;
		cout<<endl<<"Tip rate(75%=.75): %";
		cin>>tiprate;
		cout<<endl<<"Specific tax rate(y/n)?: ";
		cin>>ans2;
		if(ans2=='y' || ans2=='Y'){
			cout<<endl<<"Tax rate(75%=.75): %";
			cin>>taxrate;
			Tips tip(taxrate);
			cout<<"The tip should be: $"<<tip.computetip(total,tiprate);
		}
		else {
		Tips tip;
		cout<<"The tip should be: $"<<tip.computetip(total,tiprate);
		}
		cout<<endl<<"Press any letter to computer your tip, type Q to exit"<<endl;
		cin>>ans;
	}
return 0;	
}
