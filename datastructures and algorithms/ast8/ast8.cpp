//Kavya Mohan
#include <iostream>
#include <string>
#include <fstream>
#include "myStackast8.h"
#include "myVertexast8.h"

using namespace std;

bool dfs(int, vertex<int> *, bool *, bool *);
void topologicalSort(int, vertex<int> *, myStack<int> &, bool *);

int main()
{
  ifstream infile ;       //filestreams
  string inputFile;

  int vertices, edges;    //managing file input
  int from, to;

  bool cycleFound = false;  //detecting cycles
  bool * visited;
  bool * recursiveStack;

  vertex<int> * sticks;   //dynamic array of vertex objects

  //prompt for valid file
  while(!infile.is_open())
  {
    cout << "Enter a filename: ";
    cin >> inputFile;
    infile.open(inputFile.c_str());
    cout << endl;
  }

  infile >> vertices;     //number of sticks
  infile >> edges;        //number of dependencies

  sticks = new vertex<int>[vertices + 1]; //array of vertex objects

  for (int i = 0; i < edges; i++)
  {
    //read an edge
    infile >> from;   //"from" stick is on top of "to" stick
    infile >> to;

    //call addEdge function to add edge to linked list
    sticks[from].addEdge(to);
  }

  //initialize boolean arrays to false
  visited = new bool[vertices + 1];
  recursiveStack = new bool [vertices + 1];
  for (int i = 1; i <= vertices; i++)
    visited[i] = recursiveStack[i] = false;

  //for each vertex, as long as it has not been visited and no cycle has been detected
  //call dfs function and store return value
  for (int i = 1; i <= vertices; i++)
    if(!visited[i] && !cycleFound)
      cycleFound = dfs(i, sticks, visited, recursiveStack);

  if (cycleFound)
    cout << "IMPOSSIBLE! YOU CANNOT WIN!" << endl;

  else
  {
    myStack<int> stackObj;    //created stack object

    for (int i = 1; i <= vertices; i++) //reinitialize visited array
      visited[i] = false;

    for (int i = 1; i <= vertices; i++) //call topologicalSort for each unvisited vertex
      if(!visited[i])
        topologicalSort(i, sticks, stackObj, visited);

    while(!stackObj.isEmpty())      //outputtin gin topological order
      cout << stackObj.pop() << endl;
  }

  infile.close();
  delete [] sticks; //call destructor for each element(linked list) in array
  delete [] visited;
  delete [] recursiveStack;
  cout << endl;
  return 0;
}

//return true if a cycle has been found
bool dfs(int currNode, vertex<int> * graph, bool * visited, bool * recursiveStack)
{
  if(!visited[currNode])
  {
    visited[currNode] = recursiveStack[currNode] = true;

    vertex<int>::edgeIterator iter;

    //iter goes thru graph[currNode]'s linked list
    for (iter = graph[currNode].begin(); iter != graph[currNode].end(); iter++)
    {
      if(!visited[*iter])       //call dfs on unvisited nodes
        if(dfs(*iter, graph, visited, recursiveStack))
          return true;

      if(visited[*iter])    //checks if already visited item is part of cycle already
        if (recursiveStack[*iter])
          return true;
    }
  }
  recursiveStack[currNode] = false;
  return false;
}

void topologicalSort(int curr, vertex<int> * graph, myStack<int> & stackObj, bool * visited)
{
  visited[curr] = true;

  vertex<int>::edgeIterator iter;

  //iter goes thru vertex's unvisited adjacent nodes
  for (iter = graph[curr].begin(); iter != graph[curr].end(); iter++)
    if(!visited[*iter])
      topologicalSort(*iter, graph, stackObj, visited);

  stackObj.push(curr);    //pushes node whose ancestors are all on stack already
}
