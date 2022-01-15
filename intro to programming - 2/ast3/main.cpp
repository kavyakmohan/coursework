#include <iostream>
#include <fstream>
#include "bankBranch.h"
using namespace std;


//FUNCTION PROTOTYPES
void openFile(string, ifstream&);
void readFile(bankBranch&, string, ifstream&);
void promptUserAcctNo(bankBranch&, int&);
void promptUserPin(bankBranch&, int);
void promptTransaction(bankBranch&, int);
int promptContinuation(bankBranch, int);


//INT MAIN
int main ()
{
  bankBranch accounts;	//object of type bankBranch
  ifstream infile;
  string filename;	//stores file name entered by user
  int index;		//value returned by accounts.search(long acct)
  short userpin;	//pin entered by user
  double amountReadIn;	//amount user wishes to deposit or withdraw
  
  //prompt user for file name
  cout << endl;
  cout << "Enter file name to begin this program...again: ";
  cin >> filename;

  openFile(filename, infile);

  readFile(accounts, filename, infile);

  promptUserAcctNo(accounts,index);

  return 0;
}


/***********************************************
 FUNCTION NAME: openFile
 PARAMETERS: filename entered by user, ifstream input variable
 RETURN: VOID
 DESCRIPTION: reprompts until valid file is entered and then opens valid file
************************************************/
void openFile(string filename, ifstream& infile)
{
  if (filename != "BankData.txt")
  {
    cout << "Ahem...let's try this again: ";
    cin >> filename;
    openFile(filename, infile);
  }

  else
  {
    infile.open(filename.c_str());
  }
}


/***********************************************
 FUNCTION NAME: readFile
 PARAMETERS: class object bankBranch accounts, filename entered by user, ifstream input variable
 RETURN TYPE: VOID
 DESCRIPTION: read the file one line at a time and passes the variables read to class member function addAccount
************************************************/
void readFile(bankBranch& accounts, string filename, ifstream& infile)
{
  string f, l;
  double amt;
  long acct;
  short p;
   
  while (!infile.eof())
  {
    infile >> f >> l >> acct >> p >> amt;
    accounts.addAccount(f, l, amt, acct, p);
  }
}
    

/***********************************************
 FUNCTION NAME: promptUserAcctNo
 PAREMETERS: bankBranch accounts, index
 RETURN TYPE: VOID
 DESCRIPTION: prompts user for their account number and passes it to class member function searchAccounts. the value returned by that function is initialized to index. if index is -1, an error message is outputted. otherwise, the user is prompted for their pin.
************************************************/
void promptUserAcctNo(bankBranch& accounts, int& index)
{ 
  long acct;
  cout << endl;
  cout << "Enter account number: ";
  cin >> acct;
  index = accounts.searchAccounts(acct);
  if (index == -1)
  {
    cout << "Account not found! :(" << endl << endl;
    promptContinuation(accounts, index);
  }

  else
  {
    promptUserPin(accounts, index);
  }
}
      

/*************************************************
 FUNCTION NAME: promptUserPin
 PAREMETERS: bankBranch accounts, index
 RETURN TYPE: VOID
 DESCRIPTION: prompts user to enter pin. passes pin and index to class member function verifyAccount. if it returns false, an error message is outputted. if it returns true, it outputs the user's bank info and prompts them to withdraw or deposit. both cases prompt user if they wish to continue.
**************************************************/
void promptUserPin(bankBranch& accounts, int index)
{
  short userpin;
  cout << "Enter pin: ";
  cin >> userpin;
  if (accounts.verifyAccount(index, userpin))
  {
    accounts.outputUserInfo(index);
    promptTransaction(accounts, index);
    promptContinuation(accounts, index);
  }

  else
  {
    cout << endl << "Account frozen or incorrect pin entered, existing account" << endl;
    promptContinuation(accounts, index);
  }
}


/******************************************************
 FUNCTION NAME: promptTransaction
 PARAMETERS: bankBranch accounts, index
 RETURN TYPE: VOID
 DESCRIPTION: prompts user if they wish to make a withdrawl or deposit and reprompts until a valid option is entered. then the user is prompted to enter the amount of money they wish to deposit or withdraw. the index and a negative or positive value of the amount read in by the user are passed to class member function updateAccount. if updateAccount returns false, an error message is outputted.
*******************************************************/
void promptTransaction(bankBranch& accounts, int index)
{
  char transactionChoice;
  double amountReadIn;
  cout << "Would you like to make a withdrawl or deposit? (W/D): ";
  cin >> transactionChoice;
   
  if (transactionChoice == 'w' || transactionChoice == 'W')
  {
    cout << "Enter an amount you would like to withdraw: ";
    cin >> amountReadIn;
    //reprompt for invalid amountReadIn
    if (!accounts.updateAccount(index, -amountReadIn))
      cout << "Cannot process transaction...O.o" << endl;
  }

  else if (transactionChoice == 'd' || transactionChoice == 'D')
  {
    cout << "Enter an amount you would like to deposit: ";
    cin >> amountReadIn;
    //reprompt for invalid amount read in
    if (!accounts.updateAccount(index, amountReadIn))
      cout << "Cannot process transaction...O.o" << endl;
  }

  else
  {
    cout << "Invalid option!" << endl;
    promptTransaction(accounts, index);
  }
}


/****************************************************
 FUNCTION: promptContinuation
 PARAMETERS: bankBranch accounts, index
 RETURN TYPE: INT
 DESCRIPTION: prompts user to enter if they wish to continue or not and reprompts until valid option is entered. if they don't wish to continue, the program terminates. if they wish to continue, promptUserAcctNo will be called
*****************************************************/
int promptContinuation(bankBranch accounts, int index)
{
  char continuationChoice;
  cout << "Do you wish to continue? (Y/N): ";
  cin >> continuationChoice;

  if (continuationChoice == 'n' || continuationChoice == 'N')
  {
    cout << endl << "Have a great day! :)" << endl;
    //TERMINATE PROGRAM
    return -1;
  }

  else if (continuationChoice == 'y' || continuationChoice == 'Y')
    promptUserAcctNo(accounts, index);

  else
    promptContinuation(accounts, index);
}

