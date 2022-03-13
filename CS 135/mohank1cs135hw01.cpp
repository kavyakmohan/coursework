/* Kavya Mohan 2001362917 CS 135 Section 1020 Assignment01
 * Description: Program to create a business card
 * Input: name, title, location, and email
 * Output: Input data is displayed as a business card */

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main ()
{
string name;
string title;
string location;
string email;

// accept inputs
cout << "Enter your name: ";
getline(cin, name);

cout << "Enter your title: ";
getline(cin, title);

cout << "Enter your location: ";
getline(cin, location);

cout << "Enter your email: ";
getline(cin, email);

// print business card
cout << "+-----------------------------------------+" << endl;
cout << "| " << setw(40) << left << " "        << "|" << endl;
cout << "| " << setw(40) << left << name       << "|" << endl;
cout << "| " << setw(40) << left << title      << "|" << endl;
cout << "| " << setw(40) << left << location   << "|" << endl;
cout << "| " << setw(40) << left << email      << "|" << endl;
cout << "| " << setw(40) << left << " "        << "|" << endl;
cout << "+-----------------------------------------+" << endl;

return 0;
}
