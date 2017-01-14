//Alan Thomas
//Assignment#2 1/30/2015
//Chapter4 Problem A
#include <cstdlib>
#include <iostream>
#include <ctime>

using namespace std;

int main(){
	//seeding and naming variable for rng
    int randnum;
	srand(time(0));
	randnum=1+rand()%5;
//begin if-else statements to determine career based on rng results.
if(randnum == 1){
	cout<<"Your career should be in the field of education.";
}
else if(randnum==2){
	cout<<"Your career should be in politics.";
}
else if(randnum==3){
cout<<"Your career should be in entertainment.";
}
else if (randnum==4){
	cout<<"Your career should be in the field of journalism.";
}
else if(randnum==5){
	cout<<"Your career should be in the technology sector";
}
cout<<endl<<endl<<"Thank you for using the ACME career determination program.";
//freezing screen so user can view results
cin.get();
}


