#include <iostream>
using namespace std;

int main()
{
	int ans = 50, guess = 0;
	
	cout << "Pick a number between 1-100: ";
	cin >> guess;
	
	while ( guess != ans){
	
		if (guess > ans){
		
			cout << "Guess lower" << endl;
			
	}
		else if (guess < ans)
			cout << "Guess higher" << endl;
			cin >> guess;
}
cout << "Congratulations";			


}
	
