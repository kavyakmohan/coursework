//Kavya Mohan, 2001362917, Assignment 4
//Description: multiply 2 matrices using vectors and threads
//Input: input file containing 2 matrices and their dimensions
//Output: print a matrix containing the solutions

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <thread>
using namespace std;

void multiplication(int, int);

//global vectors
vector< vector<int> > matrixA;
vector< vector<int> > matrixB;
vector< vector<int> > productMatrix(10, vector <int> (10, 0));


int main()
{
  string inputFile;
  ifstream infile;

  int matrixArows;
  int matrixAcolumns;

  int matrixBrows;
  int matrixBcolumns;

  vector<thread> threadPool;
  int maxThreads = thread::hardware_concurrency();

  cout << endl;

  //prompt for valid inputFile
  while(!infile.is_open())
  {
    cout << "Enter filename: ";
    cin >> inputFile;
    infile.open(inputFile.c_str());
  }

  cout << endl;

  //reading matrix A's dimensions
  infile >> matrixArows;
  infile >> matrixAcolumns;

  //allocating rows to matrixA
  matrixA.resize(matrixArows);

  //allocating columns for each row in matrix A
  for (int i = 0; i < matrixA.size(); i++)
  	matrixA[i].resize(matrixAcolumns);

  //reading in matrix A from inputFile
  for (int i = 0; i < matrixArows; i++)
  {
    for (int j = 0; j < matrixAcolumns; j++)
      infile >> matrixA[i][j];
  }

  //reading matrix B's dimensions
  infile >> matrixBrows;
  infile >> matrixBcolumns;

  //allocating rows to matrix B
  matrixB.resize(matrixBrows);

  //allocating columns for each row in matrix B
  for (int i = 0; i < matrixB.size(); i++)
    matrixB[i].resize(matrixBcolumns);

  //reading in matrix B from inputFile
  for (int i = 0; i < matrixBrows; i++)
  {
    for (int j = 0; j < matrixBcolumns; j++)
      infile >> matrixB[i][j];
  }

  //closing inputFile
  infile.close();

  //MATRICES MULTIPLICATION ALGORITHM
  for (int i = 0; i < matrixArows; i++)
  {
    for (int j = 0; j < matrixBcolumns; j++)
    {
      //spawn a thread to compute productMatrix [i][j]
      //spawn a thread for each element in productMatrix
      threadPool.push_back(thread(multiplication, i, j));

      //if we spawned the max amnt of threads that the system can handle
      //we wait for all of them to finish before we spawn more threads
      if (threadPool.size() == maxThreads)
      {
        for (int k = 0; k < threadPool.size(); k++)
          threadPool[k].join();

        threadPool.clear();
      }
    }
  }

  //wait for any leftover threads that were spawned in the above loop before continuing
  for (int i = 0; i < threadPool.size(); i++)
    threadPool[i].join();

  threadPool.clear();

  //cout product matrix
  for (int i = 0; i < 10; i++)
  {
    for (int j = 0; j < 10; j++)
      cout << productMatrix[i][j] << " ";

    cout << endl;
  }

  cout << endl;

  return 0;
}

//function identifier: summation of (row[n] * column[n])
//parameters: index for a row from matrixA and index for a column from matrixB
//return value: void
void multiplication(int aRow, int bColumn)
{
  int sum = 0;

  //multipy aRow[i] and bColumn[i] and update sum
  for (int i = 0; i < 5; i++)
    sum = sum + (matrixA[aRow][i] * matrixB[i][bColumn]);

  //store sum in product matrix
  productMatrix[aRow][bColumn] = sum;

  return;
}
