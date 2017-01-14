//Alan Thomas
//Assignment#7 3/17/2015
//Chapter8 Problem A

#include <iostream>
#include <string>

using namespace std;
//Student struct
struct Students{
	double score;
	string name;
   //student constructor
	Students(string name_, double score_){
		name = name_;
		score = score_;
	}
};

//begin execution
int main(){
	int i = 0;
	//creating array of Students with defined values
    Students New[] = { Students("Alan Thomas", 95),Students("Georgie Dude", 85),Students("Jane Doe", 75), };
    //printing information
    for(i=0;i<3;i++){
	cout << New[i].name<<" "<<New[i].score<<endl;
    }
//pausing so user to can view
system("PAUSE");

return 0;
}

