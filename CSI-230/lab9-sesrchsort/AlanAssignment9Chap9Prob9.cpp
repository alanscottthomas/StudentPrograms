//Assignment: #9, Chapter 9, Problem 9
//Name: Alan Thomas
//4/2/2015
//Purpose: Allow for a user perform
//         sort function and count
//         the number of passes it makes


#include <iostream>

using namespace std;

void bubblesort(int x[],int SIZE){
	int j=0;
	int temp = 0;
		bool flag=true;
		
	do{
		flag = false;
		for (int i = 0; i<SIZE - 1; i++){
			if (x[i + 1]<x[i]){
				temp = x[i];
				x[i] = x[i + 1];
				x[i + 1] = temp;
				flag = true;
				
			}
			
		}
		j++;
	} while (flag);
	cout << "-Sorting first array-" << "It took " << j << " passes." << endl;
	for (int i = 0; i<SIZE; i++){
		cout << x[i] << " ";
	}

	cin.get();
}


void selection(int x[],int SIZE){
	int j = 0;
	int minvalue, minindex;
	for (int i = 0; i<SIZE - 1; i++){
		minvalue = x[i];
		minindex = i;

		for (int index = i + 1; index<SIZE; index++){
			if (x[index]<minvalue){
				minvalue = x[index];
				minindex = index;
			}
			j++;
		}  // close inner loop


		//swapping
		x[minindex] = x[i];
		x[i] = minvalue;
	}  // close outer loop


	cout << endl << "-Sorting second array-"<<" It took " << j <<" passes." << endl;
	for (int i = 0; i<SIZE; i++){
		cout << x[i] << " ";
	}
	cin.get();

}



int main(){
	const int SIZE = 20;
	int one[SIZE] = { 12, 9, 111, 45, 584, 18, 90, 32, 293, 54, 11, 91, 75, 32, 52, 71, 34, 14, 17, 653 };
	int two[SIZE] = { 12, 9, 111, 45, 584, 18, 90, 32, 293, 54, 11, 91, 75, 32, 52, 71, 34, 14, 17, 653 };


	bubblesort(one, SIZE);
	selection(two, SIZE);

	return 0;
}
