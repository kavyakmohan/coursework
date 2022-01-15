#include <iostream>
#include <cstdlib>
#include <cmath>
#include "bigNum.h"
using namespace std;

/******************************************
 FUNCTION NAME: bigNum();
 PARAMETERS: none
 RETURN TYPE: none
 DESCRIPTION: default constructor initializes amtDigits and number[MAX_DIGITS] to zero
********************************************/
bigNum::bigNum()
{
  //sets amtDigits to 0
  amtDigits = 0;
  
  //assigns '0' number[]
  for (int i = 0; i < MAX_DIGITS; i++)
    number[i] = '0';
}  


/********************************************
 FUNCTION NAME: bigNum(const char strNum[])
 PARAMETERS: array of characters containing a string literal
 RETURN TYPE: none
 DESCRIPTION: constructor assigns characters from strNum[] to number[] and sets amtDigits
********************************************/
bigNum::bigNum(const char strNum[])
{
  int pos = 0;
  amtDigits = 0;

  //count leading zeros
  while (strNum[pos] == '0')
    pos++;

  int start = pos;

  //count digits excluding leading zeros and null char
  while (strNum[pos] != '\0')
  {
    pos++;
    amtDigits++;
  }
 
  //assigns '0' number[]
  for (int i = 0; i < MAX_DIGITS; i++)
    number[i] = '0';

  //assigns strNum[] to number[]
  for (int i = 0; i < amtDigits; i++)
    number[MAX_DIGITS - amtDigits + i] = strNum[start + i];

  //assigns '0' to number[] if string is all 0's
  if (amtDigits == 0)
  {
    number[MAX_DIGITS - 1] = '0';
    amtDigits++;
  }
}


/************************************************
 FUNCTION NAME: bigNum(int n)
 PARAMETERS: int n
 RETURN TYPE: none
 DESCRIPTION: constructor extracts each digit from int n, converts it to a char, and stores it in number[] accordingly. also finds and stores amtDigits
************************************************/
bigNum::bigNum(int n)
{
  int i = 1;
  amtDigits = 0;
 
  if (n == 0)
    number[MAX_DIGITS - 1] = '0';

  //assigns '0' number[]
  for (int i = 0; i < MAX_DIGITS; i++)
    number[i] = '0';

  //mod n by 10 and then divide n by 10 while incrementing amtDigits and i
  while (n > 0)
  {
    number[MAX_DIGITS - i] = n % 10 + '0';
    n = n / 10;
    amtDigits++;
    i++;
  }
}


/************************************************
 FUNCTION NAME: bigNum operator+(const bigNum& rhs) const
 PARAMETERS: bigNum
 RETURN TYPE: bigNum that is a sum
 DESCRIPTION: adding a bigNum object to another bigNum object and returning a bigNum object storing the sum
*************************************************/
bigNum bigNum::operator+(const bigNum& rhs) const
{
  int carry = 0;
  int operand1;
  int operand2;
  int sum = 0;
  int i = MAX_DIGITS - 1; //49

  bigNum result; //obj that returns sum

  //loops runs from i = 49 to i = 0
  while (i > -1 )
  {
    operand1 = number[i] - '0';
    operand2 = rhs.number[i] - '0';
    sum = operand1 + operand2 + carry;
    carry = 0;				//resets carry
    if (sum > 9)			//assigns carry if necessary
    {
      carry = sum / 10;
      sum = sum % 10;
    }
    result.number[i] = sum + '0';	//stores sum in result.number[]
    i--;				//decrements i
  }

  // recalc result amtDigits;
  for (int j = 0; j < result.MAX_DIGITS; j++)
  {
    if ( result.number[j] != '0' )
    {
       result.amtDigits = result.MAX_DIGITS - j;
       break;
    }
    if ( j == (result.MAX_DIGITS - 1))
    {
       result.amtDigits = 1;
    }
  }
  return result;			//returns result
}


/***************************************************
 FUNCTION NAME: bigNum operator+(int rhs) const
 PARAMETERS: int rhs
 RETURN TYPE: bigNum obj containing sum
 DESCRIPTION: add bigNum object with and int and return a bigNum object that contains a sum
****************************************************/
bigNum bigNum::operator+(int rhs) const
{
  //converting int using bigNum(int n) definition
  int i = 1;
  bigNum convertedInt;			//will store int rhs
  convertedInt.amtDigits = 0;
 
  if (rhs == 0)
    convertedInt.number[convertedInt.MAX_DIGITS - 1] = '0';

  while (rhs > 0)
  {
    convertedInt.number[convertedInt.MAX_DIGITS - i] = rhs % 10 + '0';
    rhs = rhs / 10;
    convertedInt.amtDigits++;
    i++;
  }

  //definition of bigNum operator+(const bigNum& rhs)
  int carry = 0;
  int operand1;
  int operand2;
  int sum = 0;
  int j = MAX_DIGITS - 1;
 
  bigNum result;  

  while (j > -1)
  {
    operand1 = number[j] - '0';
    operand2 = convertedInt.number[j] -'0';
    sum = operand1 + operand2 + carry;
    carry = 0;
    if (sum > 9)
    {
      carry = sum / 10;
      sum = sum % 10;
    }
    result.number[j] = sum + '0';
    j--;
  }

  //recalculating amtDigits
  for (int k = 0; k < result.MAX_DIGITS; k++)
  {
    if ( result.number[k] != '0' )
    {
       result.amtDigits = result.MAX_DIGITS - k;
       break;
    }
    if ( k == (result.MAX_DIGITS - 1))
    {
       result.amtDigits = 1;
    }
  }
  return result;
}


/*************************************************
 FUNCTION NAME: bool operator<(const bigNum& rhs) const
 PARAMETERS: bigNum type object rhs (righthand object)
 RETURN TYPE: bool
 DESCRIPTION: compares bigNum with another bigNum. if function returns true, obj on left is smaller. function returns false otherwise
**************************************************/
bool bigNum::operator<(const bigNum& rhs) const
{
  //if and else if compare amtDigits and rhs.amtDigits
  if (amtDigits < rhs.amtDigits)
    return true;
  else if (amtDigits > rhs.amtDigits)
    return false;
  else
  {
    //compares digits one-by-one from left to right 
    for (int j = 0; j < MAX_DIGITS; j++)
    {
      if (number[j] < rhs.number[j])
        return true;

      else
        j++;
    }
  }
  return false;
}


/*************************************************
 FUNCTION NAME: operator<(int rhs) const
 PARAMETERS: int rhs
 RETURN TYPE: bool
 DESCRIPTION: compares bigNum obj with int rhs (after it is converted). returns true if bigNum is smaller than rhs or false otherwise
**************************************************/
bool bigNum::operator<(int rhs) const
{
  //convert int into bigNum type using bigNum(int n) definition
  int i = 0;
  bigNum convertedInt;
  convertedInt.amtDigits = 0;
 
  if (rhs == 0)
    convertedInt.number[convertedInt.MAX_DIGITS - 1] = '0';

  while (rhs > 0)
  {
    convertedInt.number[convertedInt.MAX_DIGITS - i] = rhs % 10 + '0';
    rhs = rhs / 10;
    convertedInt.amtDigits++;
    i++;
  }

  //definition of operator<(const bigNum& rhs)
  if (amtDigits < convertedInt.amtDigits)
    return true;
  else if (amtDigits > convertedInt.amtDigits)
    return false;
  else
  {
    for (int j = 0; j < MAX_DIGITS; j++)
    {
      if (number[j] < convertedInt.number[j])
        return true;
      else
        j++;
    }
  }
  return false;
}


/**************************************************
 FUNCTION NAME: operator==(const bigNum& rhs) const
 PARAMETERS: bigNum object rhs
 RETURN TYPE: bool
 DESCRIPTION: compares bigNum obj with bigNum rhs. returns true if they're equal and false otherwise
**************************************************/
bool bigNum::operator==(const bigNum& rhs) const
{
  //returns false if amtDigits doesn't equal rhs.amtDigits
  if (amtDigits != rhs.amtDigits)
    return false;
  else
  {
    //compares digits one-by-one from left to right
    for (int i = 0; i < MAX_DIGITS; i++) 
    {
      if (number[i] != rhs.number[i])
        return false;
    }
  }
  return true;
}


/*************************************************
 FUNCTION NAME: operator==(int rhs) const
 PARAMETERS: int rhs
 RETURN TYPE: bool
 DESCRIPTION: compares bigNum obj with int rhs (after it's converted). returns true if they're equal and false otherwise
**************************************************/
bool bigNum::operator==(int rhs) const
{
  //convert to int using bigNum(int n)
  int i = 1;
  bigNum convertedInt;
  convertedInt.amtDigits = 0;
 
  if (rhs == 0)
    convertedInt.number[convertedInt.MAX_DIGITS - 1] = '0';

  while (rhs > 0)
  {
    convertedInt.number[convertedInt.MAX_DIGITS - i] = rhs % 10 + '0';
    rhs = rhs / 10;
    convertedInt.amtDigits++;
    i++;
  }

  //operator==(const bigNum& rhs) definition
  if (amtDigits != convertedInt.amtDigits)
    return false;
  else
  {
    for (int j = 0; j < MAX_DIGITS; j++)
    {
      if (number[j] != convertedInt.number[j])
        return false;
    }
  }
  return true;
}


/*************************************************
 FUNCTION NAME: friend bigNum operator+(int lhs, const bigNum& rhs)
 PARAMETERS: int lhs, bigNum obj rhs
 RETURN TYPE: bigNum
 DESCRIPTION: friend funct adds left hand side int with right hand side object. sum is returned in the form of bigNum obj
**************************************************/
bigNum operator+(int lhs, const bigNum& rhs)
{
  //convert lhs using bigNum(int n)
  int i = 1;
  bigNum convertedlhs;
  convertedlhs.amtDigits = 0;
 
  if (lhs == 0)
    convertedlhs.number[convertedlhs.MAX_DIGITS - 1] = '0';

  while (lhs > 0)
  {
    convertedlhs.number[convertedlhs.MAX_DIGITS - i] = lhs % 10 + '0';
    lhs = lhs / 10;
    convertedlhs.amtDigits++;
    i++;
  }

  //convertedlhs.operator+(bigNum& rhs);
  //operator+(const bigNum& rhs)
  int carry = 0;
  int operand1;
  int operand2;
  int sum = 0;
  
  bigNum result;
  int j = result.MAX_DIGITS - 1;

  while (j > -1)
  {
    operand1 = convertedlhs.number[j] - '0';
    operand2 = rhs.number[j] -'0';
    sum = operand1 + operand2 + carry;
    carry = 0;
    if (sum > 9)
    {
      carry = sum / 10;
      sum = sum % 10;
    }
    result.number[j] = sum + '0';
    j--;
  }

  // recalc result amtDigits;
  for (int k = 0; k < result.MAX_DIGITS; k++)
  {
    if ( result.number[k] != '0' )
    {
       result.amtDigits = result.MAX_DIGITS - k;
       break;
    }
    if ( k == (result.MAX_DIGITS - 1))
    {
       result.amtDigits = 1;
    }
  }
  return result;
}


/*************************************************
 FUNCTION NAME: friend bool operator<(int lhs, const bigNum& rhs)
 PARAMETERS: int lhs, bigNum rhs
 RETURN TYPE: bool
 DESCRIPTION: compares int lhs and bigNum rhs. returns true if lhs is smaller and false otherwise
**************************************************/
bool operator<(int lhs, const bigNum& rhs)
{
  //converting int lhs into bigNum object
  bigNum convertedlhs;
  int i = 1;
  convertedlhs.amtDigits = 0;
 
  if (lhs == 0)
    convertedlhs.number[convertedlhs.MAX_DIGITS - 1] = '0';

  while (lhs > 0)
  {
    convertedlhs.number[convertedlhs.MAX_DIGITS - i] = lhs % 10 + '0';
    lhs = lhs / 10;
    convertedlhs.amtDigits++;
    i++;
  }

  //comparing objects
  //definition of operator<(const bigNum& rhs)
  if (convertedlhs.amtDigits < rhs.amtDigits)
    return true;
  else if (convertedlhs.amtDigits > rhs.amtDigits)
    return false;
  else
  {
    for (int j = 0; j < rhs.MAX_DIGITS; j++)
    {
      if (convertedlhs.number[j] < rhs.number[j])
        return true;
      else
        j++;
    }
  }
  return false;
}


/*************************************************
 FUNCTION NAME: friend bool operator==(int lhs, const bigNum& rhs)
 PARAMETERS: int lhs, bigNum rhs
 RETURN TYPE: bool
 DESCRIPTION: compares int lhs with bigNum rhs. returns true if lhs equals rhs and false otherwise
**************************************************/
bool operator==(int lhs, const bigNum& rhs)
{
  //convert lhs using bigNum(int n)
  bigNum convertedlhs;
  int i = 1;
  convertedlhs.amtDigits = 0;
 
  if (lhs == 0)
    convertedlhs.number[convertedlhs.MAX_DIGITS - 1] = '0';

  while (lhs > 0)
  {
    convertedlhs.number[convertedlhs.MAX_DIGITS - i] = lhs % 10 + '0';
    lhs = lhs / 10;
    convertedlhs.amtDigits++;
    i++;
  }

  //comparing objects
  //operator==(const bigNum& rhs) definition
  if (convertedlhs.amtDigits != rhs.amtDigits)
    return false;
  else
  {
    for (int j = 0; j < rhs.MAX_DIGITS; j++)
    {
      if (convertedlhs.number[j] != rhs.number[j])
        return false;
      else
        j++;
    }
  }
  return true;
}


/***************************************************
 FUNCTION NAME: friend ostream& operator<<(ostream& out, bigNum& bN)
 PARAMETERS: operator stream object, bigNum object (bN)
 RETURN TYPE: out
 DESCRIPTION: friend function that outputs the bigNum object bN...characters are output one at a tyme
*****************************************************/
ostream& operator<<(ostream& out, const bigNum& bN)
{
  //out object << ...

  for (int i = 0; i < bN.amtDigits; i++)
    out << bN.number[bN.MAX_DIGITS - bN.amtDigits + i];
  
  //Return the streamobject
  return out;
}


/***************************************************
 FUNCTION NAME: friend istream& operator>>(istream& in, bigNum& bN)
 PARAMETERS: string from user, bigNum object bN
 RETURN TYPE: in
 DESCRIPTION: friend function reads in a string from user and assigns it to bN's number[]. first assings input to character array, then uses a constructor to assign to bN
*****************************************************/
istream& operator>>(istream& in, bigNum& bN)
{
  char input[bN.MAX_DIGITS];    
  in >> input;
  int pos = 0;
  bN.amtDigits = 0;

  //count leading zeros
  while (input[pos] == '0')
    pos++;

  int start = pos;

  //count digits excluding leading zeros
  while (input[pos] != '\0')
  {
    pos++;
    bN.amtDigits++;
  }
 
  for (int i = 0; i < bN.amtDigits; i++)
    bN.number[bN.MAX_DIGITS - bN.amtDigits + i] = input[start + i];

  if (bN.amtDigits == 0)
    bN.number[bN.MAX_DIGITS - 1] = '0';

 //return the stream object
 return in; 
}


/*********************************************************
 FUNCTION NAME: bigNum operator-(const bigNum&) const;
 PARAMETERS: bigNum object rhs
 RETURN TYPE: bigNum result
 DESCRIPTION: subtracts bigNum rhs from another bigNum obj
**********************************************************/
bigNum bigNum::operator-(const bigNum& rhs) const
{
  bigNum result;
  int operand1 = 0;
  int operand2 = 0;
  int borrow = 10;
  int carry = 0;
  int difference = 0;

  for (int i = MAX_DIGITS - 1; i > -1; i--)
  {
    operand1 = number[i] - '0' - carry;
    operand2 = rhs.number[i] - '0';
    difference = operand1 - operand2;
    if (difference < 0)
    {
      operand1 = operand1 + borrow;
      difference = operand1 - operand2;
      carry = 1;
    }
    else
      carry = 0;
    result.number[i] = difference + '0';
  }

  //calculating result.amtDigits
  for (int j = 0; j < result.MAX_DIGITS; j++)
  {
    if (result.number[j] != '0')
    {
       result.amtDigits = result.MAX_DIGITS - j;
       break;
    }
    if (j == (result.MAX_DIGITS - 1))
    {
       result.amtDigits = 1;
    }
  }
  return result;
}


/*********************************************************
 FUNCTION NAME: bigNum operator-(int rhs) const;
 PARAMETERS: int rhs
 RETURN TYPE: bigNum result
 DESCRIPTION: converts rhs int bigNum obj and adds both objs 
************************************/
bigNum bigNum::operator-(int rhs) const
{
  //convert int rhs into bigNum obj
  int k = 1;
  bigNum convertedInt;
  convertedInt.amtDigits = 0;
 
  if (rhs == 0)
    convertedInt.number[convertedInt.MAX_DIGITS - 1] = '0';

  while (rhs > 0)
  {
    convertedInt.number[convertedInt.MAX_DIGITS - k] = rhs % 10 + '0';
    rhs = rhs / 10;
    convertedInt.amtDigits++;
    k++;
  }

  //copy bigNum operator-(const bigNum&) const
  bigNum result;
  int operand1 = 0;
  int operand2 = 0;
  int borrow = 10;
  int carry = 0;
  int difference = 0;

  for (int i = MAX_DIGITS - 1; i > -1; i--)
  {
    operand1 = number[i] - '0' - carry;
    operand2 = convertedInt.number[i] - '0';
    difference = operand1 - operand2;
    if (difference < 0)
    {
      operand1 = operand1 + borrow;
      difference = operand1 - operand2;
      carry = 1;
    }
    else
      carry = 0;
    result.number[i] = difference + '0';
  }
  
  //recalculate result.amtDigits
  for (int j = 0; j < result.MAX_DIGITS; j++)
  {
    if (result.number[j] != '0')
    {
       result.amtDigits = result.MAX_DIGITS - j;
       break;
    }
    if (j == (result.MAX_DIGITS - 1))
    {
       result.amtDigits = 1;
    }
  }
  return result;
}


/*********************************************************
 FUNCTION NAME: bigNum operator-(int lhs, const bigNum& rhs)
 PARAMETERS: int lhs and bigNum rhs
 RETURN TYPE: bigNum result
 DESCRIPTION: converts lhs into bigNum obj and adds it to bigNum rhs
********************************************************/
bigNum operator-(int lhs, const bigNum& rhs)
{
  //convert lhs using bigNum(int n)
  int i = 1;
  bigNum convertedlhs;
  convertedlhs.amtDigits = 0;
 
  if (lhs == 0)
    convertedlhs.number[convertedlhs.MAX_DIGITS - 1] = '0';

  while (lhs > 0)
  {
    convertedlhs.number[convertedlhs.MAX_DIGITS - i] = lhs % 10 + '0';
    lhs = lhs / 10;
    convertedlhs.amtDigits++;
    i++;
  }

  bigNum result;
  int operand1 = 0;
  int operand2 = 0;
  int borrow = 10;
  int carry = 0;
  int difference = 0;

  for (int i = result.MAX_DIGITS - 1; i > -1; i--)
  {
    operand1 = convertedlhs.number[i] - '0' - carry;
    operand2 = rhs.number[i] - '0';
    difference = operand1 - operand2;
    if (difference < 0)
    {
      operand1 = operand1 + borrow;
      difference = operand1 - operand2;
      carry = 1;
    }
    else
      carry = 0;
    result.number[i] = difference + '0';
  }
  
  //recalculate result.amtDigits
  for (int j = 0; j < result.MAX_DIGITS; j++)
  {
    if (result.number[j] != '0')
    {
       result.amtDigits = result.MAX_DIGITS - j;
       break;
    }
    if (j == (result.MAX_DIGITS - 1))
    {
       result.amtDigits = 1;
    }
  }
  return result;
}
