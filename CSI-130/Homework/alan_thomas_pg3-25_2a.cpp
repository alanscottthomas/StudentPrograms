//Alan Thomas CSI130-01CA Pg.3-25:2a 09/08/2014
#include <iostream>

using namespace std;

int main()
{
    int n = 0, ans = 0;
    cout << "Enter an integer." << endl;
    cin >> n;
    ans = n % 2;
    
    if ( ans == 0) {
       cout << "Even";
       }
    else {
         cout << "Odd";
         }
    
    return 0;
}
       
    
    
