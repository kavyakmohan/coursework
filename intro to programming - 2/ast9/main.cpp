#include <iostream>
#include <string>
#include "myStack.h"
using namespace std;

int main()
{
  char topvalue;		//stores values returned by top()
  int rpcnt, lpcnt, rccnt, lccnt, rbcnt, lbcnt, charcnt;	//1st six variables count symbols
  rpcnt = lpcnt = rccnt = lccnt = rbcnt = lbcnt = 0;

  string message;		//stores message user inputs

  cout << "Enter the arithmetic expression: ";

  getline(cin, message);

  // count characters in string
  charcnt = message.size();
 
  //variables to for message without spaces
  char mssg[charcnt];
  int mssgcnt = 0;

  // stores message without spaces 
  int pos = 0;
  for (int i = 0; i < charcnt; i++)
  {
    if (message[i] != ' ')
    {
      mssg[pos] = message[i];
      pos++;
      mssgcnt++;
    }
  }

  myStack stack(mssgcnt);		//mystack obj

  //push each char from mssg
  for (int i = 0; i < mssgcnt; i++)
    stack.push(mssg[i]);

  //top and pop each char
  for (int i = 0; i < mssgcnt; i++)
  {
    topvalue = stack.top();
   
    //check for symbols 
   
    if (topvalue == '(')
      lpcnt++;

    if (topvalue == ')')
      rpcnt++;

    if (topvalue == '{')
      lccnt++;

    if (topvalue == '}')
      rccnt++;

    if (topvalue == '[')
      lbcnt++;

    if (topvalue == ']')
      rbcnt++;

    stack.pop();
  }

  if (rpcnt == lpcnt && rccnt == lccnt && rbcnt == lbcnt)
    cout << "All brackets/parenthesis are matched correctly" << endl;

  else
    cout << "Oops, looks like something went wrong" << endl;
  return 0;
}
