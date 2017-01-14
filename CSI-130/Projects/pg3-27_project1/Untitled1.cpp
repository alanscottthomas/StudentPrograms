#include <iostream>
using namespace std;

int main()
{
    char ch;
    int ans;
    cin >> ch;
    
    while (ch != '#')
    {
          
          
          if (ch >= 65 && ch <= 91)
                 {
                 ans = ch - 65 + 8;
                 cout << " | " << ans;
                 }
          else if ( ch >= 97 && ch <= 'z')
               {
               ans = ch - 97 + 8;
               cout << " | " << ans;
               }
          else if ( ch == '!')
               {
               cout << " | " << "D";
               }
               
               main();
               cout << endl;
               
    }

}
    

