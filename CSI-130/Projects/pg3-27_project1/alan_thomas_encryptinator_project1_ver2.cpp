//Alan Thomas CSI130-01CA Pg.3-27:Project1 09/08/2014
#include <iostream>
using namespace std;

//Start of program, get en/decrypt option from user
int main()
{
    char answer = 0;
    int encrypt();
    int decrypt();
    cout << "*******************************************************" <<endl;
    cout << "*                                                     *" << endl;
    cout << "*                    Encryptinator                    *" << endl;
    cout << "*                       v0.2                          *" << endl;
    cout << "*******************************************************" <<endl;
    cout << "*    '1' to encrypt | '2' to decrypt | '#' to exit    *" <<endl;
    cout << "*******************************************************" <<endl;
    cout << ">";
    cin >> answer;
    //if statement for answer
    if (answer == '1'){
       cout << "\n\n\n==Follow the prompts to begin encrypting==\n\nPound '#' will exit the program.\nThe tilda '~' will bring you to the main menu." << endl << endl << endl << endl;
       cout << "Please enter a phrase to encrypt: " << endl;
       encrypt();
       }
    else if (answer == '#'){
         exit(1);  
         }
    else if (answer == '2'){
        decrypt();
        }
    else{ 
         cout << "Input valid response please." << endl << endl;
         main();
         }
}
    
    // Class to handle encryption
    //ASCII is used to find value of the encryption
    int encrypt(){
    int main();
    char ch;
    
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
               exit(1);
               }
           else if (ch =='~')
                {
               main();
               }     
           else{
              cout << "**UNSUPPORTED VALUE**" <<endl << "Please enter a phrase to encrypt: " << endl << endl;
              }    
              cout << "]";
              encrypt();
    }
}
//Decrypt(ish) class
int decrypt()
{
    cout << "\n\n\n==Follow the prompts to begin decryption.==\n\nPound '#' will exit the program.\nThe tilda '~' will bring you to the main menu." << endl << endl << endl << endl;
    cout << "Enter your phrase to be decyphered(One set of characters at a time): " << endl;
    //name variable and initializing    
    string character_de = "";
    //loop until # sign  
    while (character_de != "#"){
          
          character_de = "";
          cin >> character_de;
          // if else statements for alphabet
          if (character_de == "8")
               cout << "[A]";
          else if (character_de == "9")
               cout <<"[B]";
          else if (character_de == "10")
               cout <<"[C]";
          else if (character_de == "11")
               cout <<"[D]";
          else if (character_de == "12")
               cout <<"[E]";
          else if (character_de == "13")
               cout <<"[F]";
          else if (character_de == "14")
               cout <<"[G]";
          else if (character_de == "15")
               cout <<"[H]";
          else if (character_de == "16")
               cout <<"[I]";
          else if (character_de == "17")
               cout <<"[J]";
          else if (character_de == "18")
               cout <<"[K]";
          else if (character_de == "19")
               cout <<"[L]";
          else if (character_de == "20")
               cout <<"[M]";
          else if (character_de == "21")
               cout <<"[N]";
          else if (character_de == "22")
               cout <<"[O]";
          else if (character_de == "23")
               cout <<"[P]";
          else if (character_de == "24")
               cout <<"[Q]";
          else if (character_de == "25")
               cout <<"[R]";
          else if (character_de == "26")
               cout <<"[S]";
          else if (character_de == "27")
               cout <<"[T]";
          else if (character_de == "28")
               cout <<"[U]";
          else if (character_de == "29")
               cout <<"[V]";
          else if (character_de == "30")
               cout <<"[W]";
          else if (character_de == "31")
               cout <<"[X]";
          else if (character_de == "32")
               cout <<"[Y]";
          else if (character_de == "33")
               cout <<"[Z]";
          else if (character_de == "A")
               cout <<"[.]";
          else if (character_de == "B")
               cout <<"[,]";     
          else if (character_de == "C")
               cout <<"[?]";     
          else if (character_de == "D")
               cout <<"[!]";
          else if (character_de == "#")
               exit(1);          
          else if (character_de == "~")
               main();
          //error handling to let user know to input a different value
          else{     
          cout << "**UNSUPPORTED VALUE**" <<endl << endl << endl;
          }
    cout << endl << "Next set: ";
          }           
    system("PAUSE");
    return 0;
    }
