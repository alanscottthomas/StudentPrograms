//Alan Thomas CSI130-01CA Pg.3-25:2b 09/08/2014
#include <iostream>
#include <string>
#include <cstdlib>
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
    cout << "*                       v0.1                          *" << endl;
    cout << "* Enter '1' to encrypt | '2' to decrypt | '#' to exit *" << endl;
    cout << "*                                                     *" <<endl;
    cout << "*******************************************************" <<endl;
    cout << ">";
    cin >> answer;
    
    //if statement for answer
    if (answer == '1'){
       encrypt();
       }
    
    else if (answer == '#'){
         exit(1);  
         }
    
    else if (answer == '2'){
        cout << "Feature disabled. Uncomment in code to enable" << endl << endl << endl << endl;
        //decrypt();
        main();
        }
    
    else{ 
         cout << "Input valid response please." << endl << endl;
         main();
         }
    }


//start of encrypt function
int encrypt()
{
    cout << "\n\n\n==Follow the prompts to begin==\n\nPound '#' will exit the program.\nThe tilda '~' will bring you to the main menu." << endl << endl << endl << endl;
    cout << "Please enter a phrase to encrypt: " << endl;
    //name variable and initializing    
    char character;
    character = 0;
    
    //loop until # sign  
    
    while (character != '#'){
          
          character = 0;
          cin >> character;
          // if else statements for alphabet
          if (character == 'a' || character == 'A' )
               cout << "8";
          else if (character == 'b' || character == 'B')
               cout <<"9";
          else if (character == 'c' || character == 'C')
               cout <<"10";
          else if (character == 'd' || character == 'D')
               cout <<"11";
          else if (character == 'e' || character == 'E')
               cout <<"12";
          else if (character == 'f' || character == 'F')
               cout <<"13";
          else if (character == 'g' || character == 'G')
               cout <<"14";
          else if (character == 'h' || character == 'H')
               cout <<"15";
          else if (character == 'i' || character == 'I')
               cout <<"16";
          else if (character == 'j' || character == 'J')
               cout <<"17";
          else if (character == 'k' || character == 'K')
               cout <<"18";
          else if (character == 'l' || character == 'L')
               cout <<"19";
          else if (character == 'm' || character == 'M')
               cout <<"20";
          else if (character == 'n' || character == 'N')
               cout <<"21";
          else if (character == 'o' || character == 'O')
               cout <<"22";
          else if (character == 'p' || character == 'P')
               cout <<"23";
          else if (character == 'q' || character == 'Q')
               cout <<"24";
          else if (character == 'r' || character == 'R')
               cout <<"25";
          else if (character == 's' || character == 'S')
               cout <<"26";
          else if (character == 't' || character == 'T')
               cout <<"27";
          else if (character == 'u' || character == 'U')
               cout <<"28";
          else if (character == 'v' || character == 'V')
               cout <<"29";
          else if (character == 'w' || character == 'W')
               cout <<"30";
          else if (character == 'x' || character == 'X')
               cout <<"31";
          else if (character == 'y' || character == 'Y')
               cout <<"32";
          else if (character == 'z' || character == 'Z')
               cout <<"33";
          else if (character == '.')
               cout <<"A";
          else if (character == ',')
               cout <<"B";     
          else if (character == '?')
               cout <<"C";     
          else if (character == '!')
               cout <<"D";
          
          /* Had difficulty detecting whitespace, read on Google. Tried noskipws and get. Neither provided a satisfactory result
          else if (character == '\n')
               cout <<"SPACE";
          */
          
          else if (character == '#')
               exit(1);          
          else if (character == '~')
               main();
               
          //error handling to let user know to input a different value
          else
              cout << "**UNSUPPORTED VALUE**" <<endl << "Please enter a phrase to encrypt: " << endl << endl;
          cout << " | ";
                 
              }                    
    system("PAUSE");
    return 0;
}




/*
int decrypt()
{
    cout << "==Follow the prompts to begin.==\n\nPound '#' will exit the program.\nThe tilda '~' will bring you to the main menu." << endl << endl << endl << endl;
    cout << "Please enter your phrase to be decyphered(One set of characters at a time): " << endl;
    //name variable and initializing    
    string character_de = "";
    
    
    
    
    //loop until # sign  
    while (character_de != "#"){
          
          character_de = "";
          cin >> character_de;
          // if else statements for alphabet
          if (character_de == "8")
               cout << "A";
          else if (character_de == "9")
               cout <<"B";
          else if (character_de == "10")
               cout <<"C";
          else if (character_de == "11")
               cout <<"D";
          else if (character_de == "12")
               cout <<"E";
          else if (character_de == "13")
               cout <<"F";
          else if (character_de == "14")
               cout <<"G";
          else if (character_de == "15")
               cout <<"H";
          else if (character_de == "16")
               cout <<"I";
          else if (character_de == "17")
               cout <<"J";
          else if (character_de == "18")
               cout <<"K";
          else if (character_de == "19")
               cout <<"L";
          else if (character_de == "20")
               cout <<"M";
          else if (character_de == "21")
               cout <<"N";
          else if (character_de == "22")
               cout <<"O";
          else if (character_de == "23")
               cout <<"P";
          else if (character_de == "24")
               cout <<"Q";
          else if (character_de == "25")
               cout <<"R";
          else if (character_de == "26")
               cout <<"S";
          else if (character_de == "27")
               cout <<"T";
          else if (character_de == "28")
               cout <<"U";
          else if (character_de == "29")
               cout <<"V";
          else if (character_de == "30")
               cout <<"W";
          else if (character_de == "31")
               cout <<"X";
          else if (character_de == "32")
               cout <<"Y";
          else if (character_de == "33")
               cout <<"Z";
          else if (character_de == "A")
               cout <<".";
          else if (character_de == "B")
               cout <<",";     
          else if (character_de == "C")
               cout <<"?";     
          else if (character_de == "D")
               cout <<"!";
          else if (character == '#')
               exit(1);
          else if (character_de == "~")
               main();
          //error handling to let user know to input a different value
          cout << "**UNSUPPORTED VALUE**" <<endl << endl << endl;
          cout << endl << "Next set: ";
          
          }           
                                  

    system("PAUSE");
    return 0;
    
    
}

*/



