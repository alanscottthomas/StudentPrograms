#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){
	int i;
	string info[70];
	ifstream file;
	file.open("payroll.txt");
	for(i=0;i<70;i++){
	file>>info[i];
}
	for(i=0;i<70;i++){
	cout<<endl<<info[i];
}
	
}
