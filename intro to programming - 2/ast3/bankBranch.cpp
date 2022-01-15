#include <iostream>
#include <cstdlib>
#include <cmath>
#include <iomanip>
#include "bankBranch.h"
using namespace std;

/*********************************************
 DEFAULT CONSTRUCTOR
 sets empty strings and zero's for numeric types for arrays in the class
**********************************************/
bankBranch::bankBranch()
{
  amountOfAccounts = 0;

  for (int i = 0; i < 20; i++)
  {
    first[i] = last[i] = " ";
    amount[i] = 0;
    acctNo[i] = 0;
    pin[i] = 0;
    attempts[i] = 0;
  }
}


/*********************************************
 FUNCTION NAME: addAccount
 PARAMETERS: first name, last name, initial balance, bank acct number, pin (all read in from input file in main.cpp)
 RETURN: VOID
 DESCRIPTION: adds new bank account by inserting each element into its appropriate array at position amountOfAccounts and increment amountOfAccounts;
**********************************************/
void bankBranch::addAccount(string f, string l, double amt, long acct, short p)
{
  first[amountOfAccounts] = f;
  last[amountOfAccounts] = l;
  amount[amountOfAccounts] = amt;
  acctNo[amountOfAccounts] = acct;
  pin[amountOfAccounts] = p;
  amountOfAccounts++;
}


/**********************************************
 FUNCTION NAME: searchAccounts
 PARAMETERS: the acount num entered by the user
 RETURN: INT (position in array where user acct num is found or -1)
 DESCRIPTION: use linear search to return the position where acctNo[position] equals useracctNo or returns -1 if useracctNo isn't found
***********************************************/
int bankBranch::searchAccounts(long acct) const
{
  int position;
  bool found = false;

  position = 0;

  while (position < 20 && !found)
  {
    if (acctNo[position] == acct)
      found = true;

    else
      position++;
  } 

  if (found) 
    return position;

  else
    return -1;
}


/**********************************************
 FUNCTION NAME: verifyAccount
 PARAMETERS: index (value returned by searchAccounts), & p (pin entered by user)
 RETURN: BOOL
 DESCRIPTION: compares accounts[index].pin and pin entered by user and keeps track of failed attempts to enter correct pin
***********************************************/
bool bankBranch::verifyAccount(int index, short p)
{
  while (attempts[index] < 3)
  {
    if (pin[index] == p)
      return true;

    else
    {
      attempts[index]++;
      return false;
    }
  }

  return false;
}


/*********************************************
 FUNCTION NAME: updateAccount
 PARAMETERS: index (value returned by searchAccounts), amt (what user wishes to deposit or withdraw)
 RETURN: BOOL
 DESCRIPTION: updates accounts[index].amount and returns false if account has initial neg balance or true for initial pos balance
*********************************************/
bool bankBranch::updateAccount(int index, double amt)
{
  if (amount[index] < 0 && amt < 0)
    return false;

  else
  {
    amount[index] = amount[index] + amt;
    return true;
  }
}


/**********************************************
 FUNCTION NAME: outputUserInfo
 PARAMETERS: index (value returned by searchAccounts)
 RETURN: VOID
 DESCRIPTION: outputs accounts[index]'s first name, last name, acctNo, and amount
***********************************************/
void bankBranch::outputUserInfo(int index) const
{
  cout << endl;
  
  cout << "Name:" << setw(40) << right << last[index] + ", " + first[index] << endl;

  cout << "AcctNo" << setw(39) << right << acctNo[index] << endl;

  cout << "Balance...$" << setw(34) << right << amount[index] << endl << endl;
}
