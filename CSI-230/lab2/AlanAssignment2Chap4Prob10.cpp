//Alan Thomas
//Assignment#2 1/30/2015
//Chapter4 Problem 10
#include <iostream>
#include <cstdlib>
using namespace std;

//Main function
int main(){
	int checks = 0;
	float sum = 0;
	//Getting input from user
    cout << "Welcome to the ACME Bank checking account statement calculator." << endl << "Checks Writen: ";
	cin >> checks;
	//If invalid input loop till acceptable input
    while (!cin || checks <= -1)
	{
		cout << "Invalid input" << endl;
		//clearing cin cache
        cin.clear();
        cin.ignore();
        cout<<"Checks Writen: ";
        cin>>checks;
        }
    //Once acceptable input used this loop will execute to compute checking statement
    if (checks<20){
		sum = checks*.10 + 10;
	}
	else if (checks >= 20 && checks<39){
		sum = checks*.08 + 10;
	}
	else if (checks >= 40 && checks<59){
		sum = checks*.06 + 10;
	}
	else if (checks >= 60){
		sum = checks*.04 + 10;
  }
	//Printing information and pausing program so user can view before termination
    cout << "Your monthly checking account statement is $" << sum << endl << endl;
	system("PAUSE");
    return 0;
}
