/*
 * myStack.h
 * Kavya Mohan CS302 Assignment 1
 */

#include <cstdlib>
#include <iostream>
using namespace std;

// CLASS DECLARATION
template <class type>
class myStack
{
public:
	myStack();
	myStack(const myStack<type>&);
	~myStack();
	const myStack& operator=(const myStack<type>&);
	void clearStack();
	void push(const type&);
	type peek() const;
	type pop();
	bool isEmpty() const;
	int stackSize() const;
private:
	struct node
	{
		type item;
		node * link;
	};

	int size;
	node * stackTop;
};


// DEFAULT CONSTRUCTOR
// initializes an empty stack
template <class type>
myStack<type>::myStack()
{
	size = 0;
	stackTop = NULL;
}


// COPY CONSTRUCTOR
// Creates a deep copy of the copy object into the *this object
template <class type>
myStack<type>::myStack(const myStack<type>& copy)
{
	size = copy.size;					//copy's size copied into size of this

	node * newNode, * current, * last;

	if (stackTop != NULL)				//if stack isn't empty
		clearStack();					//makes stack empty before deep copy

	if (copy.stackTop == NULL)			//if copy stack is empty
		stackTop = NULL;				
	else
	{
		current = copy.stackTop;		//current points to copy stack

		//copy stackTop element of the stack
		stackTop = new node;			//create the node
		stackTop->item = current->item;	//copy the info
		stackTop->link = NULL;			//link field of node set to NULL
		last = stackTop;				//set last to point to the node
		current = current->link;		//set current to point to the next node

		//copy the remaining stack
		while (current != NULL)
		{
			newNode = new node;
			newNode->item = current->item;
			newNode->link = NULL;
			last->link = newNode;
			last = newNode;
			current = current->link;
		}
	}
}


// DESTRUCTOR
// deallocates the entire stack
template <class type>
myStack<type>::~myStack()
{
	clearStack();
}


// DEFAULT ASSIGNMENT OPERATOR
// creates a deep copy of the rhs object into the *this object(lhs object),
// use when sliding over stacks to fill gaps
template <class type>
const myStack<type>& myStack<type>::operator=(const myStack<type>& rhs)
{
	if (this != &rhs)
	{
		//Your code goes here
		size = rhs.size;						//copy over size from rhs

		node * newNode, * current, * last;

			if (stackTop != NULL)				//if stack isn't empty
				clearStack();					//makes stack empty

			if (rhs.stackTop == NULL)			//if copy stack is empty
				stackTop = NULL;

			else
			{
				current = rhs.stackTop;		//current points to copy stack

				//copy stackTop element of the stack
				stackTop = new node;			//create the node
				stackTop->item = current->item;	//copy the info
				stackTop->link = NULL;			//link field of node set to NULL
				last = stackTop;				//set last to point to the node
				current = current->link;		//set current to point to the next node

				//copy the remaining stack
				while (current != NULL)
				{
					newNode = new node;
					newNode->item = current->item;
					newNode->link = NULL;
					last->link = newNode;
					last = newNode;
					current = current->link;
				}
			}
	}
	return *this;
}


// pushes element to the top of the stack
template <class type>
void myStack<type>::push(const type& element)
{
	node * temp;				//pointer to create the new node
	temp = new node;			//create the node

	temp->item = element;		//store element in the node
	temp->link = stackTop;		//insert newNode before stackTop
	stackTop = temp;			//set stackTop to point to the new top node

	size++;
}


// returns the item field of the front node without removing the node
// if the stack is empty then return a default value, you can use return type()
template <class type>
type myStack<type>::peek() const
{
	if (stackTop != NULL)
		return stackTop->item;

	else
		return type();
}


// returns and removes the top node from the stack if the stack is not empty
template <class type>
type myStack<type>::pop()
{
	if (stackTop != NULL)
	{
		node * temp;
		node poppedObj;
		temp = stackTop;			//temp points to top node
	        poppedObj.item = peek();
		stackTop = stackTop->link;	//advance stackTop to the next node
		delete temp;				//delete the top node
		size--;
		return poppedObj.item;
	}

	else
		return type();
}


// returns true if the stack is empty and returns false if the stack is not empty
template <class type>
bool myStack<type>::isEmpty() const
{
	return (stackTop == NULL);
}


// returns the size field
template <class type>
int myStack<type>::stackSize() const
{
	return size;
}


// destroys the stack, i.e.  deallocates all the nodes in the stack
template <class type>
void myStack<type>::clearStack()
{
	size = 0;

	node * temp;						//pointer to delete node

	while (stackTop != NULL)			//while there are elements in the stack
	{
		temp = stackTop;				//temp points to current top node
		stackTop = stackTop->link;		//stackTop points to node underneath actual top
		delete temp;					//deallocate memory pointed to by temp (aka actual top)
	}
}
