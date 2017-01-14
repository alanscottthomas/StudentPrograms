//Implementation file for problem B

#include "car.h"
#include <iostream>

double Car::carsold = 0;
double Car::profit = 0.0;

//
void Car::setcarsold(double s){
	carsold += s;
}

//sets profit
void Car::setprofit(double p){
	profit += p;
}

//return number of vehicles sold
double Car::getcarsold(){
	return carsold;
}

//return profit function
double Car::getprofit(){
	return profit;
}