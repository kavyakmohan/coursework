/* Kavya Mohan 2001362917 CS 135 Section 1020 Assignment06
 * Description: use filestreams to decrypt and encrypt messages
 * Input: command line argument directing program to read a file and execute a function
 * Output: program writes an output file */

#include <iostream>
#include <string>
#include <fstream>        //For file input/output 
#include <time.h>         //For time
#include <stdlib.h>       //For srand
#include <cstdlib>        //For atoi
using namespace std;

//Decrypt function
int decryptfunction (){
	string word, lastword;
	string ifile = "input.txt";
	string ofile = "output.txt";
	ifstream inf;
	ofstream outf;

	//Opening files and converting to strings
	inf.open(ifile.c_str());
	outf.open(ofile.c_str());

	inf >> word;	//read in word from input file

	while (inf){
		if (lastword == "jarjar")	//if the last word read was jarjar, print the following word
			outf << word << " ";

		lastword = word;		//lastword is changed to current word being read
		inf >> word;			//a new word is reas
	}

	//close files
	inf.close();
	outf.close();

	cout << "Filestream Assignment 6" << endl;
	return 0;
}

//Encrypt function
int encryptfunction (){
	int rand_words, rand_word_length;
	string word;
	string ifile = "input.txt";
	string ofile = "output.txt";
	ifstream inf;
	ofstream outf;

	//open files
	inf.open(ifile.c_str());
	outf.open(ofile.c_str());

	srand(time(NULL));

	inf >> word;	//read in word

	while (inf){
		rand_words=3+rand()%10; //generate how many junk words to insert before jarjar

		for (int i=0; i<=rand_words; i++){ 
			//generate length of each junk word
			rand_word_length=4+rand()%10;

			for(int j=0; j<=rand_word_length; j++)
				outf << (char) ('a' + rand()%26); //prints junk words

			outf << " ";
			}

		outf << "jarjar" << " " << word << " "; //prints "jarjar (word) "
                inf >> word;	//reads in the next word
		}

	//close files
	inf.close();
	outf.close();

	cout << "Filestream Assignment 6" << endl;
	return 0;
}

//Determine which function to perform
int main(int argc, char *argv[]){

//./a.out 0 ---> decrypt function
	if (atoi(argv[1]) == 0)
		decryptfunction();

//./a.out 1 ---> encrypt function
	else if (atoi(argv[1]) == 1)
		encryptfunction();

//error message for invalid argument
	else {
		cout << "Invalid Argument Given. Use ./a.out 0 or ./a.out 1" << endl;
		return 0;
		}

return 0;
}

