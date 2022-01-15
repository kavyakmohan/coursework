//Kavya Mohan
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main (int argc, char* argv[]){
const int MAX_ROWS = 100;
const int MAX_COLS = 100;

//declare a 2d array with MAX_ROWS and MAX_COLS for matrix A
int matrixA[MAX_ROWS][MAX_COLS];

//declare a 2d array with MAX_ROWS and MAX_COLS for matrix B
int matrixB[MAX_ROWS][MAX_COLS];

//declare the rest of your filestream variables, string variables, etc.
string num;
int rows;
int cols;
string matrix_A;
string matrix_B;
ifstream inf;

//grab the cmd line args
matrix_A = argv[1];
matrix_B = argv[2];

//open the file for matrix A
inf.open(matrix_A.c_str());

//read in the first 2 lines to get the rows and columns for matrix A
//read in the rest of the values and 
    //assign them to the correct position for the matrix A array
if (inf.is_open()){
	inf >> rows;
	inf >> cols; 
	for (int i = 0; i < rows; i++){
		for(int j = 0; j < cols; j++){
			inf >> matrixA[i][j];
		}
	}
}

//close the file for matrix A 
inf.close();

//open the file for matrix B
inf.open(matrix_B.c_str());

//read in the first 2 lines to get the rows and columns for matrix B
//read in the rest of the values and 
    //assign them to the correct position in the matrix B array
if (inf.is_open()){
	inf >> rows;
	inf >> cols; 
	for (int i = 0; i < rows; i++){
		for(int j = 0; j < cols; j++){
			inf >> matrixB[i][j];
		}
	}
}

//close the file for matrix B
inf.close();

//loop over the rows and columns 
    //add the corresponding values in each 2d array 
    //print the result to the screen, 
        //making sure it is formatted in a row/column fashion
for(int i = 0; i < rows; i++){
	for (int j = 0; j < cols; j++){
		cout << matrixA[i][j] + matrixB[i][j] << " ";
	}
	cout << "\n";
}

return 0;
}
