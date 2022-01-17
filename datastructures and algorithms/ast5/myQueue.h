//myQueue.h
//Kavya Mohan CS302 AST5

#include <cstdlib>
#include <iostream>
#include <assert.h>
using namespace std;

//CLASS DECLARATION
template <class Type>
class myQueue
{
  struct queueNode
  {
    Type item;
    queueNode * link;
  };

  public:
    myQueue();
    ~myQueue();
    Type peek() const;
    void enqueue(const Type&);
    void dequeue();
    bool isEmpty() const;
  private:
    queueNode * front;
    queueNode * back;
};

//default constructor initializes an empty queue
template <class Type>
myQueue<Type>::myQueue()
{
  front = NULL;     //set front to NULL
  back = NULL;      //set back to NULL
}

//destructor deallocates the structure
template <class Type>
myQueue<Type>::~myQueue()
{
  queueNode * temp;

  //while there are elements left in the queue
  while (front != NULL)
  {
    //temp points at the current node
    temp = front;

    //advance first to the next node
    front = front->link;

    //deallocate memory occupied by temp
    delete temp;
  }

  back = NULL;
}

//returns item of node at the front of the queue
template <class Type>
Type myQueue<Type>::peek() const
{
  if(!isEmpty())
    return front->item;
}

//inserts new item to the back of the queue
template <class Type>
void myQueue<Type>::enqueue(const Type& newElement)
{
  queueNode * newNode;

  newNode = new queueNode;  //create the node

  newNode->item = newElement;     //store the info
  newNode->link = NULL;           //initialize link field to NULL

  if (isEmpty())
  {
    front = newNode;
    back = newNode;
  }

  else
  {
    back->link = newNode;
    back = back->link;
  }
}

//removes the front node from the queue
template <class Type>
void myQueue<Type>::dequeue()
{
  queueNode * temp;

  if (!isEmpty())
  {
    //make temp point to 1st node
    temp = front;

    //advance front
    front = front->link;

    //delete the first node
    delete temp;

    //if after deletion, queue is empty
    if (front == NULL)
      back = NULL;
  }

  else
    cout << "Cannot remove from an empty queue" << endl;
}

//returns true if front is NULL
template <class Type>
bool myQueue<Type>::isEmpty() const
{
  return (front == NULL);
}
