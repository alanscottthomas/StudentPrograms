/*
Name: Alan Thomas
Class: CSI337 - Information Security
Assignment: Feistel Cipher Round 2 Implementation | part 1 of assignment # 6
Professor: Dr. Dutta
Date: 2/15/18
Notes: No notes.
*/

//Libraries//
#include<iostream>
#include<fstream>
#include<cstdlib>
#include<ctime>
#include<bits/stdc++.h>
//-------------//
using namespace std;
int *getBinary(int);                 //function to get binary numbers for our chars

int main(){

    int length, num, *chararray1, chararray2[8];
    string sentence;
    char *ptr;
    int *ptr1, *ptr2, *ptr3, counter=8, counter2=0, counter3=0, counter5=0, randnum;
    int key[32]={1,0,0,1,0,1,0,1,0,0,0,1,1,0,0,1,0,1,1,1,0,0,0,1,1,0,1,0,1,1,0,1};
    int key1[24];
    int key2[24];
    srand(time(0));

    ifstream input("secret2.txt");
    if(!input){
        cout<<"File not found !";
        return 1;
    }

    getline(input, sentence);
    length = sentence.size();

    input.clear();
    input.seekg(0, ios::beg);

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

    for(int i=0;i<counter2;i++){
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

    } // end outer loop


// ***************  ENCRYPTION ROUND 1 *********************
//GENERATE subkey 1 of size 24

    for(int i=0;i<24;i++){
        randnum=rand()%32;
        key1[i]=key[randnum];
    }

//Create cipher array ptr2 by XORing ptr1 with subkey1, 24 bits at a time

    for(int i=0;i<length*8;i++){
        ptr2[i]=ptr1[i]^key1[counter5];  // xoring with the key
        counter5++;
        if(counter5%24==0){  //reset counter5 to 0 to restart XORing next 24 bits with key array
            counter5=0;
        }
   }

//--------round 2--//
//Generate another subkey of size 24 and XOR with ptr2
//place cipher into ptr3;

//GENERATE subkey 2 of size 24

    for(int i=0;i<24;i++){
        randnum=rand()%32;
        key2[i]=key[randnum];
    }

//Create cipher array ptr3 by XORing ptr2 with subkey2, 24 bits at a time

    for(int i=0;i<length*8;i++){
        ptr3[i]=ptr2[i]^key2[counter5];  // xoring with the key
        counter5++;
        if(counter5%24==0){  //reset counter5 to 0 to restart XORing next 24 bits with key array
            counter5=0;
        }
   }
//------end round 2--///


cout<<"--ROUND 1--"<<endl;
//read ptr2 array
    for(int i=0;i<length*8;i++){
        if(i%8==0){
            cout<<endl;
        }
        cout<<ptr2[i]<<" ";
    }
cout<<endl<<"--PRESS ENTER TO EXECUTE ROUND 2--"<<endl;
cin.get();
cout<<endl<<"--ROUND 2--"<<endl;

    //read ptr3 array
    for(int i=0;i<length*8;i++){
        if(i%8==0){
            cout<<endl;
        }
        cout<<ptr3[i]<<" ";
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
    ptr3=0;
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
