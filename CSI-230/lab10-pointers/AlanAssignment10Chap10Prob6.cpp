//Assignment: #10, Chapter 10, Problem 6
//Name: Alan Thomas
//4/14/2015
//Purpose: Allows user to sort an array of values
//         and determine the median of the sorted array




#include <iostream>
#include <cstdlib> //pause
using namespace std;


//sorting function
void bubble(int numptr[], int num){
	int temp;
	bool flag;

	cout << "-VALUES IN ASCENDING ORDER-" << endl;
	do{
		flag = false;

		for (int i = 0; i<num - 1; i++){
			if (numptr[i + 1]<numptr[i]){
				temp = numptr[i];
				numptr[i] = numptr[i + 1];
				numptr[i + 1] = temp;
				flag = true;
			}
		}

	} while (flag);

	for (int i = 0; i<num; i++){
		cout << numptr[i] << endl;
	}
}

void median(int numptr[], int num){
	int ans = 0, ans2 = 0;
	

	cout << endl;
	//number of values is odd
	if (num % 2 == 1){
		ans = ans+ (num / 2) + 1;
		cout << "The median is : "<<numptr[ans]<<endl;
	}
	//values default to even
	else{
		ans = num + 1;
		double ans_;
		double median = 0;
		ans_ = ans / 2;
		ans = ans_ - .5;
		median = numptr[ans];
		ans = 0;
		ans = ans_ + .5;
		median =median+numptr[ans];
		median = median / 2;
		cout << endl <<"The median is: "<< median << endl;
		
	}


}


//main function
int main(){
	int num, j = 1;


	//reading in user information
	cout << "Number of values: ";
	cin >> num;
	while (num < 0){
		cout << "INVALID input" << endl;
		cout << "Number of values: ";
		cin >> num;
	}


	int *numptr; //creating num pointer

	numptr = new int[num];  //allocation
	//Loop gathering scores from user
	for (int i = 0; i < num; i++){
		cout << "Enter the value for item #" << j << ": ";
		cin >> numptr[i];
		while (numptr[i] < 0){
			cout << "-INVALID INPUT-" << endl;
			cout << "Enter the value for item #" << j << ": ";
			cin >> numptr[i];
		}
		j++;
	}

	//sending scoresptr to bubblesort function
	bubble(numptr, num);

	//sending scoresptr array to average function
	median(numptr, num);
	system("PAUSE");


	delete[] numptr; //garbage handling
	numptr = 0;

	return 0;
}
