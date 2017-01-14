//Alan Thomas
//Assignment#7 3/17/2015
//Chapter8 Problem 4

#include <iostream>
using namespace std;

int main(){
	int food[3][7],i=0,j=0,total=0,flag=0,monkey1=0,monkey2=0,monkey3=0;
	string ans;
	
	//looping to fill information in for the 3 animals
	for(j=0;j<3;j++){
	cout<<"-Monkey# "<<j+1<<" diet information-"<<endl;;
	for(i=0;i<7;i++){
		cout<<"Pounds of food eaten on day "<<i+1<<" of the week: ";
		cin>>food[j][i];
		if(food[j][i]<0){
			cout<<endl<<"Input a positive number.";
			cout<<endl<<"Pounds of food eaten on day "<<i+1<<" of the week: ";
			cin>>food[j][i];
			
		}
	}
 }
//average per a day loop
	for(i=0;i<7;i++){
		total=(total+food[0][i]+food[1][i]+food[2][i])/3;
		cout<<"Average on day #"<<i+1<<": "<<total<<" lbs."<<endl;
		total=0;
	}



/**********************************************
Multiple loops to determine least amount of food
***********************************************/
//loop for least food monkey1
 for(i=0;i<7;i++){
 		monkey1=monkey1+food[0][i];
}

//loop for least food monkey2
 for(i=0;i<7;i++){
 		monkey2=monkey2+food[1][i];
}
//loop for least food monkey3
 for(i=0;i<7;i++){
 		monkey3=monkey3+food[2][i];
}
//determining which monkey ate the least
if(monkey1<monkey2){
	total=monkey1;
	ans="Monkey#1";
}
 if(monkey1>monkey3){
	total=monkey3;
	ans="Monkey#3";
	}
if (monkey2<monkey3){

	total=monkey2;
	ans="Monkey#2";
}

cout<<endl<<ans<<" ate the least, with "<<total<<" lbs. of food eaten.";
//restting some values for next calculations
monkey1=0;
monkey2=0;
monkey3=0;
total=0;







/**********************************************
Multiple loops to determine greatest amount of food
***********************************************/
//loop for most food monkey1
 for(i=0;i<7;i++){
 		monkey1=monkey1+food[0][i];
	 }

//loop for most food monkey2
 for(i=0;i<7;i++){
 		monkey2=monkey2+food[1][i];
	 }

//loop for most food monkey3
 for(i=0;i<7;i++){
 	monkey3=monkey3+food[2][i];
}
//determining which monkey ate the most
if(monkey1>monkey2){
	total=monkey1;
	ans="Monkey#1";
}
 if(monkey1<monkey2){
	total=monkey3;
	ans="Monkey#3";
	}
if (monkey2>monkey3){

	total=monkey2;
	ans="Monkey#2";
}

cout<<endl<<ans<<" ate the most, with "<<total<<" lbs. of food eaten.";

return 0;
}

