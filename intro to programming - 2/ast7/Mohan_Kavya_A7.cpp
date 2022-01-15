#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

int main()
{
//create matrix of bool type
//read in t
//loop that runs t times?
//read m for each test case
//read each char on each line into bool matrix using true or false comparisons
//for each test case...allocated a m*m bool matrix and read in values from input file and output yes or no if the matrix is symmetric horizontally and vertically
//then deallocate matrix after each test case

//variables
string filename; 
ifstream inf;
bool ** testMatrix;
bool vertSym = true;
bool horSym = true;
int t, m; //t is num of test cases m is size of matrix
char value;
int middle;

//loop should run until A07.txt is read
while (filename != "A07.txt")
{
  cout << "Please enter input file: ";
  cin >> filename;
}

//open file
inf.open(filename.c_str());

//read in t from file
inf >> t;
for (int r = 0; r < t; r++)
{
  inf >> m;
  //m represents m lines with m values each

  //read in values and assign to input matrix
  testMatrix = new bool*[m];
  for (int row = 0; row < m; row++)
    testMatrix[row] = new bool[m];

  for (int row = 0; row < m ; row++)
    for (int column = 0; column < m; column++)
    {
      inf >> value;
      if (value == '1')
        testMatrix[row][column] = true;
      else
        testMatrix[row][column] = false;  
    } 
  //cout matrix to test that it is working
/*  for (int row = 0; row < m; row++)
  {
    for (int column = 0; column < m; column++)
      cout << setw(5) << testMatrix[row][column];
    cout << endl;
  }  
*/
  int axis = m / 2; 

  //test for symmetry
  if (m % 2 == 0)
    middle = axis;
  else
    middle = axis + 1;

  bool left;
  bool right;

  //vert symmetry
  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < axis; j++)
    {
      if (testMatrix[0+j][i] != testMatrix[m-1-j][i])
      {
        vertSym = false;
        break;
      }
    }
  }
 
  //horz symmetry
  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < axis; j++)
    {
      if (testMatrix[i][0+j] != testMatrix[i][m-1-j])
      {
        horSym = false;
        break;
      }
    }
  }
   //cout symmetric or not
   if (vertSym == true && horSym == true)
     cout << "Test case " << r + 1 << ": YES" << endl;
   else
     cout << "Test case " << r + 1 << ": NO" << endl;
   
  //DEALLOCATE
  //delete [] testMatrix;
  for (int k = 0; k < m; k++)
    delete [] testMatrix[k];
  delete [] testMatrix;

  //say NULL equals testMatrix or summn
  vertSym = horSym = true;
}

return 0;
}
