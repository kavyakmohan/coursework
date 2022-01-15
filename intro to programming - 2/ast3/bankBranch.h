class bankBranch
{
public:
  bankBranch();			//default constructor
  void addAccount(std::string, std::string, double, long, short);
  int searchAccounts(long) const;
  bool verifyAccount(int, short);
  bool updateAccount(int, double);
  void outputUserInfo(int) const;
private:
  int amountOfAccounts;		//num of bank accounts
  std::string first[20];	//stores all first names
  std::string last[20];		//stores all last names
  double amount[20];		//contains balances of each acct
  long acctNo[20];		//stores acctno for each acct
  short pin[20];		//stores pin for each acct
  short attempts[20];		//stores num of failed pin entries for each acct
};
