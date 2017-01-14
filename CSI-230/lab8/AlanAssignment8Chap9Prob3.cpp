//Assignment: #8, Chapter 9, Problem 3
//Name: Alan Thomas
//3/24/2015
//Purpose: Allow for a user to search an array for
//         a number utilizing binary search.


#include <iostream>

using namespace std;

//Execution begins
int main(){
const int SIZE=10;
int lottery[SIZE]={13579,26791,26792,3345,55555,62483,77777,79422,85647,93121},user=0,i=0;
int temp;
bool flag=false;
int search, first=0, middle, position =-1;
int last =SIZE-1;
//Sorting lottery array large to small
do{
flag=false;
	for(int i=0;i<SIZE-1;i++){                     
		if(lottery[i+1]<lottery[i]){                                                                                    
			temp=lottery[i];
			lottery[i]=lottery[i+1];
			lottery[i+1]=temp;
			flag=true;
			}
}
}while(flag);
/*Verifying lottery is sorted

             for(i=0;i<10;i++){
                  cout<<endl<<lottery[i];
                  }
                                   
             cout<<endl;
*/

cout<<"Enter the lottery number to search for: ";
cin>>search;


	while(!flag && first<=last){
		middle=(first+last)/2;

		if(lottery[middle]==search){
			flag=true;
			position = middle+1;
		}
		else if(lottery[middle]>search){
			last = middle-1;
		}
		else{first=middle+1;}
	}


	if(flag){
		cout<<"Number was found at position# "<<position<<endl;
	}
	else{
		cout<<"Number was NOT found"<<endl;
	}

system("PAUSE");
return 0;
}

