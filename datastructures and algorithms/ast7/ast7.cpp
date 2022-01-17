//Kavya Mohan AST7
#include <iostream>
#include <fstream>
#include "myHeap.h"
using namespace std;

struct studentType
{
  string name;
  double gpa;
  int status, droppedCount, dayEnrolled;

  //return true if this student < s
  //else return false
  //smaller means higher priority
  bool operator <(const studentType& s) const
  {
    if (dayEnrolled < s.dayEnrolled)
      return true;
    else if (dayEnrolled > s.dayEnrolled)
      return false;
    else
    {
      if (status > s.status)
        return true;
      else if (status < s.status)
        return false;
      else
      {
        if (gpa > s.gpa && droppedCount < s.droppedCount)
          return true;
        if (gpa < s.gpa && droppedCount > s.droppedCount)
          return false;
      }
    }
  };
};

int main()
{
  //variables
  string inputFile;
  ifstream infile;
  int enrollmentCap;
  int waitlistCap;
  studentType temp;

  //allocate of type binMinHeap<studentType>
  binMinHeap<studentType> heap;

  //prompt uer for input file
  while(!infile.is_open())
  {
    cout << endl;
    cout << "Enter a filename: ";
    cin >> inputFile;
    infile.open(inputFile.c_str());
  }

  infile >> enrollmentCap;
  infile >> waitlistCap;

  //reading file and inserting into heap
  while(!infile.eof())
  {
    infile >> temp.name;
    infile >> temp.dayEnrolled;
    infile >> temp.gpa;
    infile >> temp.status;
    infile >> temp.droppedCount;

    heap.insert(temp);
  }

  infile.close();

  //CHECK IF NOT EMPTY BEFORE OUTPUTTING
  cout << endl;
  if (!heap.isEmpty())
  {
    int studentsEnrolled = 0;
    if (heap.getSize() < enrollmentCap)
      studentsEnrolled = heap.getSize();
    else
      studentsEnrolled = enrollmentCap;

    //output students enrolled from highest priority first
    cout << "Students enrolled" << endl;
    cout << "-------------------------------------------" << endl;
    for (int i = 0; i < studentsEnrolled; i++)
    {
      temp = heap.getMin();
      cout << temp.name << endl;
      heap.deleteMin();
    }
    cout << endl;
  }

  //check if waitlisted students exist
  if (!heap.isEmpty())
  {
    int studentsWaitlisted = 0;
    if (heap.getSize() < waitlistCap)
      studentsWaitlisted = heap.getSize();
    else
      studentsWaitlisted = waitlistCap;

    cout << "Waitlisted" << endl;
    cout << "-------------------------------------------" << endl;
    for (int i = 1; i <= studentsWaitlisted; i++)
    {
      temp = heap.getMin();
      cout << "#" << i << " " << temp.name << endl;
      heap.deleteMin();
    }
    cout << endl;
  }

  //output any unenrolledStudents
  if (!heap.isEmpty())
  {
    int unenrolledStudents = heap.getSize();
    cout << "Students enrollment rejected" << endl;
    cout << "-------------------------------------------" << endl;
    for (int i = 0; i < unenrolledStudents; i++)
    {
      temp = heap.getMin();
      cout << temp.name << endl;
      heap.deleteMin();
    }
    cout << endl;
  }
  return 0;
}
