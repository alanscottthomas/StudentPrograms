//Alan Thomas
//Assignment#2 2/05/2015
//Chapter6 Problem 4
#include <iostream>
using namespace std;
//kinetic funct
float kineticEnergy(float mass, float velocity){
float x=0;
//formula for calculation
x=.5*(mass*velocity*velocity);
return x;
}
//main funct
int main(){
	float mass=0,velocity=0,x=0;
	cout<<"Objects mass in kilograms: ";
	cin>>mass;
	cout<<endl<<"Velocity(m/s): ";
	cin>>velocity;
	//passing arguements to energy funct
	kineticEnergy(mass,velocity);
	x=kineticEnergy(mass,velocity);
	//printing results
	cout<<endl<<"The kinetic energy is: "<<x<<" joules."<<endl;
	system("PAUSE");
	return 0;
}
