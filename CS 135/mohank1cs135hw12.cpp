/* Kavya Mohan 2001362917 CS135 SECTION 1020 Assignment12
 * Description: hypercube assignment
 * Input: test file with adjacenty matrix
 * Output: children of each node and route from start to end point*/

//Hypercube by Jorge
#include<iostream>
#include<string>
#include<stdlib.h>  //For srand
#include<time.h>    //For Time

#define MAXSIZE 100 //Max Size of Your Graph

using namespace std;

//For your code to compile. The first thing you need to do is declare your two structs:

//NODE and GRAPH.

//NODE:
//Should have the following Components:
//-id (of type int)
//name (of type string)
//children  (an array of children of size MAXSIZE of type int

//GRAPH
//Should have the following Components:
//name (of type string)
//size (of type int) this keeps the actual number of active nodes in your cube. So this will be 8 for the sample input but could vary
//we use this know the real size of our arrays since the rest is unused data since we hardcoded our arrays to be of MAXSIZE
//an array of nodes of the type struct NODE of size MAXSIZE.

//Your Code Here
struct NODE {
	int id;
	string name;
	int children[MAXSIZE];
};

struct GRAPH {
	string name;
	int size;
	NODE node[MAXSIZE]; //array of nodes
};

//Once you declare your two structs your code SHOULD COMPILE WITHOUT DOING ANY ADDITIONAL MODIFICATIONS.
//So do this first before doing anything else!

//DO NOT DO ANYTHING ELSE UNTIL YOU DO THAT. IF YOUR CODE DOES NOT COMPILE AFTER YOU MAKE YOUR TWO STRUCTS WITH ALL OF THEIR COMPONENTS.
//THEN YOU MESSED UP AND NEED TO FIX THAT BEFORE PROCEEDING. YOU HAVE BEEN WARNED.
//SERIOUSLY

void initGraph(GRAPH&, string);
void initNode(NODE&, int);
void readGraph(GRAPH&);
void printGraph(GRAPH);
void printNode(NODE);
bool findRoute(GRAPH);
void readStartEnd(int &start, int& end);
bool visitChild(GRAPH g, int curr, int end, int level);

int main(){
	cout << "The Network!" << endl;
	struct GRAPH network;
	initGraph(network, "Hypercube");
	readGraph(network);
	printGraph(network);
	srand(time(NULL));
	if(findRoute(network)){
		cout << "\nAnother Happy Landing!" << endl;
	}
    	return 0;
}

void initGraph(GRAPH& g, string n){
	g.name = n;
	g.size = 0;
	for(int i=0;i<MAXSIZE;i++){
		initNode(g.node[i], i);
	}
}

void initNode(NODE& n, int id){
	n.id = id;
	n.name = "";
	for(int i=0;i<MAXSIZE;i++){
		//Your Code here
		//Initialize the children array to be all -1
		n.children[i] = -1;
	}
}

void readGraph(GRAPH& g){
	cin >> g.size;
	//Your Code Here
	//Double For Loop to read in the adjacency matrix into the children array of a specific node.
	//The outer loop should look like for(int f=0;f<g.size && f<MAXSIZE; f++){
	//And the inner loop should loop through the children array of each node. so children[t]
	for (int f = 0; f < g.size && f < MAXSIZE; f++){
		for (int t = 0; t < g.size; t++){
			cin >> g.node[f].children[t];
		}
	}
}

void printGraph(GRAPH g){
	cout << g.name << ":"<< endl;
	for(int i=0; i<g.size && i<MAXSIZE;i++){
		//Your Code Here
		//Call printNode and pass it a single node.
		printNode(g.node[i]);
	}
}

void printNode(NODE n){
	cout << n.id << " Node: " << n.name << endl;
	cout << "Children: ";
	for(int i=0; i<MAXSIZE; i++){
		//Your Code Here
		//Check if the children at index i has a value > 0 and if so then cout << i
		if (n.children[i] > 0){
			cout << i;
		}
	}
	cout << endl;
}

//This function reads the Start: 0 End: 7 beneath the matrix.
void readStartEnd(int &start, int& end){
	string temp;
	cin >> temp >> start;
	cout << temp << " " << start << endl;;
	cin >> temp >> end;
	cout << temp << " " << end << endl << endl;
}

bool findRoute(GRAPH g){
	int start, end, curr;
	readStartEnd(start, end);
	return visitChild(g, start, end, 0);
}

//Recursive Function. MUAHAHAHAH!!!!
bool visitChild(GRAPH g, int curr, int end, int level){
	int start = curr;
	//Your Code Here
	//Base Case Here. We have 2 base cases:

	//Base Case1: if the level variable is >= MAXSIZE then return FALSE because 
	//It means we are giving up we went 100 levels deep in the recursion. Don't go deeper. Too much Inception!
	//https://www.youtube.com/watch?v=YoHD9XEInc0
	if (level >= 100){
		return false;
	}

	//Base Case2:
	//Check if curr is equal to end, if so we have reached our destination! If so then
	//cout << "\nRoute: "; and return TRUE for success!
	if (curr == end){
		cout << "\nRoute: ";
		return true;
	}

	//Otherwise we are not done with the search and have to 
	//Pick a child to visit. At random but from available links;
	for(int i=0; i<MAXSIZE; i++){ //Loop a lot of times
		int t = rand() % g.size;
		if (g.node[curr].children[t] == 1){
		//	cout << "Picked:"<<t<< " ";
			curr = t;
			break;
		}
		//Search if the current node (node[curr]'s children at index [t] is equal to 1. If yes this means
		//there is a connection there 
			//cout << "Picked:"<<t<< " "; //For Debugging
			//if yes then assign that value to curr.   curr  <-- t;
			// and break out of the loop
		//In short, what you are doing is randomly picking from the available edges. You can do this
		//in other ways, or better more elegant ways, but just make sure your algorithm works and 
		//make sure it picks a valid edge + not picking yourself so you don't go in cicles
		//you may still go in cycles but at least through other nodes and not 3->3->3.
		//3->4->3 is ok.
	}

	//After you have picked a node to use and copied over to curr. then recursively call the function on the new curr 
	//but don't forget to increase level+1 to keep track of how deep we are!
	if(visitChild(g, curr, end, level+1)){
		//If we are here it means we found the destination and are now backtracking through the recursions and as we do so
		//we print out the curr
		cout << curr << "<-";
		//if we are at level 0 we go ahead and print the start
		if(level == 0){
			cout << start;
		}
		return true; //pass our true to the function that called us
	}
	return false;	//..or false if we failed (this means we found no success.
}




