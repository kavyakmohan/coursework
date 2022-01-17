//Kavya Mohan
#include <iostream>

using namespace std;

template <class Type>
class myStack
{
public:
  myStack();
  myStack(const myStack<Type>&);
  const myStack& operator=(const myStack<Type>&);
  ~myStack();
  void push(const Type&);
  Type pop();
  Type peek() const;
  bool isEmpty() const;
private:
  Type * stack;
  size_t size;
  size_t stackTop;    //last element added to the stack
};

//DEFAULT CONSTRUCTOR
template <class Type>
myStack<Type>::myStack()
{
  stackTop = 0;
  size = 10;
  stack = new Type[size];
}

//COPY CONSTRUCTOR
//deep copy of copy into this obj
template <class Type>
myStack<Type>::myStack(const myStack& copy)
{
  stack = NULL;

  delete [] stack;
  size = copy.size;
  stackTop = copy.stackTop;

  stack = new Type[size];

  for (int i = 0; i < stackTop; i++)
    stack[i] = copy.stack[i];
}

//ASSIGNMENT OPERATOR
//deep copy of rhs into lhs(this) obj
template <class Type>
const myStack<Type>& myStack<Type>::operator=(const myStack<Type>& rhs)
{
  if (this != &rhs)   //avoid self-copy
  {
    delete [] stack;
    size = rhs.size;
    stackTop = rhs.stackTop;

    stack = new Type[size];

    for (int i = 0; i < stackTop; i++)
      stack[i] = rhs.stack[i];
  }
  return *this;
}

//DESTRUCTOR
template <class Type>
myStack<Type>::~myStack()
{
  delete [] stack;    //deallocate memory occupied by the array
}

//PUSH
template <class Type>
void myStack<Type>::push(const Type& item)
{
  if (stackTop == size)     //first check if stack is full
  {
    Type *temp = new Type[size + 10];

    for (int i = 0; i < stackTop; i++)
      temp[i] = stack[i];

    delete [] stack;  //deallocate full stack
    stack = temp;     //larger array assigned to pointer
    temp = NULL;      //temp points to nothing
  }

  stack[stackTop] = item;   //item pushed to top of stack
  stackTop++;               //increment stackTop
}

//POP
template <class Type>
Type myStack<Type>::pop()
{
  //returns the top element
  //removes top element if stack is not empty
  Type temp = peek();   //store stackTop in temp

  if (!isEmpty())
    stackTop--;

  return temp;
}

//peek
template <class Type>
Type myStack<Type>::peek() const
{
  if(isEmpty())    //return empty constructor if stack is empty
    return Type();

  return stack[stackTop - 1]; //return stackTop w/o removing it
}

//isEmpty
template <class Type>
bool myStack<Type>::isEmpty() const
{
  //returns true if stack is empty
  return(stackTop == 0);
}
