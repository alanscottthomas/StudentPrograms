//add the comments he wanted in class



#include <iostream>

using namespace std;
void searchscores(int s[], int size){
int lotto, position;
bool flag=false;
cout<<"Enter the lottery numer to search for: ";
cin>>lotto;

for(int i=0;i<size;i++){
if(lotto==s[i]){
flag=true;
position=i+1;
}
}

if(flag==true){
cout<<endl<<"The Value was found at position# "<<position<<endl;
}
else{
cout<<endl<<"Value NOT found"<<endl;
}
}

int main(){
const int SIZE=10;
int lottery[SIZE]={13579,26791,26792,3345,55555,62483,77777,79422,85647,93121},user=0,i=0;

//cout<<"Enter your five digit pick: ";
//cin>>user;

int temp;
bool flag;

do{
flag=false;
	for(int i=0;i<SIZE-1;i++){                     
		if(lottery[i+1]<lottery[i]){              //swapping larger number to the left, sorting from largest to smallest                                                                           
			temp=lottery[i];
			lottery[i]=lottery[i+1];
			lottery[i+1]=temp;
			flag=true;
			}


}


}while(flag);







searchscores(lottery, SIZE);
system("PAUSE");
return 0;
}

