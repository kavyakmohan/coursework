#include "myStack.h"
#include <cstdlib>

/*********************************
 * FUNTION NAME: myStack()
 * PARAMETERS: none
 * RETURN TYPE: none
 * DESCRIPTION: default constructor sets head to NULL
************************************/
myStack::myStack()
{
  head = NULL;
}



/*********************************
 * FUNTION NAME: myStack()
 * PARAMETERS: int size
 * RETURN TYPE: none
 * DESCRIPTION: constructor allocates size number of nodes to linked list
************************************/
myStack::myStack(int size)
{
  node * list;
  list = NULL;
  
  for (int i = 0; i < size; i++)
  {
    list = new node;
    list->link = head;
    head = list;
  }  

}




/*********************************
 * FUNTION NAME: myStack
 * PARAMETERS: const myStack& copy
 * RETURN TYPE: none
 * DESCRIPTION: copy constructors performs a deep copy of parameter into obj constructor is creating
************************************/
myStack::myStack(const myStack& copy)
{
  node * front;
  front = NULL;
  if(copy.head != NULL)
  {
    front = new node;
    front->item = copy.head->item;
    front->link = NULL;
    node * i = copy.head;
    node * j = front;
    while(i->link!=NULL)
    {
      i = i->link;
      j->link = new node;
      j = j->link;
      j->item = i->item;
      j->link = NULL;
    }
  }
}




/*********************************
 * FUNTION NAME: operator=(const myStack& rhs)
 * PARAMETERS: const myStack& rhs
 * RETURN TYPE: myStack obj
 * DESCRIPTION: performs a deep copy of rhs into lhs, check for self assignments and avoid memory leaks
************************************/
const myStack& myStack::operator=(const myStack& rhs)
{
  if (this != &rhs)
  {
    head = NULL;

    if(rhs.head != NULL)
    {
      head = new node;
      head->item = rhs.head->item;
      head->link = NULL;
      node * i = rhs.head;
      node * j = head;
      while(i->link != NULL)
      {
        i = i->link;
        j->link = new node;
        j = j->link;
        j->item = i->item;
        j->link = NULL;
      }
    }
    return *this;
  }
}




/*********************************
 * FUNTION NAME: ~myStack()
 * PARAMETERS: none
 * RETURN TYPE: none
 * DESCRIPTION: destructor deallocates the linked list that starts at head
************************************/
myStack::~myStack()
{
  node * i;
  while (head!=NULL)
  {
    i = head;
    head = head->link;
    delete i;
  }
}




/*********************************
 * FUNTION NAME: push()
 * PARAMETERS: int element
 * RETURN TYPE: void
 * DESCRIPTION: allocates a new node and sets this node's item field to element and inserts it to the front of the linked linke
************************************/
void myStack::push(int element)
{
  //head insert
  node * tmp;
  tmp = new node;
  tmp->item = element;
  tmp->link = head;
  head = tmp;
  tmp = NULL;
}




/*********************************
 * FUNTION NAME: top()
 * PARAMETERS: none
 * RETURN TYPE: int
 * DESCRIPTION: returns head->item ... only call if head->item isn't NULL
************************************/
int myStack::top() const
{
  if (head != NULL)
    return head->item;
}




/*********************************
 * FUNTION NAME: pop()
 * PARAMETERS: none
 * RETURN TYPE: void
 * DESCRIPTION: removes the front element of the linked list if list isn't empty
************************************/
void myStack::pop()
{
  if (head != NULL)
  {
    //head removal
    node * del;
    del = head;
    head = head->link;
    delete del;
  }
}




/*********************************
 * FUNTION NAME: isEmpty()
 * PARAMETERS: none
 * RETURN TYPE: bool
 * DESCRIPTION: returns true if stack is empty and false otherwise
************************************/
bool myStack::isEmpty() const
{
  if (head != NULL)
    return false;

  else
    return true;  
}
