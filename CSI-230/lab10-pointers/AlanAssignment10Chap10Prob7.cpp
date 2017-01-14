//Assignment: #10, Chapter 10, Problem 7
//Name: Alan Thomas
//4/14/2015
//Purpose: Allow for a user to survey
//	   people on how many
//         movies they watch per a month
//	   then calc avg,median, and mode.


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
		ans = ans + (num / 2) + 1;
		cout << "The median is : " << numptr[ans] << endl;
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
		median = median + numptr[ans];
		median = median / 2;
		cout << endl << "The median is: " << median << endl;

	}


}

void mode(int numptr[], int num){
	int number = numptr[0];
	int mode = number;
	int count = 1;
	int countMode = 1;

	for (int i = 1; i<num; i++)
	{
		if (numptr[i] == number)
		{ // count occurrences of the current number
			count++;
		}
		else
		{ // now this is a different number
			if (count > countMode)
			{
				countMode = count; // mode is the biggest ocurrences
				mode = number;
			}
			count = 1; // reset count for the new number
			number = numptr[i];
		}
	}

	cout <<endl<< "mode: " << mode << endl;
}



void avg(int numptr[], int num){
	int total = 0;

	for (int i = 0; i < num; i++){
		total += numptr[i];
	}
	total = total / num;
	cout << endl << "Average: " <<total << endl << endl;
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
		cout << "Enter the score for item #" << j << ": ";
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
	mode(numptr, num);
	median(numptr, num);
	cout << endl;
	avg(numptr, num);

	system("PAUSE");


	delete[] numptr; //garbage handling
	numptr = 0;

	return 0;
}
