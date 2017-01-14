//Alan Thomas
//Assignment#4 2/19/2015
//Chapter6 Problem 14

#include <iostream>

using namespace std;


//in-patient function
double Patient(int days,double rate,double charges,double medication){
	double total;
	total=(days*rate)+charges+medication;
	return total;
	}
//out patient function
double Patient(double charges, double medication){
	double total;
	total=charges+medication;
	return total;
	}
//main function
int main(){
	char ans;
	int days;
	double rate, charges, medication;
	cout<<"Please enter 'i' for in-patient billing and 'o' for outpatient billing: ";
	cin>>ans;
	//input validation
	while(!(ans =='i' || ans=='I'||ans=='o'||ans=='O')){
	cout<<"Invalid input";
	cout<<endl<<"Please enter 'i' for in-patient billing and 'o' for outpatient billing: ";
	cin.clear();
	cin.ignore();
	cin>>ans;
	}
	//inpatient 
	if(ans == 'I' || ans == 'i'){
	cout<<"Number of days in hospital: ";
	cin>>days;
	cout<<"Enter rate: ";
	cin>>rate;
	cout<<"Enter any additonal charges: ";
	cin>>charges;
	cout<<endl<<"Enter charges pertaining to medication cost: ";
	cin>>medication;
	cout<<endl<<"The total for this hospital stay is: $"<<Patient(days,rate,charges,medication)<<endl;
	system("PAUSE");
	}
	//outpatient
	else if (ans=='o' || ans=='O'){
	cout<<"Enter any charges encured during this patient's visit: ";
	cin>>charges;
	cout<<endl<<"Enter charges that occured due to medication administration: ";
	cin>>medication;
	cout<<endl<<"The total charge for this patient's outpatient visit is: "<<Patient(charges,medication)<<endl;
	system("PAUSE");
		
	}
	return 0;
}

