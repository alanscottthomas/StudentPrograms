//Alan Thomas
//Assignment#6 3/10/2015
//Chapter7 Problem 13

#include <iostream>
using namespace std;

class Population{
	private:
		double population,births,deaths;
		
	public:
		Population(double population_=2,double births_=0,double deaths_=0){
			population = population_;
			births = births_;
			deaths = deaths_;
			
		}
	void setpop(double p);
	void setbirths(double b);
	void setdeaths(double d);	
	double getbirthrate();
	double getdeathrate();
};

void Population::setpop(double p){
	population = p;
}

void Population::setbirths(double b){
	births = b;
}

void Population::setdeaths(double d){
	deaths = d;
}
//birthrate function
double Population::getbirthrate(){
	double birthrate;
	
	birthrate=births / population;
	return birthrate;
}
//deathrate function
double Population::getdeathrate(){
	double deathrate;
	deathrate=deaths/population;
	return deathrate;
}



//start main function
int main(){
	double population,births,deaths;
	
	cout<<"Population: ";
	cin>>population;
	cout<<endl<<"Births: ";
	cin>>births;
	cout<<endl<<"Deaths: ";
	cin>>deaths;
	cout<<endl;
	
	Population New;
	//use if statements here
	if(population>2){
	New.setpop(population);
	}
	if(births>0){
	New.setbirths(births);
	}
	if(deaths>0){
	New.setdeaths(deaths);
	}
	
	
	//printing death&birth rates
	cout<<endl<<"Birthrate: "<<New.getbirthrate();
	cout<<endl<<"Deathrate: "<< New.getdeathrate();
	cout<<endl;
	system("PAUSE");
return 0;
	 
}
