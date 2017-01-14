//Assignment: #9, Chapter 9, Problem 4
//Name: Alan Thomas
//4/2/2015
//Purpose: Allow for a user to to sort rainfall
//         from highest to lowest



#include <iostream>
#include <string>
using namespace std;



struct Month{
	double rain;
	string name;

	Month(string n){
		name = n;
	}


	//function to set the rain amount
	void setrain(double r){
		rain = r;
	}

	double getrain(){
		return rain;
	}

	string getname(){
		return name;
	}



};
//Bubblesort for rain
void bubblesort(Month[], int);


void display(Month[], int);




int main(){
	const int SIZE = 12;
	Month Months[SIZE] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
	double rain;


	//loop to set the amount of rain per a month
	for (int i = 0; i<SIZE; i++){
		cout << "Enter the amount of rain for the month of " << Months[i].name << ": ";
		cin >> rain;
		Months[i].setrain(rain);
		cout << endl;
		rain = 0;
	}

	bubblesort(Months, SIZE);

	display(Months, SIZE);

	cin.get();
	return 0;
}


void bubblesort(Month m[], int SIZE){
	string nametemp;
	double temp[12];
	bool flag = true;

	do{
		flag = false;
		for (int i = 0; i < SIZE - 1; i++){
			if (m[i + 1].getrain() < m[i].getrain()){
				temp[i] = m[i].getrain();
				nametemp = m[i].name;
				m[i].name = m[i + 1].name;
				m[i + 1].name = nametemp;
				m[i].setrain(m[i + 1].getrain());
				m[i + 1].setrain(temp[i]);
				flag = true;
			}
		}
	} while (flag);
	
	
}

void display(Month m[],int SIZE){

	for (int i = 0; i<SIZE; i++){
		cout << "Month: " << m[i].getname() << " " << "Rain: " << m[i].getrain() << endl;
	}
	cin.get();
}