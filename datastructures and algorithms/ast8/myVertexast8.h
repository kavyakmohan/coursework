//Kavya Mohan
#include <iostream>

using namespace std;

template <class Type>
class vertex
{
  struct node
  {
    Type item;
    node * link;
  };

public:
  class edgeIterator
  {
  public:
    friend class vertex;
    edgeIterator();
    edgeIterator(node*);
    edgeIterator operator++(int);
    Type operator*();
    bool operator==(const edgeIterator&);
    bool operator!=(const edgeIterator&);
  private:
    node * current;
  };

  vertex();
  vertex(const vertex&);
  const vertex& operator=(const vertex&);
  ~vertex();
  edgeIterator begin();
  edgeIterator end();
  void addEdge(const Type&);
private:
  node * neighbors;
};

//EDGE ITERATOR MEMBER FUNCTIONS
//edgeIterator DEFAULT CONSTRUCTOR
template <class Type>
vertex<Type>::edgeIterator::edgeIterator()
{
  current = NULL;
}

//edgeIterator CONSTRUCTOR
template <class Type>
vertex<Type>::edgeIterator::edgeIterator(vertex<Type>::node * edge)
{
  //takes in node object which gets assigned to current
  current = edge;
}

//edgeIterator iterator operator function
template <class Type>
typename vertex<Type>::edgeIterator vertex<Type>::edgeIterator::operator++(int)
{
  //sets the iterator to point to the next node object
  //need to set current to point to the next node
  current = current->link;
  return *this;
}

//edgeIterator dereferencing operator function
template <class Type>
Type vertex<Type>::edgeIterator::operator*()
{
  //returns the item field of the node that current points to
  return current->item;
}

//edgeIterator == bool function
//compares the address of iterator on left with iterator on the right
//returns true if they point to the same node... false otherwise
template <class Type>
bool vertex<Type>::edgeIterator::operator==(const vertex<Type>::edgeIterator& rhs)
{
  return(current == rhs.current);
}

//edgeIterator != bool function
//compares address of iterator on the left w/ iterator on the right
//returns false if they point to the same node ... true otherwise
template <class Type>
bool vertex<Type>::edgeIterator::operator!=(const vertex<Type>::edgeIterator& rhs)
{
  return(current != rhs.current);
}


//VERTEX MEMBER FUNCTIONS
//vertex DEFAULT CONSTRUCTOR
template <class Type>
vertex<Type>::vertex()
{
  //sets neighbors to NULL
  neighbors = NULL;
}

//VERTEX COPY CONSTRUCTOR
template <class Type>
vertex<Type>::vertex(const vertex<Type>& copy)
{
  neighbors = NULL;

  node * newNode;   //pointer to create a node
  node * currentNode;   //pointer to traverse the list

  if (neighbors != NULL)  //if linked list isn't empty, delete nodes
  {
    node * temp;
    while (neighbors != NULL)
    {
      temp = neighbors;
      neighbors = neighbors->link;
      delete temp;
    }
  }

  if (copy.neighbors == NULL) //if copy obj has empty linked list
    neighbors = NULL;

  else                        //deep copy of copy obj into this obj
  {
    currentNode = copy.neighbors;

    neighbors = new node;
    neighbors->item = currentNode->item;
    neighbors->link = NULL;

    currentNode = currentNode->link;

    while (currentNode != NULL)
    {
      newNode = new node;
      newNode->item = currentNode->item;
      newNode->link = NULL;

      neighbors->link = newNode;
      neighbors = newNode;

      currentNode = currentNode->link;
    }
  }
}

//vertex assignment operator
template <class Type>
const vertex<Type>& vertex<Type>::operator=(const vertex<Type>& rhs)
{
  //performs deep copy of rhs into lhs obj
  if (this != &rhs)
  {
    node * newNode;   //pointer to create a node
    node * currentNode;   //pointer to traverse the list

    if (neighbors != NULL)  //if linked list isn't empty
    {
      node * temp;
      while (neighbors != NULL)
      {
        temp = neighbors;
        neighbors = neighbors->link;
        delete temp;
      }
    }

    if (rhs.neighbors == NULL)  //if rhs is empty
      neighbors = NULL;

    else                    //deep copy rhs into this obj
    {
      currentNode = rhs.neighbors;

      neighbors = new node;
      neighbors->item = currentNode->item;
      neighbors->link = NULL;

      currentNode = currentNode->link;

      while (currentNode != NULL)
      {
        newNode = new node;
        newNode->item = currentNode->item;
        newNode->link = NULL;

        neighbors->link = newNode;
        neighbors = newNode;

        currentNode = currentNode->link;
      }
    }
  }
  return *this;
}

//vertex DESTRUCTOR
//DESTROY LIST
template <class Type>
vertex<Type>::~vertex()
{
  //deallocates all nodes in neighbor linked list
  //destroy the linked list using head removals
  node * temp;    //pointer to deallocate memory occupied by node
  while (neighbors != NULL) //while there are nodes in the list
  {
    temp = neighbors;       //set temp to current node
    neighbors = neighbors->link;  //advance linked list
    delete temp;            //deallocate memory occupied by temp
  }
}

//vertex begin
template <class Type>
typename vertex<Type>::edgeIterator vertex<Type>::begin()
{
  //returns a edgeIterator object whose current will be the head
  //of the neighbor list for the vertex object
  vertex<Type>::edgeIterator temp(neighbors);
  return temp;
}

//VERTEX end
template <class Type>
typename vertex<Type>::edgeIterator vertex<Type>::end()
{
  //returns a edgeIterator obj whose current will be assigned to NULL
  vertex<Type>::edgeIterator temp(NULL);
  return temp;
}

//vertex add edge
template <class Type>
void vertex<Type>::addEdge(const Type& edge)
{
  //adds a new node into the neighbor list
  //implement using head insert
  node * newNode;
  newNode = new node;
  newNode->item = edge;

  newNode->link = neighbors;
  neighbors = newNode;
}
