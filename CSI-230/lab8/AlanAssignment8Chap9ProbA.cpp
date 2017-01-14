//Assignment: #8, Chapter 9, Problem A
//Name: Alan Thomas
//3/24/2015
//Purpose: Allow for a user to search a class for a value
//         utilizing binary search.


#include <iostream>

using namespace std;
//inventory class start
class Inventory{
private:
	int quantity;
public:
	void setquantity(int q);
	int getquantity();
};
void Inventory::setquantity(int q){
	quantity = q;
}

int Inventory::getquantity(){
	return quantity;
}


//begin execution
int main(){
	const int SIZE = 5;
	bool flag;
	int temp, temp2,search, first=0, middle, position =-1;;
    int last =SIZE-1;   
	Inventory New[SIZE];
	//setting values
    New[0].setquantity(5);
	New[1].setquantity(8);
	New[2].setquantity(1);
	New[3].setquantity(4);
	New[4].setquantity(2);

	flag = 0;
	//Sorting begin
    //Could of just set quantities in order but needed the practice
    do{
		flag = false;
		for (int i = 0; i < SIZE - 1; i++){
			if (New[i + 1].getquantity() < New[i].getquantity()){
				temp = New[i].getquantity();
				New[i].setquantity(New[i + 1].getquantity());
				New[i + 1].setquantity(temp);
				flag = true;
			}
   }
	} while (flag);


      //printing sorted array to ensure sort completed correctly.       
     /*
	for (int i = 0; i<SIZE; i++){
		cout << " " << New[i].getquantity();
	}*/
	
	
	//prompting user for input
    cout<<endl<<"Enter a quantity to search for: ";
    cin>>search;

//begin binary search
	while(!flag && first<=last){
	  middle=(first+last)/2;
		if(New[middle].getquantity()==search){
		flag=true;
		position = middle+1;
	}
		else if(New[middle].getquantity()>search){
     		last = middle-1;
     	}
		else{first=middle+1;}
	}


 	if(flag){
          cout<<"Number was found at position# "<<position<<endl;
          }
          else{
          	cout<<"Number was NOT found"<<endl;
    }

system("PAUSE");
	return 0;
}








