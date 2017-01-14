//Assignment: #10, Chapter 10, Problem A
//Name: Alan Thomas
//4/14/2015
//Purpose: Allow for a user to enter a major
//			and enter score for students in the class
//			then print their average score

#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

//Start class Major
class Major{
private:
	string name;
	int number;
	int *ptr;
public:
	Major(int num){
		ptr = new int[num]; //allocating array
	}
	void setname(string n){
		name = n;
	}

	string getname(){
		return name;
		for (int j = 0; j < number; j++){
			cout << "Score for student #" << j + 1 << ": ";
			cin >> ptr[j];
			cout << endl;
		}
				//adding ptr[n] to total for avg
		for (int i = 0; i < number; i++){
			total += ptr[i];
		}
		cout << "The average score is: ";
		return total / num;
	}
};
//Start main function
	int main(){
		int num;
		string name;

		cout << "Name of major: ";
		getline(cin, name);
		cout << endl;
		cout << "Number of students: ";
	}
	//Function to computer avg
	double averagescore(int num){
		static double total;
		cin >> num;
		//Creating 1 object of Major class
		Major New(num);
		//Setting Major name
		New.setname(name);
		//Getting student scores
		cout <<"Enter the scores for "<< New.getname()<<endl;
		//printing avg
		cout<<New.averagescore(num);

		cout << endl << endl;
		system("pause"); //pause for user
		return 0;
	}
