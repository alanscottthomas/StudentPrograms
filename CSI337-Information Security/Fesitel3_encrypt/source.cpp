//Feistel Cipher with only one round of XORing and swapping

#include<iostream>
#include<fstream>
#include<cstdlib>
#include<ctime>
#include<bits/stdc++.h>
using namespace std;

int *getBinary(int);

int main(){
    int length, num, *chararray1, chararray2[8];
    string sentence,sentence2;
    char *ptr,*ptr_key;
    int *ptr1, *ptr2, *ptr3, counter=8, counter2=0, counter3=0, counter4=0, counter5=0, randnum;
    //int key[32]={1,0,0,1,0,1,0,1,0,0,0,1,1,0,0,1,0,1,1,1,0,0,0,1,1,0,1,0,1,1,0,1};  //should be kept in a secret notepad file
    int key[32]={0};
    int key1[12];
    int key2[12];
    int leftside[12], rightside[12];
    srand(time(0));

    ifstream input("secret2.txt");
    ifstream input2("key.txt");


    if(!input){
        cout<<"File not found !";
        return 1;
    }

    ofstream output("key1.txt");
    ofstream output3("key2.txt");
    ofstream output2("cipherbits.txt");

    getline(input, sentence);
    length = sentence.size();


    input.clear();
    input.seekg(0, ios::beg);

    //--GET KEY FILE LOGIC--//
//while loop to read key.txt//
while (getline(input2, sentence2))
    {
            while (sentence2[counter5] != '\0')
            {
                counter5++;
            }
	}
//---------------------------//

    ptr_key= new char[counter5];
    input2.clear();
    input2.seekg(0, ios::beg);

	//while loop to read sentence2 into ptr_key//

		for (int i=0;i<counter5;i++)                       //do for size of sentence2
            {
                ptr_key[i] = sentence2[i];                 //populate ptr key array
            }


//placing 1/0 in key array depending on the ASCII value or ptr. Kind of lazy, but it works.
for(int i =0;i<counter5;i++)
{
    if(ptr_key[i]==48)
    {
        key[i]=0;
    }

     else
    {
        key[i]=1;
    }
}
//--------END GET KEY FILE LOGIC-------------//

    counter5=0;
    input2.clear();
    input2.seekg(0, ios::beg);

    ptr = new char[length];
    ptr1= new int[8*length];
    ptr2= new int[8*length];
    ptr3= new int[8*length];

    while(getline(input, sentence)){
        while(sentence[counter2]!='\0'){
            ptr[counter2]=sentence[counter2];    //populate array ptr with characters
            counter2++;
      }
    }

    chararray1= new int[8];

int round=0;

//convert to binary and flip//
while(round<2)
{
    cout<<endl<<"Round: "<<round+1<<endl;
    if(round==0)
    {
        for(int i=0;i<counter2;i++)
            {
            num=(int)ptr[i];
            chararray1=getBinary(num);

        //copy chararray1 to chararray2
        for(int j=0;j<counter;j++){
            chararray2[j]=chararray1[j];
        }

        //flip the values in chararray1
        for(int k=0;k<counter;k++){
            chararray1[k]=chararray2[counter-1-k];
            ptr1[counter3]=chararray1[k];  //feeding into ptr1 bits from chararray1
            counter3++;
        }
            }
    counter3=0;


    }

    else
        {
        for(int i=0;i<counter2;i++)
        {

        //flip the values in chararray1
        for(int k=0;k<counter;k++)
            {
                chararray1[k]=chararray2[counter-1-k];
                ptr1[counter3]=chararray1[k];  //feeding into ptr1 bits from chararray1
                counter3++;
            }
        }
    }
//round++;
//}

//-----------------//


// ***************  ENCRYPTION *********************
//GENERATE subkey of size 12

//randnum=rand()%32;
        for(int i=0;i<12;i++)
            {
                if(round==0)
                {
                    randnum=rand()%32;
                    key1[i]=key[randnum];
                }

                else
                {
                    randnum=rand()%32;
                    key2[i]=key[randnum];
                }

            }


     int code=1;    //even / odd
    //copy 12 bits into array leftside, XOR with key1, place next 12 bits into rightside, then swap the two

    for(int i=0;i<length*8;i++){
       if(code%2!=0){
        leftside[counter4] = ptr1[i];
        counter4++;
         if(counter4%12==0){

            for(int j=0;j<12;j++){
                if(round==0)
                {
                    leftside[j]=leftside[j]^key1[j];
                }
                else
                {
                    leftside[j]=leftside[j]^key2[j];
                }
            }

            counter4=0;
            code++;
        }
       }
        else if(code%2==0){
        rightside[counter4]=ptr1[i];
        counter4++;

        if(counter4%12==0){
                for(int j=0;j<12;j++){
                    ptr2[counter5]=rightside[j];
                    counter5++;
                }

                for(int j=0;j<12;j++){
                    ptr2[counter5]=leftside[j];
                    counter5++;
                }
        counter4=0;
         code++;
        }
     }

    }  // loop end -->

    counter5=0;
//read ptr2 array
    for(int i=0;i<length*8;i++){
        if(i%8==0){
            cout<<endl;
        }
        cout<<ptr2[i]<<" ";
         counter5++;
    }

if(round!=0)
{
   for(int i=0;i<length*8;i++){
        output2<<ptr2[i]<<" ";
   }
}




//write key1 to file

for(int i=0;i<12;i++){
    if(round==0)
    {
        output<<key1[i]<<endl;
    }
    else
    {
        output3<<key2[i]<<endl;
    }
  }

counter5=0;
round++;
}



//deallocate heap memory
    delete [] ptr;
    delete [] ptr1;
    delete [] ptr2;
    delete [] ptr3;
    delete [] chararray1;
    ptr=0;
    ptr1=0;
    ptr2=0;
    chararray1=0;

return 0;
}

int *getBinary(int num){
int rem, counter=0;
int *ptr6;

ptr6 = new int[8];  //allocate an array of size 8

//finding the binary equivalent of num;

while(num>0){
    rem=num%2;
    num=num/2;
    ptr6[counter]=rem;
    counter++;
}

if(counter==6){
    ptr6[6]=0;
    ptr6[7]=0;
}
else if(counter==7){
    ptr6[7]=0;
}

return ptr6;
}
