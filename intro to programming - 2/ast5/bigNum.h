#include <iostream>
using namespace std;

class bigNum
{
public:
  static const int MAX_DIGITS = 50; //max digits bigNum object can hold

  //constructors
  bigNum();
  bigNum(const char[]);
  bigNum(int);


  //overloading +
  bigNum operator+(const bigNum&) const;
  bigNum operator+(int) const;


  //overloading <
  bool operator<(const bigNum&) const;
  bool operator<(int) const;


  //overloading ==
  bool operator==(const bigNum&) const;
  bool operator==(int) const;


  //friend functions to overload +, <, and ==
  friend bigNum operator+(int, const bigNum&);
  friend bool operator<(int, const bigNum&);
  friend bool operator==(int, const bigNum&);


  //friend functions to overload output and input operators << and >>
  friend ostream& operator<<(ostream&, const bigNum&);
  friend istream& operator>>(istream&, bigNum&);


  //extra credit
  bigNum operator-(const bigNum&) const;
  bigNum operator-(int) const;
  friend bigNum operator-(int, const bigNum&);
 

private:
  int amtDigits;		//digits bigNum object contains
  char number[MAX_DIGITS];	//char array stores number
};
