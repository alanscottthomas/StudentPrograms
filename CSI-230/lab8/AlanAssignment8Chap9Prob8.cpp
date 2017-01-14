//Assignment: #8, Chapter 9, Problem 8
//Name: Alan Thomas
//3/24/2015
//Purpose: Allow for a user to search for a certain number
//         utilizing a binary and linear search function.
//         it will than display the position and the number
//         loops needed in order to find the value.


#include <iostream>

using namespace std;

//utilized a global for simplicity
int array[20]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};




//Linear search function begins
void linesearch(int num){
	int j=0,position;
	bool flag=false;
	const int SIZE=20;
	cout<<endl<<"[LINEAR SEARCH]";

	for(int i=0;i<SIZE;i++){
		if(num==array[i]){
			flag=true;
			position=i+1;
			break; //breaking out of the loop since value was found
		}	
		else if(flag!=array[i]){
			j++;  //counter for loops
		}
	}


	if(flag==true){
		cout<<endl<<"The Value was found at position# "<<position<<endl;
	}
	else{
		cout<<endl<<"Value NOT found"<<endl;
	}
		cout<<"Linear search required "<<j<<" "<<"loops to find the value "<<num<<"."<<endl;
		cout<<"_____________________________________________________________";
	}

//Binary function begins
void binarysearch(int num){
	int j,first=0, middle, position =-1;
	bool flag;
	const int SIZE=20;
	int last = SIZE-1; 
	cout<<endl<<endl<<"[BINARY SEARCH]"<<endl;	
//begin binary search
	while(!flag && first<=last){
		middle=(first+last)/2;
		j++;  //counter till value found
			if(array[middle]==num){
				flag=true;
				position = middle+1;
				break; //breaking loop since value found
			}
			else if(array[middle]>num){
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
				cout<<"Binary search required "<<j<<" "<<"loops to find the value "<<num<<"."<<endl<<endl<<endl;
			}



//main function
int main(){
int x;

cout<<"Enter a number to search for: ";
cin>>x;


linesearch(x);	//sending variable to line function
binarysearch(x);  //sending 
system("PAUSE");
return 0;	
	
}
