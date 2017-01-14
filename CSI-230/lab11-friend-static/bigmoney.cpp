//BIGMONEY.CPP for problem A
#include <iostream>

#include "bigmoney.h" //importing the header file for banking program classes

//************BIGMONEY CLASS BEGIN***************

double Bigmoney::totalprofit=0.0;
double Bigmoney::taxrate=0.0;

void Bigmoney::setprofit(double s){
	profit = s;
	totalprofit += s;
}

double Bigmoney::getprofit(){
	return profit;
}

double Bigmoney::tax(double t){
	taxrate = t;
	double x;
	x = taxrate*totalprofit;
	return x;
}

double Bigmoney::totalprofit_(){
	return totalprofit;
}

//***********OVERSEAS CLASS BEGIN**************

void Overseas::setprofit(double s){
	oprofit = s;

	Bigmoney::totalprofit += oprofit;
}


double Overseas::getprofit(){
	return oprofit;
}