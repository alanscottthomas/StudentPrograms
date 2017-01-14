//Assignment: #9, Chapter 9, Problem 9
//Name: Alan Thomas
//4/2/2015
//Purpose: Allow for a user enter
//			circle information
//          and display the radius
//          in sorted order





#include <iostream>
#include <iomanip>
//#include "Circle.h"
#include <cmath>
using namespace std;

const int NUM_CIRCLES = 8;
class Circle{
private:
	double radius;
	int centerX, centerY;

public:
	Circle(){
		radius = 1.0;
		centerX = centerY = 0;
	}
	Circle(double r){
		radius = r;
		centerX = centerY = 0;
	}
	Circle(double r, int x, int y){
		radius = r;
		centerX = x;
		centerY = y;
	}
	void setRadius(double r){
		radius = r;
	}

	int getXcoord(){
		return centerX;
	}
	int getYcoord(){
		return centerY;
	}

	double findArea(){
		return 3.14*pow(radius, 2);
	}

	double getRadius(){
		return radius;
	}



};



void bubblesort(Circle circle[], int size){
	double temp = 0;
	bool flag = true;
	
	do{
		flag = false;
		for (int i = 0; i<size - 1; i++){
			if (circle[i + 1].findArea()<circle[i].findArea()){
				temp = circle[i].getRadius();
				circle[i].setRadius(circle[i + 1].getRadius());
				circle[i + 1].setRadius(temp);
				flag = true;
			}
		}
	} while (flag);

	for (int i = 0; i<size; i++){
		cout << "Circle#" << i + 1 << ": " << circle[i].findArea() << endl;
	}

}





int main(){

	Circle circle[NUM_CIRCLES] = { 2.5, 4.0, 1.0, 3.0, 6.0, 5.5, 3.5, 2.0 }; //defines array of circle objects

	for (int index = 0; index < NUM_CIRCLES; index++){
		double r;
		cout << endl << "Enter the radius of the circle: ";
		cin >> r;
		circle[index].setRadius(r);
	}


	cout << fixed << showpoint << setprecision(2);
	cout << endl << "Here are the areas of the circles: " << endl;

	for (int index = 0; index < NUM_CIRCLES; index++){
		cout << "Circle " << index + 1 << setw(8)
			<< circle[index].findArea() << endl;
	}


	bubblesort(circle, NUM_CIRCLES);
	system("pause");


	return 0;

}
