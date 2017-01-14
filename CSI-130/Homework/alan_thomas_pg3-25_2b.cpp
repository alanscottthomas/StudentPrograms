//Alan Thomas CSI130-01CA Pg.3-25:2b 09/08/2014
#include <iostream>

using namespace std;

int main()
{
    char character = 0;
    cout << "Enter a character to encrypt:" << endl;
    cin >> character;
    cout << "Running encryption engine utilizing 1bit Blowfish" << endl;
    
    if (character == "A"){
                  cout << "8";
                  }
    
    system("PAUSE");
    return 0;
    
}
