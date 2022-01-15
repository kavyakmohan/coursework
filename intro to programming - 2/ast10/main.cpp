#include <iostream>
#include <fstream>
#include <cstdlib>
#include "myStack.h"
using namespace std;

int main()
{
  string file = "I10_1.txt";
  string inputfile;
  ifstream infile;
  myStack towers, placeHolder, ranges;
  int readin, x, y, z, xranges, output;
  xranges = 1;

  //prompts for valid file
  while (inputfile != file)
  {
    cout << "Pleaase enter an input file: ";
    cin >> inputfile;
  }

  cout << endl;

  //opens file
  infile.open(file.c_str());

  //reads file until eof and pushes input to towers
  infile >> readin;
  while(!infile.eof())
  {
    towers.push(readin);
    infile >> readin;
  }

  //loop repeats until towers is empty
  while(!towers.isEmpty())
  {
    //x is top of towers
    x = towers.top();
    towers.pop();
     
    //compares x to other values until top until if finds one bigger than it
    while (!towers.isEmpty() && x >= towers.top())
    {
      y = towers.top();
      towers.pop();
      placeHolder.push(y); //values smaller than x pushed into placeHolder
      xranges++;
    }
   
    ranges.push(xranges); //stores ranges
    xranges = 1; //reset ranges

    //placeHolder values are stored in towers again
    while (!placeHolder.isEmpty())
    {
      z = placeHolder.top();
      placeHolder.pop();
      towers.push(z);  
    }
  }

  cout << "Here are the ranges for each tower" << endl;
  while (!ranges.isEmpty())
  {
    output = ranges.top();
    cout << output << " ";
    ranges.pop();
  }

return 0;
}
