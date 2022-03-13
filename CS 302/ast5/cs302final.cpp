/*
 * Kavya Mohan, 2001362917, Assignment 5
 * Description:
 * Input:
 * Output:
 */

 #include <iostream>
 #include <fstream>
 #include <string>
 #include <cmath>
 using namespace std;

 struct binTreeNode
 {
   int id;
   bool flag;
   binTreeNode * left;
   binTreeNode * right;
 };

// int plinko(binTreeNode *, int);  //recursive, preorder
void preorder(binTreeNode * r);
void deleteTree(binTreeNode * r);
void preorderBuilding(int completeNodeCnt, binTreeNode * r, int idCounter);

 int main()
 {
   string inputFile;
   ifstream infile;
   int testCases;
   int height;
   int rounds;
   int chipLocation;

   //prompt for valid input file
   while (!infile.is_open())
   {
     cout << "Enter filename: ";
     cin >> inputFile;
     infile.open(inputFile.c_str());
   }

   infile >> testCases;
   cout << "test cases: " << testCases << endl;

   //iterating thru each testCase
   for (int i = 0; i < 1; i++)
   {
     infile >> height;
     infile >> rounds;

     int idCounter = 1;
     int completeNodeCnt = pow(2, (h+1)) - 1;
     cout << "complete node count" << completeNodeCnt << endl;

     //build binary tree using preorder traversal
     binTreeNode * root;
     root = new binTreeNode;
     preorderBuilding(completeNodeCnt, root, idCounter);




     //SIMULATING GAME
//     for (int i = 0; i < rounds; i++)
//     {
//      chipLocation = plinko(tree, i);
//     }


  cout << "going to print out tree" << endl;
     preorder(root);
     cout << "done printing tree" << endl;
     //destroy tree
     cout << "going to delete tree" << endl;
     deleteTree(root);
     //call function that deallocates tree
     delete tree;
   }

   //close file
   return 0;
 }
void preorderBuilding(int totalNodes, int completeNodeCnt, binTreeNode * r, int idCounter)
{
  if (totalNodes < completeNodeCnt)
  {
    r->id = idCounter;
    totalNodes++;
    preorderBuilding(height, r->left, idCounter * 2);
    preorderBuilding(height, r->right, idCounter * 2 + 1);
  }
}

void preorder(binTreeNode * r)
{
  if (r != NULL)
  {
    cout << r->id << endl;
    preorder(r->left);
    preorder(r->right);
  }
  return;
};

 //plinko function(root)
 /*
int plinko(binTreeNode * r)
{
  if (r != NULL)
  {
    if (r->flag == false)
    {
      r->flag = true;
      plinko(r->left);
    }
    else
    {
      r->flag = false;
      plinko(r->right);
    }
  }
  return r-> item;
}
*/

 //destroy tree function
 //recursive postordeer
 void deleteTree(binTreeNode * r)
 {
   if (r != NULL)
   {
     deleteTree(r->left);
     deleteTree(r->right);
     delete r;
   }
   return;
 }
