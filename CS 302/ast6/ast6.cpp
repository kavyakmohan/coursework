//Kavya Mohan 2001362917 Ast 6

#include <iostream>
#include <fstream>
#include <string>
#include "myHash.h"
using namespace std;

int main()
{
  //variable declarations
  string inputFile;
  ifstream infile;
  string word;
  size_t wordsRead = 0;
  int arraySize = 10;
  bool newWordFound;

  //declare myHash object, key type - string, item type - int
  myHash <string, int> h;

  //declare dynamic array
  string * uniqueWords;
  uniqueWords = new string[arraySize];

  //prompt for input file
  while (!infile.is_open())
  {
    cout << "Enter filename: ";
    cin >> inputFile;
    infile.open(inputFile.c_str());
    cout << endl;
  }

  //for each word from the input file
  while (infile >> word)
  {
    newWordFound = false;

    //check for punctuation in last char of string
    if (word[word.length()-1] == ',' || word[word.length()-1] == '.')
      word.pop_back();	//delete the last char

    //make sure entire string is lowercase
    for (int i = 0; word[i] != '\0'; i++)
      if (word[i] >= 'A' && word[i] <= 'Z')
        word[i] = word[i] + 32;

    h[word] += 1;       //add 1 to value at the index key maps to

    //if value = 1, a new entry was added to h
    if (h[word] == 1)
      newWordFound = true;

    //store word in dynamic array
    if (newWordFound) 
    {
      wordsRead++;
      //resize dynamic array if needed
      if ((wordsRead - 1) % 10 == 9)
      {
        arraySize *= 2;
        string * temp;
        temp = new string[arraySize];

        for (int i = 0; i < arraySize / 2; i++)
          temp[i] = uniqueWords[i];

        delete [] uniqueWords;
        uniqueWords = temp;
        temp = NULL;
      }
      uniqueWords[wordsRead-1] = word;
    }
  }

  //OUTPUTTING RESULTS
  //output amount of distinct words read in
  cout << "Words Read: " << wordsRead << endl << endl;

  //for each distinct word, output # of occurences in input file
  for (int i = 0; i < wordsRead; i++)
    cout << uniqueWords[i] << ": " << h[uniqueWords[i]] << endl;
 
  cout << endl;

  //deallocate dynamic array storing input
  delete [] uniqueWords;
  uniqueWords = NULL;

  //close inputFile
  infile.close();

  return 0;
}
