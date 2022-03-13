#include <iostream>
#include "myStack.h"
using namespace std;

/********************************
 FUNCTION NAME: myStack()
 PARAMETERS: none
 RETURN TYPE: none
 DESCRIPTION: default constructor sets stk to NULL and sets stkTop and capacity to 0
********************************/
myStack::myStack()
{
  stk = NULL;
  stkTop = capacity = 0;
}





/***********************************************
 FUNCTION NAME: myStack()
 PARAMETERS: int size
 RETURN TYPE: none
 DESCRIPTION: constructor sets stkTop to 0, capacity to size and assigns a char array of length size to stk
************************************************/
myStack::myStack(int size)
{
  stkTop = 0;
  capacity = size;
  stk = new char[size]; //char array of length size assigned to what stk points to
}





/***********************************************
 FUNCTION NAME: myStack
 PARAMETERS: const myStack& copy (object of myStack class)
 RETURN TYPE: none
 DESCRIPTION: constructor performs depp copy of copy obj parameter into *this object
************************************************/
myStack::myStack(const myStack& copy)
{
  capacity = copy.capacity;
  stkTop = copy.stkTop;
  stk = new char[capacity];
 
  for (int i = 0; i < capacity; i++)
    stk[i] = copy.stk[i];
}





/***********************************************
 FUNCTION NAME: operator=
 PARAMETERS: const myStack& rhs
 RETURN TYPE: myStack obj...*this
 DESCRIPTION: performs deep copy of parameter obj into *this object, checks for self assignments, avoids memory leaks
************************************************/
const myStack& myStack::operator=(const myStack& rhs)
{
  if (this != &rhs) //check for self assignment
  {
    if (stk != NULL)
      delete [] stk; //deallocate any memory before deep copy
 
    capacity = rhs.capacity;
    stkTop = rhs.stkTop;
    stk = new char[capacity]; //allocate memory to *this

    for (int i = 0; i < capacity; i++) //actual copying
      stk[i] = rhs.stk[i];
  }
  return *this;
}





/***********************************************
 FUNCTION NAME: ~myStack()
 PARAMETERS: none
 RETURN TYPE: none
 DESCRIPTION: destructor deallocates the dynamic array
************************************************/
myStack::~myStack()
{
  if (stk != NULL)
    delete [] stk;
}





/***********************************************
 FUNCTION NAME: push()
 PARAMETERS: chaar item
 RETURN TYPE: void
 DESCRIPTION: inserts parameter item to stkTop position of stk array and increments the stkTop index....resize stack by doubling capacity if its full
************************************************/
void myStack::push(char item)
{
//if array is full...resize using deep copy
  if (stkTop == capacity)
  {
    capacity = capacity * 2;
    char * temp;
    temp = new char[capacity];
    
    for (int i = 0; i < capacity/2; i++)
      temp[i] = stk[i];

    delete [] stk;

    stk = temp;

    temp = NULL;
  }

  stk[stkTop] = item;
  stkTop++;
}





/***********************************************
 FUNCTION NAME: top()
 PARAMETERS: none
 RETURN TYPE: char
 DESCRIPTION: returns the top item of the stack at position stk[stkTop - 1]
************************************************/
char myStack::top() const
{
  return stk[stkTop - 1];
}





/***********************************************
 FUNCTION NAME: pop()
 PARAMETERS: none
 RETURN TYPE: void
 DESCRIPTION: removes the top item from the stack
************************************************/
void myStack::pop()
{
/*******************
  char * temp;
  temp = new char[capacity];

  for (int i = 0; i < capacity; i++)
    temp[i] = stk[i + 1];

  delete [] stk;

  stk = temp;

  temp = NULL;
*************************/
  stkTop--;
}





/***********************************************
 FUNCTION NAME: isEmpty()
 PARAMETERS: none
 RETURN TYPE: bool
 DESCRIPTION: returns true if stack is empty and false otherwise
************************************************/
bool myStack::isEmpty() const
{
  if (stk != NULL)
      return false;

  else 
    return true;
}
