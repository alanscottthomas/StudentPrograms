#include <iostream>

using namespace std;

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

int main(){
	const int SIZE = 5;
	bool flag;
	int temp, temp2;
	Inventory New[SIZE];
	New[0].setquantity(5);
	New[1].setquantity(1);
	New[2].setquantity(8);
	New[3].setquantity(4);
	New[4].setquantity(2);

	
	do{
		flag = false;
		for (int i = 0; i<SIZE - 1; i++){
			if (New[i + 1].getquantity()<New[i].getquantity()){
				temp = New[i].getquantity();
				temp2 = New[i + 1].getquantity();
				New[i].setquantity(temp2);
				New[i + i].setquantity(temp);
				temp = 0;
				temp2 = 0;
				flag = true;
			}
		}
	} while (flag);




	for (int i = 0; i<SIZE - 1; i++){
		cout << endl << New[i].getquantity();
	}

	return 0;
}













