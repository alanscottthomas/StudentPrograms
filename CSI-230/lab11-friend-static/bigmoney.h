//BIGMONEY CLASS HEADER FILE PROBLEM A

#ifndef BIGMONEY_H
#define BIGMONEY_H
#include <iostream>



//***********OVERSEAS CLASS BEGIN**************
class Overseas{
private:
	double oprofit;

public:
	Overseas(){
		oprofit = 0.0;
	}
	void setprofit(double); //sets oprofit and += Bigmoney::totalprofit

	double getprofit();

};





//************BIGMONEY CLASS BEGIN***************
class Bigmoney{
	private:
		double profit;
		static double totalprofit;
		static double taxrate;
	public:
		Bigmoney(){
			profit = 0.0;
		}
		void setprofit(double);   //accepts double to set profit variable also adds profit to totalprofit variable
		double getprofit();     ///returns profit for a branch
		static double tax(double); //sets tax amount and returns tax amount for entire corporation
		friend void Overseas::setprofit(double);
		static double totalprofit_(); //returns total
};



#endif
