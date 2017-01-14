//Alan Thomas
//Assignment#4 2/19/2015
//Chapter6 Problem 11


#include <iostream>
using namespace std;
//Profit Function
void Profit(double NS, double SP, double SC, double PP, double PC){
     double profit;
     profit = ((NS*SP)-SC)-((NS*PP)*PC);
     if(profit>=0)
     cout<<endl<<"You made a gain of: $"<<profit<<endl;
     if(profit<0)
     cout<<endl<<"You lost: $"<<profit<<endl;
     system("PAUSE");
     }
//Begin Main function     
int main(){
double NS;
double SP,SC,PP,PC;

cout<<"Number of shares: ";
cin>>NS;
cout<<endl<<"Sale price per a share: ";
cin>>SP;
cout<<"Sale commission paid: ";
cin>>SC;
cout<<endl<<"Purchase price per a share: ";
cin>>PP;
cout<<"Purchase commission paid: ";
cin>>PC;

Profit(NS,SP,SC,PP,PC);    
return 0;
}
