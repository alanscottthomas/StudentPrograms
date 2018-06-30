#include <iostream>

using namespace std;

int findexp(int, int, int);
int main()
{

int bn, ex,mn,result;

cout<<"Enter base number: ";
cin>>bn;

cout<<"Enter the exponent: ";
cin>>ex;


cout<<"Enter mod: ";
cin>>mn;

result = findexp(bn,ex,mn);

cout<<"result is: "<<result<<endl;


return 0;
}




int findexp(int bn, int ex, int mn)
{
    int num=1;

    for(int i=1; i<=ex; i++)
    {

        num=num*bn;
        num=num-(num/mn)*mn; //

    }

return num;


}
