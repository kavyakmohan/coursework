#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;
//read in list of numbers into int dynamic array
//array capacity is initially 5
//resize array by 5 items each time the array becomes full
//can only read thru input file once
//store all the integers in array and run following algorithm;

//FUNCTION PROTOTYPE
void resizeArray(int * &listOfItems, int capacity);

int main ()
{
  string filename; 
  ifstream inf;
  int * listOfItems;
  int capacity = 5;
  int size = 0;
  int addtoCap = 0;
  listOfItems = new int[capacity];
  int value;

  while (filename != "A08.txt")
  {
    cout << "Enter input file: ";
    cin >> filename;
  }

  inf.open(filename.c_str());
 
  for (int i = 0; i < 5; i++)
  {
    inf >> listOfItems[i];
    size++;
  }

  while (! inf.eof())
  {
    resizeArray(listOfItems, capacity);

    for (int i = capacity; i < capacity + 5; i++)
    {
      inf >> listOfItems[i];
      if (! inf.eof())
        size++;
    }
    capacity = capacity + 5;
  }

  //create an array whose size is amount of integers read from file
  //set each element to 1
  int *monotoneLength = new int[size];
  int maxLength=0;
  bool max;
  
  for (int i = 0; i < size; i++)
    monotoneLength[i] = 1;

  //loop that cycles from 0 to arraysize - 1
  for (int i = 0; i < size ; i++)
  {
    maxLength=0;
    //search elements of listOfItems from 0 to i-1
    for (int j = 0; j < i ; j++)
    {
      //if listofitems[j] < listofitems[i] AND 
      if (listOfItems[j] < listOfItems[i])
      {
         if (monotoneLength[j] > maxLength)
         {
            maxLength = monotoneLength[j];
         }
      }
    }
    monotoneLength[i] = maxLength+1;
  }

  maxLength = 1;
  for (int i = 0; i < size; i++)
  {
    if ( maxLength < monotoneLength[i] )
       maxLength = monotoneLength[i];

  }
  cout << "The length of the longest monotone subsequence is " << maxLength << endl;
     
  delete [] listOfItems;
  delete [] monotoneLength;
  return 0;
}

//resize array function?
void resizeArray(int * &listOfItems, int capacity)
{
  int * temp = new int[capacity + 5];

  for (int i = 0; i < capacity; i++)
    temp[i] = listOfItems[i];

  delete [] listOfItems;

  listOfItems = temp;
 
//  delete [] temp;
  temp = NULL;
}
