//Alan Thomas
//Assignment#5 2/26/2015
//Chapter7 Problem C

#include <iostream>
#include <string>
using namespace std;

class Student{
	private:
		int score;
		string major;
		
		public:
			Student(string m="Computer Science"){
				major =m;
				score=0;
			}
			void setmajor(string m);
			void setscore(int s);
			string getmajor();
			char getgrade();
			
};
//function to determine grade
char Student::getgrade(){
char grade;
if(score>=90){
grade='A';
}
else if(score>=80){
grade='B';
}
else if(score>=70){
grade='C';
}
else if(score>=60){
grade='D';
}
else{grade='F';}
return grade;
}
//function to set the numerical score
void Student::setscore(int s){
score=s;
}
//function to set the major
void Student::setmajor(string m){
	major=m;
}
string Student::getmajor(){
	return major;
}


int main(){
	string major;
	int score;
	Student x;
	cout<<"Enter the major: ";
	getline(cin,major);
	
	cout<<"Enter the score for the course: ";
	cin>>score;
	x.setmajor(major);
	x.setscore(score);
	
	cout<<endl<<"This student is majoring in "<<x.getmajor()<<" and currently has achieved a "<<x.getgrade()<<" in the class.";

	
}


