/* Kavya Mohan 2001362917 CS 135 Section 1020 Assignment02
 * Description: Calculator program
 * Input: two integers
 * Output: solutions of arithmetic operations involving inputs */

#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>

using namespace std;

int main () {

int num1, num2, ans, rem;
float ansf;
string e, n;
e="Enter ";
n="Number: ";

//prompting user for first integer//
cout<<e<<"First "<<n;
cin>>num1;

//prompting user for second integer//
cout<<e<<"Second "<<n;
cin>>num2;

//num1/num2//
ans=num1/num2;
rem=num1%num2;
cout<<num1<<" / "<<num2<<" = "<<ans<<" "<<rem<<'/'<<num2<<endl;

//num1*num2//
ans=num1*num2;
cout<<num1<<" * "<<num2<<" = "<<ans<<endl;

//num1+num2//
ans=num1+num2;
cout<<num1<<" + "<<num2<<" = "<<ans<<endl;

//num1-num2//
ans=num1-num2;
cout<<num1<<" - "<<num2<<" = "<<ans<<endl;

//num1 squared//
ans=pow(num1,2);
cout<<num1<<" squared"<<" = "<<ans<<endl;

//num1/float(num2)//
ansf=(float)num1/(float)num2;
cout<<num1<<" / "<<"float"<<"("<<num2<<")"<<" = "<<ansf<<endl;

//num1+num2/num1//
ans=num1+(num2/num1);
rem=num2%num1;
cout<<num1<<" + "<<num2<<" / "<<num1<<" = "<<ans<<" "<<rem<<'/'<<num1<<endl;

//negative num1//
ans=num1*(-1);
cout<<"Negative "<<num1<<" = "<<ans<<endl;
	
return 0;
}

