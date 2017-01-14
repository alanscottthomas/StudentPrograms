//Assignment: #8, Chapter 9, Problem 2
//Name: Alan Thomas
//3/24/2015
//Purpose: Allow for a user to search an array for
//         a number utilizing linear search.


#include <iostream>

using namespace std;
void searchscores(int s[], int size){
	int lotto, position;
	bool flag=false;
	cout<<"Enter the lottery numer to search for: ";
	cin>>lotto;

	for(int i=0;i<size;i++){
		if(lotto==s[i]){
		flag=true;
		position=i+1;
		}
	}

	if(flag==true){
		cout<<endl<<"The Value was found at position# "<<position<<endl;
		}
	else{
		cout<<endl<<"Value NOT found"<<endl;
		}
	}

int main(){
const int SIZE=10;
int lottery[SIZE]={13579,26791,26792,3345,55555,62483,77777,79422,85647,93121},user=0,i=0;


searchscores(lottery, SIZE); //Sending user input to function.
system("PAUSE");
return 0;
}


