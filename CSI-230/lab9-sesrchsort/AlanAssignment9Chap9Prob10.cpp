//Assignment: #9, Chapter 9, Problem 9
//Name: Alan Thomas
//4/2/2015
//Purpose: Allow for a user perform
//         bubble sort and selection search
//         functions to sort an array


#include <iostream>

using namespace std;

void bubblesort(int x[],int SIZE){
	int j=0;
	int temp = 0;
		bool flag=true;
		
	do{
		flag = false;
		for (int i = 0; i<SIZE - 1; i++){
			for(j=0;j<SIZE;j++){
			cout<<x[j]<<" ";
			}
			cout<<endl;
			if (x[i + 1]<x[i]){
				
				temp = x[i];
				x[i] = x[i + 1];
				x[i + 1] = temp;
				flag = true;
				
			}
			
		cout<<x[i]<<" ";
		}
		
	} while (flag);

cout<<endl<<"-END SORT-"<<endl;
	cin.get();
}


void selection(int x[],int SIZE){
	int j = 0;
	int minvalue, minindex;
	for (int i = 0; i<SIZE - 1; i++){
		minvalue = x[i];
		minindex = i;

		for (int index = i + 1; index<SIZE; index++){
			for(j=0;j<SIZE;j++){
			cout<<x[j]<<" ";
			}
			
			cout<<endl;
			if (x[index]<minvalue){
				minvalue = x[index];
				minindex = index;
			
			}
		
			
		
		}  // close inner loop


		//swapping
		x[minindex] = x[i];
		x[i] = minvalue;
		
	}  // close outer loop

cout<<endl<<"-END SORT-"<<endl;

	cin.get();

}



int main(){
	const int SIZE = 8;
	int one[SIZE] = { 12, 9, 111, 45, 584, 18, 90, 32};
	int two[SIZE] = { 12, 9, 111, 45, 584, 18, 90, 32};

	//printing array one
	cout<<"-ARRAY ONE UNSORTED--"<<endl;
	for(int i=0;i<SIZE;i++){
		cout<<one[i]<<" ";
	}
cout<<endl<<endl<<"-SORTING ARRAY 1-"<<endl;
	//sending array one to bubble function
	bubblesort(one, SIZE);
	//printing unsorted array two
	cout<<endl<<"-ARRAY TWO UNSORTED--"<<endl;
	for(int i=0;i<SIZE;i++){
		cout<<two[i]<<" ";
	}
	cout<<endl<<endl<<"-SORTING ARRAY 2-"<<endl;
	//sending array 2 to function
	selection(two, SIZE);

	return 0;
}
