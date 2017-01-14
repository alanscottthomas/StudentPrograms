/* AUTHOR Alan Thomas.
DATE CODED 2 / 20 / 2016.
THIS PROGRAM WILL ACCEPT INPUT FROM A USER IN ORDER
TO DETERMINE ADDITION,SUBTRACTION,MULTIPLICATION, OR THE TRANSPOSE
OF A MATRIX. DETERMINANT AND INVERSE WERE EXCLUDED DUE TO THEIR
COMPLEXITY EXCEEDING WHAT I UNDERSTAND HOW TO CODE.
I HAD A FAIR BIT OF ISSUES WITH THE MULTIPLICATION FUNCTION GOING OUT OF BOUNDS,
AFTER SOME TWEAKING I WAS ABLE TO RESOLVE THIS ISSUE*/



#include <iostream>
#include <windows.h>
#include <fstream>



using namespace std;

const int MAX_SIZE = 11; // INCREASED SIZE BY ONE TO REMEMEDY OUT OF BOUNDS ISSUES. I BELIEVE THEY ARE ARRAY RELATED, BUT WAS UNABLE TO RESOLVE THEM WITH SIZE AT 10


//****I felt it was socially irresponsible to not have the scrolling Matrix code, the scrolling effect is not my code****
//***courtesy of http://xoax.net/***
int Modulus(int iN, int iMod) {
	int iQ = (iN / iMod);
	return iN - (iQ*iMod);
}

char GetChar(int iGenerator, char cBase, int iRange) {
	return (cBase + Modulus(iGenerator, iRange));
}

int quit() { //PUT THIS CODE INTO THE QUIT FUNCTION SO IT DISPLAYS WHEN THE USER EXITS, IT SERVES ABSOLUTELY NO PURPOSE, BUT IT LOOKS AWESOME!
	// Color code
	system("cls");
	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 10);
	int z = 0;
	cout << "Exiting The Matrix Calculator...";
	Sleep(2500);

	char caRow[80];
	int j = 7;
	int k = 2;
	int l = 5;
	int m = 1;
	while (true) {
		int i = 0;
		// Output a random row of characters
		while (i < 80) {
			if (caRow[i] != ' ') {
				caRow[i] = GetChar(j + i*i, 33, 30);
				if (((i*i + k) % 20) == 0) {
					SetConsoleTextAttribute(hConsole, 7);
				}
				else {
					SetConsoleTextAttribute(hConsole, 10);
				}
			}
			std::cout << caRow[i];
			++i;
			SetConsoleTextAttribute(hConsole, 10);
		}
		j = (j + 31);
		k = (k + 17);
		l = (l + 47);
		m = (m + 67);
		caRow[Modulus(j, 80)] = '-';
		caRow[Modulus(k, 80)] = ' ';
		caRow[Modulus(l, 80)] = '-';
		caRow[Modulus(m, 80)] = ' ';
		// Delay
		Sleep(30);
		z++;
		if (z == 150){
			exit(1);
		}
	}
}
//****END MATRIX CODE****


//********ADDING FUNCTION************
void adding(float a_row, float a_column, float b_row, float b_column){
	float ar = a_row, ac = a_column, br = b_row, bc = b_column;
	float c[100][100]; //ideally would have used vectors
	float a_matrix[100][100], b_matrix[100][100];
	int i_row = 1; //counter setting to 1 to make the matrix information more user friendly, as not everyone starts counting from 0.
	int i_column = 1;
	cout << endl;

	//getting matrix A values
	for (i_row = 1; i_row <= ar; i_row++){
		for (i_column = 1; i_column <= ac; i_column++){
			cout << "What is the value of matrix A row " << i_row << " " << "column " << i_column << ": ";
			cin >> a_matrix[i_row][i_column];
			//checking for valid input
			while (!cin){
				cin.clear();
				cout << "--Invalid input - please enter a number only.--" << endl;
				cin.ignore();
				cout << "What is the value of matrix A row " << i_row << " " << "column " << i_column << ": ";
				cin >> a_matrix[i_row][i_column];
			}
			cout << endl;
		}
	}

	//getting matrix B values
	for (i_row = 1; i_row <= br; i_row++){
		for (i_column = 1; i_column <= bc; i_column++){
			cout << "What is the value of matrix B row " << i_row << " " << "column " << i_column << ": ";
			cin >> b_matrix[i_row][i_column];
			while (!cin){
				cin.clear();
				cout << "--Invalid input - please enter a number only.--" << endl;
				cin.ignore();
				cout << "What is the value of matrix B row " << i_row << " " << "column " << i_column << ": ";
				cin >> b_matrix[i_row][i_column];
			}
			cout << endl;
		}
	}
	i_row = 1;
	i_column = 1;

	//A+B=C Loop
	cout << "Your matrices added together results in this matrix: " << endl;
	for (i_row = 1; i_row <= ar; i_row++){
		cout << endl;

		for (i_column = 1; i_column <= ac; i_column++){
			c[i_row][i_column] = a_matrix[i_row][i_column] + b_matrix[i_row][i_column];
			cout << " | " << c[i_row][i_column] << " | ";
		}
	}
	cout << endl << endl;
	cin.clear();
	cin.ignore();
	cout << "-Press ENTER to return to the title screen-";
	cin.get();
	system("cls");
}
//*********END ADD FUNCTION**************


//********SUBTRACTION FUNCTION************
void subtraction(float a_row, float a_column, float b_row, float b_column){
	float ar = a_row, ac = a_column, br = b_row, bc = b_column;
	float c[100][100]; //could use vectors to determine size of c, but been a while and don't remember how to use them
	float a_matrix[100][100], b_matrix[100][100];
	int i_row = 1; //counter setting to 1 to make the matrix information more user friendly, as not everyone starts counting from 0.
	int i_column = 1;
	cout << endl;

	//getting matrix A values
	for (i_row = 1; i_row <= ar; i_row++){
		for (i_column = 1; i_column <= ac; i_column++){
			cout << "What is the value of matrix A row " << i_row << " " << "column " << i_column << ": ";
			cin >> a_matrix[i_row][i_column];
			//checking for valid input
			while (!cin){
				cin.clear();
				cout << "--Invalid input - please enter a number only.--" << endl;
				cin.ignore();
				cout << "What is the value of matrix A row " << i_row << " " << "column " << i_column << ": ";
				cin >> a_matrix[i_row][i_column];
			}
			cout << endl;
		}
	}

	//getting matrix B values
	for (i_row = 1; i_row <= br; i_row++){
		for (i_column = 1; i_column <= bc; i_column++){
			cout << "What is the value of matrix B row " << i_row << " " << "column " << i_column << ": ";
			cin >> b_matrix[i_row][i_column];
			while (!cin){
				cin.clear();
				cout << "--Invalid input - please enter a number only.--" << endl;
				cin.ignore();
				cout << "What is the value of matrix B row " << i_row << " " << "column " << i_column << ": ";
				cin >> b_matrix[i_row][i_column];
			}
			cout << endl;
		}
	}
	i_row = 1;
	i_column = 1;
	//A-B=C Loop
	cout << "Matrix A minus B results in this matrix: " << endl;
	for (i_row = 1; i_row <= ar; i_row++){
		cout << endl;

		for (i_column = 1; i_column <= ac; i_column++){
			c[i_row][i_column] = a_matrix[i_row][i_column] - b_matrix[i_row][i_column];
			cout << " | " << c[i_row][i_column] << " | ";
		}
	}
	cout << endl << endl;
	cin.clear();
	cin.ignore();
	cout << "-Press ENTER to return to the title screen-";
	cin.get();
	system("cls");
}
//*********END SUBTRACTION FUNCTION**************


//********MULTIPLICATION FUNCTION************
void multiplication(float a_row, float a_column, float b_row, float b_column){
	float ar = a_row, ac = a_column, br = b_row, bc = b_column;
	float c[100][100];
	float a_matrix[100][100], b_matrix[100][100];
	int a_row_ = 1; //counter setting to 1 to make the matrix information more user friendly, as not everyone starts counting from 0.
	int a_column_ = 1;
	int b_column_ = 1;
	int b_row_ = 1; //counter setting to 1 to make the matrix information more user friendly, as not everyone starts counting from 0.
	int i_column = 1;
	int i_row = 1;

	cout << endl;

	//getting matrix A values
	for (i_row = 1; i_row <= ar; i_row++){
		for (i_column = 1; i_column <= ac; i_column++){
			cout << "What is the value of matrix A row " << i_row << " " << "column " << i_column << ": ";
			cin >> a_matrix[i_row][i_column];
			//checking for valid input
			while (!cin){
				cin.clear();
				cout << "--Invalid input - please enter a number only.--" << endl;
				cin.ignore();
				cout << "What is the value of matrix A row " << i_row << " " << "column " << i_column << ": ";
				cin >> a_matrix[i_row][i_column];
			}
			cout << endl;
		}
	}

	//getting matrix B values
	for (i_row = 1; i_row <= br; i_row++){
		for (i_column = 1; i_column <= bc; i_column++){
			cout << "What is the value of matrix B row " << i_row << " " << "column " << i_column << ": ";
			cin >> b_matrix[i_row][i_column];
			while (!cin){
				cin.clear();
				cout << "--Invalid input - please enter a number only.--" << endl;
				cin.ignore();
				cout << "What is the value of matrix B row " << i_row << " " << "column " << i_column << ": ";
				cin >> b_matrix[i_row][i_column];
			}
			cout << endl;
		}
	}
	int i = 1, j = 1, k = 1;

	//A*B=C Loop
	cout << "Matrix A multiplied by B results in this matrix: " << endl;
	for (i = 1; i <= ar; i++)
	{
		for (j = 1; j <= bc; j++)
		{
			c[i][j] = 0;
			for (k = 1; k <= br; k++)
			{
				c[i][j] = c[i][j] + a_matrix[i][k] * b_matrix[k][j];
			}
		}
	}
	for (i = 1; i <= ar; i++){
		cout << endl;
		for (k = 1; k <= ac; k++){
			cout << " | " << c[i][k] << " | ";
		}
	}
	cout << endl << endl;
	cin.clear();
	cin.ignore();
	cout << "-Press ENTER to return to the title screen-";
	cin.get();
	system("cls");
}
//*********END MULTIPLICATION FUNCTION**************


//********TRANPOSE FUNCTION************
void transpose(float a_row, float a_column){
	float ar = a_row, ac = a_column;
	float c[100][100];
	float a_matrix[100][100];
	int i_column = 1;
	int i_row = 1;

	cout << endl;

	//getting matrix A values
	for (i_row = 1; i_row <= ar; i_row++){
		for (i_column = 1; i_column <= ac; i_column++){
			cout << "What is the value of your matrix row " << i_row << " " << "column " << i_column << ": ";
			cin >> a_matrix[i_row][i_column];
			//checking for valid input
			while (!cin){
				cin.clear();
				cout << "--Invalid input - please enter a number only.--" << endl;
				cin.ignore();
				cout << "What is the value of your matrix row " << i_row << " " << "column " << i_column << ": ";
				cin >> a_matrix[i_row][i_column];
			}
			cout << endl;
		}
	}
	cout << endl;

	int i = 1, j = 1, k = 1;

	//TRANSPOSE LOOP
	cout << "Your matrix transposed results in this matrix: " << endl;
	for (i = 1; i <= ar; i++)
	{
		for (j = 1; j <= ac; j++)
		{
			c[i][j] = 0;
			for (k = 1; k <= ar; k++)
			{
				c[i][k] = a_matrix[k][i];
			}
		}
	}
	for (i = 1; i <= ar; i++){
		cout << endl;
		for (k = 1; k <= ac; k++){
			cout << " | " << c[i][k] << " | ";
		}
	}
	cout << endl << endl;
	cin.clear();
	cin.ignore();
	cout << "-Press ENTER to return to the title screen-";
	cin.get();
	system("cls");
}
//*********END TRANSPOSE FUNCTION**************


//*********START DISPLAY MATRICES FUNCTION*************
void displayMatrix1(int rowSize, int colSize, const float A[][MAX_SIZE]){
	cout << "---------------Matrix # 1---------------------------" << endl;
	cout << "Your first matrix is: " << rowSize << " X " << colSize << " and has the below values:" << endl;
	for (int i = 1; i <= rowSize; i++){
		cout << endl;
		for (int j = 1; j <= colSize; j++){
			cout << "  " << A[i][j] << "  ";
		}
	}
	cout << endl << "----------------------------------------------------" << endl;
}

void displayMatrix2(int rowSize, int colSize, const float B[][MAX_SIZE]){
	cout << "----------------Matrix # 2--------------------------" << endl;
	cout << "Your second matrix is: " << rowSize << " X " << colSize << " and has the below values:" << endl;
	for (int i = 1; i <= rowSize; i++){
		cout << endl;
		for (int j = 1; j <= colSize; j++){
			cout << "  " << B[i][j] << "  ";
		}
	}
	cout << endl << "--------------------------------------------------" << endl;
}
//*********END DISPLAY MATRICES FUNCTION*************


//*********START addMatrix FUNCTION*************
void addMatrix(const float A[][MAX_SIZE], const float B[][MAX_SIZE], int rows, int cols, float C[][MAX_SIZE]){
	cout << "-------------THE SUM OF YOUR MATRICES-------------" << endl;

	for (int i = 1; i <= rows; i++){
		cout << endl;
		for (int j = 1; j <= cols; j++){
			C[i][j] = A[i][j] + B[i][j];
			cout << "  " << C[i][j] << "  ";
		}
	}
	cout << endl << "--------------------------------------------------" << endl;
}
//*********END addMatrix FUNCTION*************


//*********START subtractMatrix FUNCTION*************
void subtractMatrix(const float A[][MAX_SIZE], const float B[][MAX_SIZE], int rows, int cols, float C[][MAX_SIZE]){
	cout << "---------THE DIFFERENCE OF YOUR MATRICES----------" << endl;
	for (int i = 1; i <= rows; i++){
		cout << endl;
		for (int j = 1; j <= cols; j++){
			C[i][j] = A[i][j] - B[i][j];
			cout << "  " << C[i][j] << "  ";
		}
	}
	cout << endl << "--------------------------------------------------" << endl;
}
//*********END subtractMatrix FUNCTION*************


//*********START multiplyMatrix FUNCTION*************
bool multiplyMatrix(const float A[][MAX_SIZE], int r1, int c1, const float B[][MAX_SIZE], int r2, int c2, float C[][MAX_SIZE], int &r3, int &c3){
	if (r1 == c2){
		cout << "----------THE PRODUCT OF YOUR MATRICES------------" << endl;
		r3 = r1;
		c3 = c2;
		int z = 0;

		for (int i = 0; i < 11; i++){
			for (int k = 0; k < 11; k++){
				C[i][k] = 0;
			}
		}
		for (int i = 1; i <= r1; i++){
			for (int j = 1; j <= c2; j++){

				for (int k = 1; k <= c1; k++){
					C[i][j] += (A[i][k] * B[k][j]);
				}
			}
		}
		for (int i = 1; i <= r1; i++){
			cout << endl;
			for (int k = 1; k <= c2; k++){
				cout << "  " << C[i][k] << "  ";
			}
		}
		cout << endl << "--------------------------------------------------" << endl;
		return true;
	}
	else return false;
}
//*********END multiplyMatrix FUNCTION*************


//*********START transposeMatrix FUNCTION*********
void transposeMatrix(const float A[MAX_SIZE][MAX_SIZE], int rows, int cols, float C[MAX_SIZE][MAX_SIZE]){
	cout << "----------THE TRANSPOSE OF YOUR MATRIX------------" << endl;
	for (int i = 1; i <= rows; i++)
	{
		for (int j = 1; j <= cols; j++)
		{
			C[j][i] = A[i][j];
		}
	}
	for (int i = 1; i <= cols; i++){
		cout << endl;
		for (int k = 1; k <= rows; k++){
			cout << "  " << C[i][k] << "  ";
		}
	}
	cout << endl << "--------------------------------------------------" << endl;
}
//********END transposeMatrix FUNCTION************


//*********MAIN FUNCTION*************
int main(){
	
	HANDLE  hConsole;
	SetConsoleTitle(TEXT("Matrices Calculator"));
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 10);	//We are in the Matrix, so we have to use green text
	float a_row = 0, a_column = 0;
	float b_row = 0, b_column = 0;
	char ans;

	cout << "         +-+-+-+-+-+-+-+-+ +-+-+-+-+-+-+-+-+-+-+        " << endl;
	cout << "         |M|a|t|r|i|c|e|s| |C|a|l|c|u|l|a|t|o|r|        " << endl;
	cout << "         +-+-+-+-+-+-+-+-+ +-+-+-+-+-+-+-+-+-+-+        " << endl;
	cout << "       coded by: Alan Thomas for Dr. Feher's CSI-235    " << endl;
	cout << "'A'dd | 'S'ubract | 'M'ultiply | 'T'ranspose | 'I'mport| 'Q'uit" << ": ";
	cin >> ans;

	//Checking what the user would like to do
	while (!(ans == 'Q' || ans == 'q')){
		//----ADDING INFORMATION START----
		if (ans == 'A' || ans == 'a'){
			//getting rows and columns for first matrix
			cout << "How many rows in your first matrix: ";
			cin >> a_row;
			while (!cin){
				cin.clear();
				cout << "--Invalid input - please enter a number only.--" << endl;
				cin.ignore();
				cout << "How many rows in your first matrix: ";
				cin >> a_row;
			}
			cout << "How many columns in your first matrix: ";
			cin >> a_column;
			while (!cin){
				cin.clear();
				cout << "--Invalid input - please enter a number only.--" << endl;
				cin.ignore();
				cout << "How many columns in your first matrix: ";
				cin >> a_column;
			}
			//getting rows and columns for second matrix
			cout << "How many rows in your second matrix: ";
			cin >> b_row;
			while (!cin){
				cin.clear();
				cout << "--Invalid input - please enter a number only.--" << endl;
				cin.ignore();
				cout << "How many rows in your second matrix: ";
				cin >> b_row;
			}
			cout << "How many columns in your second matrix: ";
			cin >> b_column;
			while (!cin){
				cin.clear();
				cout << "--Invalid input - please enter a number only.--" << endl;
				cin.ignore();
				cout << "How many columns in your second matrix: ";
				cin >> b_column;
			}
			//checking that matrices are the same size
			if (a_row == b_row && a_column == b_column){
				adding(a_row, a_column, b_row, b_column);
			}
			else{
				cout << "Matrices have to be the same size in order to subtract or add." << endl;
				cin.clear();
				main();
			}

		}
		//----ADDING INFORMATION END----


		//----SUBTRACTION INFORMATION START----
		if (ans == 'S' || ans == 's'){
			//getting rows and columns for first matrix
			cout << "How many rows in your first matrix: ";
			cin >> a_row;
			while (!cin){
				cin.clear();
				cout << "--Invalid input - please enter a number only.--" << endl;
				cin.ignore();
				cout << "How many rows in your first matrix: ";
				cin >> a_row;
			}
			cout << "How many columns in your first matrix: ";
			cin >> a_column;
			while (!cin){
				cin.clear();
				cout << "--Invalid input - please enter a number only.--" << endl;
				cin.ignore();
				cout << "How many columns in your first matrix: ";
				cin >> a_column;
			}
			//getting rows and columns for second matrix
			cout << "How many rows in your second matrix: ";
			cin >> b_row;
			while (!cin){
				cin.clear();
				cout << "--Invalid input - please enter a number only.--" << endl;
				cin.ignore();
				cout << "How many rows in your second matrix: ";
				cin >> b_row;
			}
			cout << "How many columns in your second matrix: ";
			cin >> b_column;
			while (!cin){
				cin.clear();
				cout << "--Invalid input - please enter a number only.--" << endl;
				cin.ignore();
				cout << "How many columns in your second matrix: ";
				cin >> b_column;
			}
			//checking that matrices are the same size
			if (a_row == b_row && a_column == b_column){
				subtraction(a_row, a_column, b_row, b_column);
			}
			else{
				cout << "Matrices have to be the same size in order to subtract or add." << endl;
				cin.clear();
				main();
			}

		}
		//----SUBTRACTION INFORMATION END----	


		//----MULTIPLICATION INFORMATION START----
		if (ans == 'M' || ans == 'm'){
			//getting rows and columns for first matrix
			cout << "How many rows in your first matrix: ";
			cin >> a_row;
			while (!cin){
				cin.clear();
				cout << "--Invalid input - please enter a number only.--" << endl;
				cin.ignore();
				cout << "How many rows in your first matrix: ";
				cin >> a_row;
			}
			cout << "How many columns in your first matrix: ";
			cin >> a_column;
			while (!cin){
				cin.clear();
				cout << "--Invalid input - please enter a number only.--" << endl;
				cin.ignore();
				cout << "How many columns in your first matrix: ";
				cin >> a_column;
			}
			//getting rows and columns for second matrix
			cout << "How many rows in your second matrix: ";
			cin >> b_row;
			while (!cin){
				cin.clear();
				cout << "--Invalid input - please enter a number only.--" << endl;
				cin.ignore();
				cout << "How many rows in your second matrix: ";
				cin >> b_row;
			}
			cout << "How many columns in your second matrix: ";
			cin >> b_column;
			while (!cin){
				cin.clear();
				cout << "--Invalid input - please enter a number only.--" << endl;
				cin.ignore();
				cout << "How many columns in your second matrix: ";
				cin >> b_column;
			}
			//sending variables to multiplication function
			if (a_column == b_row){
				multiplication(a_row, a_column, b_row, b_column);
			}

			else
				cout << "--When multiplying matrices, A columns must be same size as B rows--";
			cin.clear();
			main();
		}
		//----MULTIPLICATION INFORMATION END----	


		//----TRANSPOSE INFORMATION START----
		if (ans == 'T' || ans == 't'){
			//getting rows and columns for first matrix
			cout << "How many rows in your matrix: ";
			cin >> a_row;
			while (!cin){
				cin.clear();
				cout << "--Invalid input - please enter a number only.--" << endl;
				cin.ignore();
				cout << "How many rows in your matrix: ";
				cin >> a_row;
			}
			cout << "How many columns in your matrix: ";
			cin >> a_column;
			while (!cin){
				cin.clear();
				cout << "--Invalid input - please enter a number only.--" << endl;
				cin.ignore();
				cout << "How many columns in your matrix: ";
				cin >> a_column;
			}

			//sending variables to transpose function

			transpose(a_row, a_column);
		}
		//----TRANSPOSE INFORMATION END----	


		//----IMPORT INFORMATION START----
		//VARIABLES SPECIFIED BY DR. FEHER
		int row_size_matrix1 = 0, column_size_matrix1 = 0;
		int rm1, cm1, rm2, cm2;
		int row_size_matrix2, column_size_matrix2;
		float A[MAX_SIZE][MAX_SIZE]; // A = matrix 1
		float B[MAX_SIZE][MAX_SIZE]; // B = matrix 2
		float C[MAX_SIZE][MAX_SIZE]; // C = matrix 3
		//END VARIABLES SPECIFIED

		int row = 0, col = 0;

		if (ans == 'I' || ans == 'i'){
			system("cls");
			ifstream myfile;
			myfile.open("matrix.txt");

			//---IMPORTING DATA---
			//GETTING A MATRIX ROW&COL//
			for (int i = 0; i <= 0; i++){
				myfile >> row_size_matrix1;
				// cout << endl << "A row = " << row_size_matrix1 << endl; //checking array
			}
			rm1 = row_size_matrix1;
			for (int i = 1; i <= 1; i++){
				myfile >> column_size_matrix1;
				//cout << "A col = " << column_size_matrix1 << endl;//checking array
			}
			cm1 = column_size_matrix1;
			//END GETTING A MATRIX ROW&COL//

			//PLACING VALUES INTO A MATRIX//
			for (int i = 1; i <= row_size_matrix1; i++){
				cout << endl;
				for (int j = 1; j <= column_size_matrix1; j++){
					myfile >> A[i][j];
					//cout << "|" << A[i][j] << "|";//checking array
				}
			}
			cout << endl;
			//END PLACING VALUES INTO A MATRIX//

			//GETTING B MATRIX ROW&COL//
			for (int i = row_size_matrix1; i <= row_size_matrix1; i++){
				myfile >> row_size_matrix2;
				//cout << endl << "B row = " << row_size_matrix2 << endl;//checking array
			}
			rm2 = row_size_matrix2;
			for (int i = column_size_matrix1; i <= column_size_matrix1; i++){
				myfile >> column_size_matrix2;
				//cout << "B col = " << column_size_matrix2 << endl;//checking array
			}
			cm2 = column_size_matrix2;
			//END GETTING B MATRIX ROW&COL//

			//PLACING VALUES INTO B MATRIX//
			for (int i = 1; i <= row_size_matrix2; i++){
				cout << endl;
				for (int j = 1; j <= column_size_matrix2; j++){
					myfile >> B[i][j];
					//cout << "|" << B[i][j] << "|";//checking array
				}
			}
			//END PLACING VALUES INTO B MATRIX//

			cout << endl;

			//calling display function//
			displayMatrix1(row_size_matrix1, column_size_matrix1, A);
			displayMatrix2(row_size_matrix2, column_size_matrix2, B);
			//end display function//


			//calling addMatrix
			if (row_size_matrix1 == row_size_matrix2 && column_size_matrix1 == column_size_matrix2){
				row = row_size_matrix2;
				col = column_size_matrix2;
				addMatrix(A, B, row, col, C);
			}
			else{
				cout << endl << "--Cannot add, matrices must be the same size for adding/subtracting--" << endl;

			}
			//end calling addMatrix

			//calling subtractionMatrix
			if (row_size_matrix1 == row_size_matrix2 && column_size_matrix1 == column_size_matrix2){
				row = row_size_matrix2;
				col = column_size_matrix2;
				subtractMatrix(A, B, row, col, C);
			}
			else{
				cout << endl << "--Cannot subtract, matrices must be the same size for adding/subtracting--" << endl;

			}
			//end calling subtractionMatrix


			//calling multiplyMatrix
			int r1 = rm1, c1 = cm1, r2 = rm2, c2 = cm2, r3, c3; //wasn't printing correctly, this seems to have fixed it
			if (multiplyMatrix(A, r1, c1, B, r2, c2, C, r3, c3) == true){

			}
			else{
				cout << endl << "--Unable to multiply your matrices, R1 is not equal to C2--" << endl;
			}
			//end calling multiplyMatrix


			//START transposeMatrix
			transposeMatrix(A, r1, c1, C);
			//END transposeMatrix

			cin.clear();
			cin.ignore();
			cout << "-Press ENTER to return to the title screen-";
			cin.get();
			system("cls");
		}
		//---END IMPORT DATA---	

		else
			cin.clear();
		main();
	}
	quit();  //taking the user to the quit function for some reminiscence
}