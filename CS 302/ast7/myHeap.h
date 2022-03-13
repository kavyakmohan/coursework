//Kavya Mohan AST7
#include <iostream>
using namespace std;

template<class Type>
class binMinHeap
{
public:
  binMinHeap(int = 10);
  binMinHeap(const binMinHeap <Type >&);
  ~binMinHeap();
  const binMinHeap<Type>& operator=(const binMinHeap <Type>&);
  void insert(const Type &);
  void deleteMin();
  Type getMin() const;
  bool isEmpty() const;
  void bubbleUp(size_t);
  void bubbleDown(size_t);
  size_t getSize() const;
private:
  size_t capacity;
  size_t size;
  Type * heapArray;
};


//DEFAULT CONSTRUCTOR
template<class Type>
binMinHeap<Type>::binMinHeap(int capacity)
{
  this->capacity = capacity;
  size = 0;
  heapArray = new Type[capacity];
}


//COPY CONSTRUCTOR
template<class Type>
binMinHeap<Type>::binMinHeap(const binMinHeap<Type>& copy)
{
  capacity = copy.capacity;
  size = copy.size;

  heapArray = new Type[capacity];
  for (int i = 1; i <= size; i++)
    heapArray[i] = copy.heapArray[i];
}


//DESTRUCTOR
template<class Type>
binMinHeap<Type>::~binMinHeap()
{
  delete [] heapArray;
}

//ASSIGNMENT OPERATOR
template<class Type>
const binMinHeap<Type>& binMinHeap<Type>::operator=(const binMinHeap<Type>& rhs)
{
  capacity = rhs.capacity;
  size = rhs.size;

  heapArray = new Type[capacity];
  for (int i = 1; i <= size; i++)
    heapArray[i] = rhs.heapArray[i];
}

//INSERT FUNCTION
template<class Type>
void binMinHeap<Type>::insert(const Type& item)
{
  heapArray[size + 1] = item;   //insert at end of heap
  size++;                       //increment size

  if ((capacity - size) == 1)   //resize if necessaary
  {
    capacity += 2;
    Type * temp;
    temp = new Type[capacity];
    for (int i = 1; i <= size; i++)
      temp[i] = heapArray[i];

    delete [] heapArray;
    heapArray = temp;
    temp = NULL;
  }
  bubbleUp(size);               //bubbleUp new item
}


//DELETEMIN FUNCTION
template<class Type>
void binMinHeap<Type>::deleteMin()
{
  heapArray[1] = heapArray[size];   //last item in heap is new min
  size--;                           //decrement size
  bubbleDown(1);                    //bubble down new min
}


//GETMIN FUNCTION
//returns the min element (root element) without removing it
template<class Type>
Type binMinHeap<Type>::getMin() const
{
  if(!isEmpty())
    return heapArray[1];
  return heapArray[0];
}

//ISEMPTY FUNCTION
//returns true if structure is empty
template<class Type>
bool binMinHeap<Type>::isEmpty() const
{
  return (size == 0);
}

//BUBBLE UP FUNCTION
//bubbles up the element at the index position of the heapArray
//until it can't bubble up any further aka index = 1
//or if parent has higher priority
template<class Type>
void binMinHeap<Type>::bubbleUp(size_t index)
{
  //if we are at the root
  if (index == 1)
    return;

  //if parent has higher priority
  if (heapArray[index/2] < heapArray[index])
    return;

  //if child has higher priority
  else
  {
    Type temp = heapArray[index/2];         //swap parent & child
    heapArray[index/2] = heapArray[index];
    heapArray[index] = temp;
    bubbleUp(index/2);                      //bubbleUp from items new position
  }
}

//BUBBLEDOWN FUNCTION
template<class Type>
void binMinHeap<Type>::bubbleDown(size_t index)
{
  //check if heapArray[index] is leaf
  if (index * 2 > size)
    return;

  //if 2 children exist
  if ((index * 2 + 1) <= size)
  {
    size_t parent = index;
    size_t leftChild = index * 2;
    size_t rightChild = index * 2 + 1;
    Type temp;

    //if leftChild has higher priority
    if (heapArray[leftChild] < heapArray[rightChild])
    {
      if (heapArray[leftChild] < heapArray[parent])   //if child < parent
      {
        temp = heapArray[parent];                     //swap parent & child
        heapArray[parent] = heapArray[leftChild];
        heapArray[leftChild] = temp;
        bubbleDown(leftChild);                        //continue to bubbleDown
      }
      else
        return;
    }

    //if rightChild has higher priority
    if (heapArray[rightChild] < heapArray[leftChild])
    {
      if (heapArray[rightChild] < heapArray[parent])    //if child < parent
      {
        temp = heapArray[parent];                       //swap parent & child
        heapArray[parent] = heapArray[rightChild];
        heapArray[rightChild] = temp;
        bubbleDown(rightChild);                         //continue to bubbleDown
      }
      else
        return;
    }
  }

  //if only 1 child exists
  if( ((index * 2) <= size) && ((index * 2 + 1) > size) )
  {
    size_t parent = index;
    size_t child = index * 2;
    if (heapArray[child] < heapArray[parent])
    {
      Type temp = heapArray[parent];          //swap parent & child
      heapArray[parent] = heapArray[child];
      heapArray[child] = temp;
      bubbleDown(child);                      //continue to bubbleDown
    }
    else
      return;
  }
}


//GETSIZE FUNCTION
//returns amount of elements currently used in the structure
template<class Type>
size_t binMinHeap<Type>::getSize() const
{
    return size;
}
