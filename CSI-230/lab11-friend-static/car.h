//Header file for problem B

#ifndef CAR_H
#define CAR_H

#include <iostream>

class Car{
	private:
		static double carsold;
		static double profit;

	public:
		void setcarsold(double); //set carsold variable
		void setprofit(double); //sets profit
		static double getcarsold(); //gets carsold variable
		static double getprofit(); //gets profit


};


#endif