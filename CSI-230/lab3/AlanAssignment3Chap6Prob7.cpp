//Alan Thomas
//Assignment#2 2/05/2015
//Chapter6 Problem 7
#include <iostream>
using namespace std;

int i = 1;

//get scores funct
void getScore(int &score){
	int main();
	cout << "score: ";
	cin >> score;
	while (!cin || (score>100) || (score<0)){
		cin.clear();
		cin.ignore();
		cout << "Invald Score." << endl;
		cout << "score: ";
		cin >> score;
	}
}

//find lowest funct
int findLowest(int &score1, int &score2, int &score3, int &score4, int &score5){
	int lowest = 0;

	lowest = score1;
	if (score2 < lowest)
		lowest = score2;
	if (score3 < lowest)
		lowest = score3;
	if (score4 < lowest)
		lowest = score4;
	if (score5 < lowest)
		lowest = score5;

	return lowest;
}

//average determination funct
void calcAverage(int total){
	total = total / 4;
	cout << "The average test score is: " << total << endl;
}

//main funct
int main(){
	int score1 = 0, score2 = 0, score3 = 0, score4 = 0, score5 = 0, total = 0, lowest = 0, average = 0;


	while (i <= 5){
		if (i == 1){
			getScore(score1);
		}
		else if (i == 2){
			getScore(score2);
		}
		else if (i == 3){
			getScore(score3);
		}
		else if (i == 4){
			getScore(score4);
		}
		else if (i == 5){
			getScore(score5);
		}

		i++;
	}
	lowest = findLowest(score1, score2, score3, score4, score5);
	total = score1 + score2 + score3 + score4 + score5 - lowest;
	calcAverage(total);
	system("PAUSE");
}


