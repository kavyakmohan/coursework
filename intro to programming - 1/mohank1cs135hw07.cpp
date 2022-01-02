/* Kavya Mohan 2001362917 CS135 Section 1020 Assignment 07
 * Description: count numbers using arrays
 * Input: "the force", multiple numbers, a number, ect
 * Output: error messages or a table displaying how many times a digit is repeated */

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main () {
string input;

//cin input number
cout << "Enter a number or \"the force\" to exit: ";
getline(cin, input);

//calculate and initialize size of input and other variables
int string_size = input.length();
int digit_count[10] = {0}; //initialize array
int array_index = 0;
bool rpt_found=false;

//terminate the program if "the force" is entered
if (input == "the force") {
	cout << "StarWars Episode VII and VIII are bad!" << endl;
	cout << "(Episode IX will be also bad!)" << endl;
	return 1;
	}

for (int i = 0; i < string_size; i++) {
	//terminate program if multiple numbers are entered
	if (input[i] == ' '){
		cout << "StarWars Episode VII and VIII are bad!" << endl;
		cout << "(Episode IX will be also bad!)" << endl;
		return 1;
		}
	//error message if an invalid character is entered
	else if (input[i] < '0' || input[i] > '9'){
		cout << "ERROR: Invalid input!" << endl;
		cout << input << endl;
		cout << setw(i+1) << "^" << endl;
		cout << "Found symbol \"" << input[i] << "\" at index " << i << endl;
		return 1;
		}
	}

//loop reads each number and stores the number of repeats to array
for (int i = 0; i < string_size; i++) {
	array_index = (input[i] - '0');
	digit_count[array_index]++;
	}

//prints how many times each digit is repeated
cout << left << setw(11) << "Repeated" << "-> "; 
for (int i = 0; i < 10; i++) {
	cout << digit_count[i] << " "; 
	}
cout << endl;
		
//prints digits 0-9
cout << setw(11) << "Numbers" << "-> ";
for (int i = 0; i < 10; i++) {
	cout << i << " "; 
	}
cout << endl;

//prints repeated numbers
cout << setw(11) << "Ocurrances" << "-> " ;
for (int i = 0; i < 10; i++) {
	if ( digit_count[i] > 1 ){
		cout << i << " "; 
		rpt_found=true;
		}
	}

//prints message if no repeats are found
if (!rpt_found){
	cout << "NONE";
	}

cout << endl;
 	
return 0;
}
