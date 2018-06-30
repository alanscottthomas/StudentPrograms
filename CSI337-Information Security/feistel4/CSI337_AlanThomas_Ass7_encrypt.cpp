/*
Name: Alan Thomas
Class: CSI337 - Information Security
Assignment: Feistel Cipher Round 2 Implementation | part 1 of assignment # 7
Professor: Dr. Dutta
Date: 3/6/18
Notes: I noticed that it was working fine if it was a multiple of 12, after some testing I was able to get it to work using a bit of mod math.
*/

//Implementation of Feistel Cipher  with 2 rounds

//libraries//
#include<iostream>
#include<fstream>
#include<cstdlib>
#include<ctime>
#include<bits/stdc++.h>
//--------//

using namespace std;

int *getBinary(int);                                   //function to get binary value of our chars

int main(){
    int length, num, *chararray1, chararray2[8];
    string sentence;
    char *ptr;
    int *ptr1, *ptr2, *ptr3, counter=8, counter2=0, counter3=0, counter4=0, counter5=0, randnum;
    int key[32]={1,0,0,1,0,1,0,1,0,0,0,1,1,0,0,1,0,1,1,1,0,0,0,1,1,0,1,0,1,1,0,1};
    int key1[12], key2[12];
    int leftside[12], rightside[12];
    srand(time(0));

    ifstream input("secret2.txt");                //data to be encrypted
    if(!input){
        cout<<"File not found !";
        return 1;
    }

    ofstream output("key1.txt");               //key1 output
    ofstream output2("cipherbits.txt");      //encrypted data output
    ofstream output3("key2.txt");              //key2 output


    //read data into a string//
    getline(input, sentence);
    length = sentence.size();  //set length to the number of chars from the file
    //-------------------//


    //mod math//
    int mod_value=0;
    int length2=0;
    length2=length*8;          //set l2 to the length * 8 for the number of bits
    //cout<<"length:" <<length<<endl;
   //cout<<"length2:" <<length2<<endl;
    mod_value=(length*8)%12;       //value to store the remainder
    length2=length-mod_value;      //set len2 to len - mod
    //cout<<"length2-remainder:" <<length2<<endl;
    //cout<<"remainder: "<<mod_value<<endl;
   //-----------------//




//only commented the lines that I edited below this//
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
//GENERATE subkey 1 of size 12

    for(int i=0;i<12;i++){
        randnum=rand()%32;
        key1[i]=key[randnum];
    }

    int code=1;    //even / odd
    //copy 12 bits into leftside, XOR with key1, place next 12 into rightside then swap the two

    for(int i=0;i<(length*8)-mod_value;i++){               //subtracting the remainder from length*8
       if(code%2!=0){
        leftside[counter4] = ptr1[i];
        counter4++;
         if(counter4%12==0){

            for(int j=0;j<12;j++){
                leftside[j]=leftside[j]^key1[j];
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



//write key1 to file

for(int i=0;i<12;i++){
    output<<key1[i]<<endl;
  }


  // *****    R   O   U   N   D       T   W   O  ********

counter5=0;
  //GENERATE subkey 2 of size 12

    for(int i=0;i<12;i++){
        randnum=rand()%32;
        key2[i]=key[randnum];
    }

    code=1;    //even / odd
    //copy 12 bits into leftside, XOR with key1, place next 12 into rightside then swap the two

    for(int i=0;i<(length*8)-mod_value;i++){               //subtracting the remainder from length*8
       if(code%2!=0){
        leftside[counter4] = ptr2[i];
        counter4++;
         if(counter4%12==0){

            for(int j=0;j<12;j++){
                leftside[j]=leftside[j]^key2[j];
            }

            counter4=0;
            code++;
        }
       }
        else if(code%2==0){
        rightside[counter4]=ptr2[i];
        counter4++;

        if(counter4%12==0){
                for(int j=0;j<12;j++){
                    ptr3[counter5]=rightside[j];
                    counter5++;
                }

                for(int j=0;j<12;j++){
                    ptr3[counter5]=leftside[j];
                    counter5++;
                }
        counter4=0;
         code++;
        }
     }

    }  // loop end -->


  //  ******    Read back ptr3   ********************



    for(int i=0;i<length*8;i++){
        if(i%8==0){
            cout<<endl;
        }
        cout<<ptr3[i]<<" ";

    }



 for(int i=0;i<length*8;i++){
        output2<<ptr3[i]<<" ";
   }

//write key2 to file

for(int i=0;i<12;i++){
    output3<<key2[i]<<endl;
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
