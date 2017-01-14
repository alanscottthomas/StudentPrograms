//Alan Thomas
//Assignment#6 3/10/2015
//Chapter7 Problem 3

#include <iostream>
#include <string>
using namespace std;
//Corp struct
struct CorpData{
	string name;
	double firstqtr, secondqtr, thirdqtr, fourthqtr, totalsales, avgqtr;

    //Corp constructor
	CorpData(string name_, double firstqtr_, double secondqtr_, double thirdqtr_, double fourthqtr_){
		name = name_;
		firstqtr = firstqtr_;
		secondqtr = secondqtr_;
		thirdqtr = thirdqtr_;
		fourthqtr = fourthqtr_;
	}
};
   //average/name/total function
   void average(string name,double one, double two, double three, double four){
        double average;
        cout<<"Name: "<<name;
        average=one+two+three+four;
        cout<<endl<<"Total QTR sales: $"<<average;
        average=0;
        average=(one+two+three+four)/4;
        cout<<endl<<"Average QTR sales: $"<<average<<endl<<endl;
        }
         
    
    //Main func.
	int main(){
		
        string name;
		double firstqtr, secondqtr, thirdqtr, fourthqtr;
        //Prompting Corp_one
		cout << "Division name:";
		cin.clear();
		
        getline(cin,name);
		
        cout << endl << "First qtr sales: ";
		cin >> firstqtr;
		cout << endl << "Second qtr sales: ";
		cin >> secondqtr;
		cout << endl << "Third qtr sales: ";
		cin >> thirdqtr;
		cout << endl << "Fourth qtr sales: ";
		cin >> fourthqtr;
		    //Corp_One information
        CorpData Corp_one(name, firstqtr, secondqtr, thirdqtr, fourthqtr);
		cout<<endl<<endl;
		
        //Prompting Corp_two
		cout << "Division name:";
		
        cin.clear();
		cin.ignore();
        getline(cin,name);
        
        cout << endl << "First qtr sales: ";
		cin >> firstqtr;
		cout << endl << "Second qtr sales: ";
		cin >> secondqtr;
		cout << endl << "Third qtr sales: ";
		cin >> thirdqtr;
		cout << endl << "Fourth qtr sales: ";
		cin >> fourthqtr;
		    //Corp_Two information
        CorpData Corp_two(name, firstqtr, secondqtr, thirdqtr, fourthqtr);
		cout<<endl<<endl;
		
        
      
        
        //Prompting Corp_three
		cout << "Division name:";
		
        cin.clear();
		cin.ignore();
        getline(cin,name);
        
        cout << endl << "First qtr sales: ";
		cin >> firstqtr;
		cout << endl << "Second qtr sales: ";
		cin >> secondqtr;
		cout << endl << "Third qtr sales: ";
		cin >> thirdqtr;
		cout << endl << "Fourth qtr sales: ";
		cin >> fourthqtr;
		    //Corp_Three information
        CorpData Corp_three(name, firstqtr, secondqtr, thirdqtr, fourthqtr);
		cout<<endl<<endl;
        
        
        //Prompting Corp_four
		cout << "Division name:";
		
        cin.clear();
		cin.ignore();
        getline(cin,name);
        
        cout << endl << "First qtr sales: ";
		cin >> firstqtr;
		cout << endl << "Second qtr sales: ";
		cin >> secondqtr;
		cout << endl << "Third qtr sales: ";
		cin >> thirdqtr;
		cout << endl << "Fourth qtr sales: ";
		cin >> fourthqtr;
		    //Corp_four information
        CorpData Corp_four(name, firstqtr, secondqtr, thirdqtr, fourthqtr);
		cout<<endl<<endl;
        
        //Displaying average/total/name
        
        average(Corp_one.name,Corp_one.firstqtr,Corp_one.secondqtr,Corp_one.thirdqtr,Corp_one.fourthqtr);
        average(Corp_two.name,Corp_two.firstqtr,Corp_two.secondqtr,Corp_two.thirdqtr,Corp_two.fourthqtr);
        average(Corp_three.name,Corp_three.firstqtr,Corp_three.secondqtr,Corp_three.thirdqtr,Corp_three.fourthqtr);
        average(Corp_four.name,Corp_four.firstqtr,Corp_four.secondqtr,Corp_four.thirdqtr,Corp_four.fourthqtr);
        system("PAUSE");
        return 0;
        
	}

