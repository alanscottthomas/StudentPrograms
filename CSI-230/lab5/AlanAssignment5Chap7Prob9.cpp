//Alan Thomas
//Assignment#5 2/26/2015
//Chapter7 Problem 9

#include <iostream>
using namespace std;

class Date{
	private:
		int month,day,year;
	public:
		Date(int m=1,int d=1,int y=2001){
			month=m;
			day=d;
			year=y;
			
		}
void setmonth(int m);
void setday(int d);
void setyear(int y);
int getdate();
};

void Date::setmonth(int m){
	month=m;
}

void Date::setday(int d){
	day=d;
}

void Date::setyear(int y){
	year=y;
}

int Date::getdate(){
	string name;
	// 3/15/2010
	cout<<month<<"/"<<day<<"/"<<year;
	if(month==1){
		name="January";
	}
	else if(month==2){
	name="February";	
	}
	else if(month==3){
		name="March";
	}
	else if(month==4){
		name="April";
	}
	else if(month==5){
		name="May";
	}
	else if(month==6){
		name="June";
	}
	else if(month==7){
		name="July";
	}
	else if(month==8){
		name="August";
	}
	else if(month==9){
		name="September";
	}
	else if(month==10){
		name="October";
	}
	else if(month==11){
		name="November";
	}
	else if(month==12){
		name="December";
	}
	
	cout<<endl<<name<<" "<<day<<" "<<year;
	cout<<endl<<day<<" "<<name<<" "<<year<<endl;
}




int main(){
	int month,day,year;
	Date x;
	
	cout<<"Enter the month(numerical form): ";
	cin>>month;
	while(month>12 || month<1){
	cout<<"Enter the month(numerical form): ";
	cin.clear();
	cin.ignore();
	cin>>month;
	}
	cout<<endl<<"Enter the day(numerical form): ";
	cin>>day;
	while(day>31 || day<1){
	cout<<"Enter the day(numerical form): ";
	cin.clear();
	cin.ignore();
	cin>>day;
	}
	cout<<"Enter the year: ";
	cin>>year;
	while(year>2020 || year<1950){
	cout<<"Enter the year(numerical form): ";
	cin.clear();
	cin.ignore();
	cin>>year;
	}
	x.setmonth(month);
	x.setday(day);
	x.setyear(year);
	
	x.getdate();
	
	system("PAUSE");
}

