#include <iostream>
#include <cstdlib> //pause
using namespace std;


//sorting function
void bubble(int *scoresptr[], int size){
	int temp;
	bool flag;

	cout << "-SCORES IN ASCENDING ORDER-" << endl;
	do{
		flag = false;

		for (int i = 0; i<size - 1; i++){
			if (scoresptr[i + 1]<scoresptr[i]){
				temp = *scoresptr[i];
				scoresptr[i] = scoresptr[i + 1];
				*scoresptr[i + 1] = temp;
				flag = true;
			}
		}

	} while (flag);

	for (int i = 0; i<size; i++){
		cout << scoresptr[i] << endl;
	}
}

void avg(int scores[], int size){
	int total = 0;

	for (int i = 0; i < size; i++){
		total += scores[i];
	}
	total = total / size;
	cout << endl << "-THE AVERAGE IS-" << endl << total << endl << endl;
}


//main function
int main(){
	int scores, j = 1;


	//reading in user information
	cout << "Number of scores: ";
	cin >> scores;
	while (scores < 0){
		cout << "INVALID input" << endl;
		cout << "Number of scores: ";
		cin >> scores;
	}


	int *scoresptr; //creating scores pointer

	scoresptr = new int[scores];  //allocation
	//Loop gathering scores from user
	for (int i = 0; i < scores; i++){
		cout << "Enter the score for item #" << j << ": ";
		cin >> scoresptr[i];
		while (scoresptr[i] < 0){
			cout << "-INVALID INPUT-" << endl;
			cout << "Enter the score for item #" << j << ": ";
			cin >> scoresptr[i];
		}
		j++;
	}

	//sending scoresptr to bubblesort function
	bubble(&scoresptr, scores);

	//sending scoresptr array to average function
	avg(scoresptr, scores);
	system("PAUSE");


	delete[] scoresptr; //garbage handling
	scoresptr = 0;

	return 0;
}
