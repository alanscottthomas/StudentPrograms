//Assignment: #12, Chapter 11, Problem C
//Name: Alan Thomas
//4/29/2015
//Purpose: Demonstrate knowledge of inheritance to 
//         input/print data. *I had some issues with this one
//         ended up creating the functions in the mother class.

#ifndef MACHINE_H
#define MACHINE_H
#include <iostream>
#include <string>

class Machine{
	private:
		std::string model;
		std::string make;
		std::string color;
		std::string resolution;
	public:
		void setmodel(std::string);
		void setmake(std::string);
		void setcolor(std::string);
		void setresolution(std::string);
		std::string getmodel();
		std::string getmake();
		std::string getcolor();
		std::string getres();
};

class Printer :public Machine{
	private:
		std::string colortype;
		double price;
	public:
		Printer(std::string ct, double p){
			colortype = ct;
			price = p;
		}
		
		std::string getcolortypes();
		double getprice();
};

class Scanner :public Machine {
	private:
		std::string resolution;
		double price;
	public:
		Scanner(std::string r, double p){
			resolution = r;
			price = p;
		}
		std::string getresolution();
		double getprice();


};











#endif