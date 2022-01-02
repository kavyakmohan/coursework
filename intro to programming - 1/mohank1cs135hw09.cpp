/* Kavya Mohan: 2001362917 CS135 Section 1020 Assignment04
 * Description: Program that uses bubble or selection sort
 * Input: txt file containing numbers
 * Output: numbers sorted based off of command line argument */

#include <stdio.h>
#include <string.h>
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

using namespace std;

int main(int argc, char* argv[]){
//array[size of nums in file]
bool done = false;
string num;
string input = argv[3];
double temp;

//initialize array with input.txt
int SIZE = 0;
double array[10000];
char iword[200];

while (cin >> iword) {
	for (int i=0; i < strlen(iword); i++){
		if (iword[i] != '.' && (iword[i] < '0' || iword[i] > '9')){
			cout << "Invalid Number" << endl;
			return 0;
		}
	}
	array[SIZE]=atof(iword);
	SIZE++;
}

//ASCENDING BUBBLE SORT
if (strcmp(argv[1], "-BubbleAsc") == 0){
	for (int i = 1; i < SIZE; i++){
		for (int j = 1; j <= SIZE - i; j++){
			if (array[j] < array[j - 1]){
				temp = array[j];
				array[j] = array[j - 1];
				array[j - 1] = temp;
				done = false;
			}
		}
	}
	//PRINT ARRAY
	for (int i = 0; i < SIZE; i++){
		cout << array[i] << " ";
	}		
	cout << endl;
}

//DESCENDING BUBBLE SORT
else if (strcmp(argv[1], "-BubbleDesc") == 0){
	for (int i = 1; i < SIZE; i++){
		for (int j = 1; j <= SIZE - i; j++){
			if (array[j] > array[j - 1]){
				temp = array[j];
				array[j] = array[j - 1];
				array[j - 1] = temp;
				done = false;
			}
		}
	}
	//PRINT ARRAY
	for (int i = 0; i < SIZE; i++){
		cout << array[i] << " ";
	}		
	cout << endl;
}

//ASCENDING SELECTION SORT
else if (strcmp(argv[1], "-SelectionAsc") == 0){
	for (int i = 1; i < SIZE; i++){
		for (int j = i; j < SIZE; j++){
			if (array[i-1] > array[j]){
				temp = array[j];
				array[j] = array[i - 1];
				array[i - 1] = temp;
				done = false;
			}
		}
	}
	//PRINT ARRAY
	for (int i = 0; i < SIZE; i++){
		cout << array[i] << " ";
	}		
	cout << endl;
} 

//DESCENDING SELECTION SORT
else if (strcmp(argv[1], "-SelectionDesc") == 0){
	for (int i = 1; i < SIZE; i++){
		for (int j = i; j < SIZE; j++){
			if (array[j] > array[i - 1]){
				temp = array[j];
				array[j] = array[i - 1];
				array[i - 1] = temp;
				done = false;
			}
		}
	}
	//PRINT ARRAY
	for (int i = 0; i < SIZE; i++){
		cout << array[i] << " ";
	}		
	cout << endl;
} 

//ERROR MESSAGE FOR INVALID ARGV'S
else {
	cout << "Error!";
}

return 0;
}
