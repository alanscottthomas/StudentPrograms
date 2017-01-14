#include <iostream>
using namespace std;

int main(){
    int voters = 0, yes = 0, no = 0, undecided = 0, answer = 0;
    cout << "Florida State Voting Engine Copyright 2000." <<endl;
    cout << "Enter the number of voters: " << endl;
    cin >> voters;
    
    while ( voters > 0){
          cout << "Yes = 1 , No = 2, Undecided = 3" << endl << "Cast your vote: ";
          cin >> answer;
          
          if (answer == 1){
                     yes = yes + 1;
                     }
          else if (answer == 2){
               no = no + 1;
               }
          else if (answer == 3){
               undecided = undecided + 1;
               }
          voters = voters - 1;
          }
cout << "Voters that said YAY: " << yes<<endl;
cout << "Voters that said NAY: " << no << endl;
cout << "Voters that were UNDECIDED: " << undecided << endl<< endl<< endl<< endl;

if (yes > no){
        cout << "This item passed!" << endl;
        }
else if (no > yes){
     cout << "This item did not pass :(" << endl;
     }
else if (yes == no){
     cout << "This item tied." << endl;
     }
     system("PAUSE");
}

