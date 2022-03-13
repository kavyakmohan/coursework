//Kavya Mohan, 2001362917, Assignment 2
//Description: Arranging DNA Sequences
//Input: file containing multiple datasets with dna sequences
//Output: arranging sequences by level of sortedness

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int MAX_STRLENGTH = 50;
const int MAX_STRCNT = 100;

struct dna
{
  string sequence;
  int inversions;
};

int main()
{
  string inputFile;
  ifstream infile;
  int datasetcnt;   //number of datasets in inputFile
  int stringLength;
  int stringCnt;
  int i;           //used for insertion sort
  int j;           //used for insertion sort
  dna key;         //used for insertion sort

  //prompt for valid inputFile
  while(!infile.is_open())
  {
    cout << "Enter filename: ";
    cin >> inputFile;
    infile.open(inputFile.c_str());
  }

  cout << endl;

  //read in datasetcnt
  infile >> datasetcnt;

//iterates thru each input dataset
  for (int i = 0; i < datasetcnt; i++)
  {
    //read in stringLength
    infile >> stringLength;

    //read in stringCnt
    infile >> stringCnt;

    //create array
    dna dataset[MAX_STRCNT];

    //read in dataset
    for (int i = 0; i < stringCnt; i++)
    {
      infile >> dataset[i].sequence;
      dataset[i].inversions = 0;
    }

    //calculate inversions
    for (int i = 0; i < stringCnt; i++) //iterating thru each sequence in the dataset
    {
      for (int j = 0; j < stringLength - 1; j++)  //char we are looking at
      {
        for (int k = j; k < stringLength; k++)  //comparions chars
        {
          if (dataset[i].sequence[j] > dataset[i].sequence[k])
            dataset[i].inversions++;
        }
      }
    }

    //arrange input strings using insertion sort
    for (int i = 1; i < stringCnt; i++)
    {
      //initializing key
      key.sequence = dataset[i].sequence;
      key.inversions = dataset[i].inversions;

      //initializing j
      j = i - 1;

      //actual sorting loop
      while (j >= 0 && dataset[j].inversions > key.inversions)
      {
        dataset[j+1].sequence = dataset[j].sequence;
        dataset[j+1].inversions = dataset[j].inversions;

        j = j - 1;
      }
      
      dataset[j+1].sequence = key.sequence;
      dataset[j+1].inversions = key.inversions;
    }

    //output list of arranged input strings
    for (int i = 0; i < stringCnt; i++)
      cout << dataset[i].sequence << endl;

    //print blank line
    cout << endl;
  }

  //close inputFile
  infile.close();

  return 0;
}
