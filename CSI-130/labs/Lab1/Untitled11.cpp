#include <iostream>
using namespace std;


    int main(){
    
    char ch;
    cout << "Enter a text to have encrypted: " << endl;
    while (ch != '#'){
          char ch;
          int ans;
          cin >> ch;
          
          if (ch >= 65 && ch <= 91)
                 {
                 ans = ch - 65 + 8;
                 cout << "[" << ans;
                 }
          else if ( ch >= 97 && ch <= 'z')
               {
               ans = ch - 97 + 8;
               cout << "[" << ans;
               }
          else if ( ch == '!')
               {
               cout << "[" << "D";
               }
          else if (ch == '.')
               {
               cout << "[" << "A";
               }
          else if (ch == ',')
               {
               cout << "[" << "B";     
               }
          else if (ch == '?')
               {
               cout << "[" << "C";          
               }
          else if (ch =='#')
               {
               return 0;
               }
           else if (ch =='~')
                {
               main();
               }     
           else{
              cout << "INVALID INPUT" <<endl << "Enter text to have encryptedt: " << endl << endl;
              }    
              cout << "]";
              
    }
}
