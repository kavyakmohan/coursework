//Kavya Mohan

#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
#include <iomanip>

using namespace std;

//STRUCT DECLARATIONS
struct bankAcct
{
    string first, last; 	//first and last names
    double amount;	     	//user's current balance
    long acctNo;       		//user's 7 digit bank acct number
    short pin;      	   	//user's 4 digit PIN
};

//FUNCTION PROTOTYPES
int storeInfo(bankAcct[], ifstream&);
void sort(bankAcct[], int);
int search(bankAcct[], int, long);
void outputAndHandleRequest(bankAcct&);

int main ()
{
    ifstream infile;		//filestream input variable
    string filename;		//stores file name that user inputs
    int x;			//stores amount of accounts in file
    bankAcct accounts[20];	//array of bankAccts
    long userAcctNo;		//account num that user inputs
    short userPin;		//account pin that user inputs
    int index;			//value returned by search funct
    char continueResponse;	//stores Y/N

    while (!infile.is_open())	//reprompts until valid file is entered
    {
        cout << "Enter filename: ";
        cin >> filename;
        infile.open(filename.c_str());
    }

    //IF VALID FILE IS ENTERED, array is initialized and sorted
    x = storeInfo(accounts, infile);
    sort(accounts, x);
    cout << endl;

    while (true)
    {
        //prompts for acctnum to use in search funct
        cout << "Enter account number: ";
        cin >> userAcctNo;
        index = search(accounts, x, userAcctNo);
    
        //prompts for pin
        cout << "Enter pin: ";
        cin >> userPin;
        cout << endl;

        //carries out output funct if pin is correct
        if (accounts[index].pin == userPin)
        {
            outputAndHandleRequest(accounts[index]);
        }
    
        else
        {
            cout << "Incorrect pin, exiting out of account" << endl;
        }
 
        //prompts user if the wish to continue
        cout << endl;
        cout << "Do you wish to continue? (Y/N): " << endl;
        cin >> continueResponse;

        //exits while loop
        if ( continueResponse == 'N' || continueResponse == 'n' )
        {
            break;
        }
    }
    cout << "Have a great day! :)" << endl;

    return 0;
}

/***********************************
FUNCTION NAME: storeInfo
PARAMETERS: array of bank accounts and input file stream variable
RETURN: int
DESCRIPTION: assigns information to array after reading input file and returns the amount of bank accounts
************************************/

int storeInfo(bankAcct accounts[], ifstream& infile)
{
    int i = 0;
    infile >> accounts[i].first;

    if(infile.is_open())
    {
        while (!infile.eof())
        {
            infile >> accounts[i].last;
            infile >> accounts[i].acctNo;
            infile >> accounts[i].pin;
            infile >> accounts[i].amount;
            i++;
            infile >> accounts[i].first;
        }

        infile.close();
    }

    return i;
}

/***********************************
FUNCTION NAME: sort
PARAMETERS: array of bank accounts, number of accounts (value returned from storeInfo)
RETURN: void
DESCRIPTION: sort array of bank accounts in numerical order
************************************/
void sort(bankAcct accounts[], int x)
{
    bankAcct temp;

    for (int i = 0; i < x - 1; i++)
    {

        for (int j = 0; j < x - (i + 1); j++)
        {

            if (accounts[j].acctNo > accounts[j+1].acctNo)
            {
                temp = accounts[j];
                accounts[j] = accounts[j+1];
                accounts[j+1] = temp;

            }

        }

    }

}

/***********************************
FUNCTION NAME: search
PARAMETERS: array of bank accounts, amount of bank acounts, bank account number which it is searching for
RETURN: int (index of bankAcct array whose account num matches the long parameter)
DESCRIPTION:
************************************/
int search(bankAcct accounts[], int x, long userAcctNo)
{
    int l, m, r;
    l = 0;
    r = x;

    while (l < r)
    {
        m = (l + r)/2;

        if (accounts[m].acctNo == userAcctNo)
        {
            return m;
        }

        if (accounts[m].acctNo < userAcctNo)
        {
            return m + 1 + search(accounts+m+1, r - (m + 1), userAcctNo);
        }

        else
        {
            return search(accounts, m - l, userAcctNo);
        }
    }
    return -1;
}

/***********************************
FUNCTION NAME: outputAndHandleRequest
PARAMETERS: bankAcct type array
RETURN: void
DESCRIPTION: using index number returned by search funct, it will output the struct member's information and will update it if user chooses to withdraw or deposit money
************************************/
void outputAndHandleRequest(bankAcct& account)
{
   char transaction;
   double withdrawl, deposit;
   cout << setw(30) << left << "Name: " << right << account.last << ", " << right << account.first << endl;
   cout << setw(30) << left << "AcctNo " << right << account.acctNo << endl;
   cout << setw(30) << left << "Balance...$ " << right << fixed << setprecision(2) << account.amount << endl;
   while (true){
     cout << endl;
     cout << "Would you like to make a withdrawl or deposit? (W/D): ";
     cin >> transaction;
     if (transaction == 'w' || transaction == 'W')
     {
        cout << "Enter an amount you would like to withdrawl: ";
        cin >> withdrawl;
        account.acctNo = account.acctNo - withdrawl;
        break;
     }

     else if (transaction == 'd' || transaction == 'D')
     {
        cout << "Enter an amount you would like to deposit: ";
        cin >> deposit;
        account.acctNo = account.acctNo - deposit;
        break;
     }

     else // if (transaction != "w" || "W" || "d" || "D")
     {
        cout << "Invalid option!" << endl << endl;
     }
   }
}
