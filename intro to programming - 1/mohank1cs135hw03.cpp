/* Kavya Mohan 2001362917 CS 135 Section 1020 Assignment03 
 * Description: Program that allows users to run a calculator or take a quiz 
 * Input: characters, floats
 * Output: Math operation results or quiz results */

#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

int main ()
{
char input;

cout << "Enter Which Program You Wish To Run: "<< endl;
cout << "A: Calculator" << endl;
cout << "Q: Quiz" << endl;
cin >> input;

	// CALCULATOR
	if (input == 'A')
		{
		// Declaring Variables
		float num1, num2, ans;
		char oper;

		cout << " " << endl;
		cout << "Running Calculator" << endl;

		// Prompting user inputs
		cout << "Enter First Number: ";
		cin >> num1;
		cout << "Enter Second Number: ";
		cin >> num2;

		// Listing operations
		cout << "Enter operation to perform from list: " << endl;
		cout << "A: Addition" << endl;
		cout << "S: Subtraction" << endl;
		cout << "M: Multiplication" << endl;
		cout << "D: Division" << endl;
		cout << "P: Power" << endl;
		cout << "C: Comparison" << endl;
		cout << "O: Modulus" << endl;

		// Prompting user input
		cout << " " << endl;
		cin >> oper;

		// Addition
		if (oper == 'A')			
	 	    ans = num1 + num2;

		// Subtraction
		if (oper == 'S')
		    ans = num1 - num2;
	
		// Multiplication
		if (oper == 'M')
		    ans = num1 * num2;
	
		// Division
		if (oper == 'D')
			if (num2 == 0)
			{
			cout << "Division by Zero Detected. Aborting!" << endl;
			return -1;
			}

			else
			ans = num1 / num2;

		// Power
		if (oper == 'P')
			if (num1 == 0 && num2 < 0)	
			return -1;
	
			else
			ans = pow(num1,num2);

		// Comparison
		if (oper == 'C')
			if (num1 > num2)
			cout << num1 << " is greater than " << num2 << endl;
		
		 	else if (num1 < num2)
		 	cout << num1 << " is less than " << num2 << endl;

		 	else if (num1 == num2)
		 	cout << num1 << " is equal to " << num2 << endl;
		 
		// Modulus
	        if (oper == 'O')
		    ans = static_cast<int>(num1) % static_cast<int>(num2);
		
		// ANSWER
		if (oper == 'A' || oper == 'S' || oper == 'M' || oper == 'D' || oper == 'P' || oper == 'O' )
                	{
			cout << "The Answer to life is: " << ans << endl;
			}

		else if (oper != 'C')
			cout << "The Answer to life is: " << -num1 << endl;
		}

	// QUIZ
	else if (input == 'Q')
		{
		// Declaring Variables
		int s1, s2, s3, s4, s5, s6, s7, score;
		char ans;

		cout << "Running Quiz" << endl;
		cout << "Hello there, Welcome to the Automated Jedi Test, Please Answer each Question with a Y for Yes, and N for No." << endl;

		// Question 1
		cout << "Is red your favorite saber color? ";
		cin >> ans;
			if (ans == 'Y')
		 	s1 = -5;
		 
		 	else if (ans == 'N')
		 	s1 = +5;

		 	else
		 	s1 = 0;

		// Question 2
		cout << "Do you deal in absolutes? ";
		cin >> ans;
			if (ans == 'Y')
                 	s2 = -5;

                 	else if (ans == 'N')
                 	s2 = +5;

                 	else
                 	s2 = 0;

		// Question 3
		cout << "Are you selfless? ";
		cin >> ans;
	         	if (ans == 'Y')
                 	s3 = +5;

                 	else if (ans == 'N')
                 	s3 = -5;

                 	else
                 	s3 = 0;  

		// Question 4
		cout << "What about the droid attact on the Wookies? ";
		cin >> ans;
			if (ans == 'Y')
			s4 = +5;

			else if (ans == 'N')
			s4 = -5;

			else
			s4 = 0;

		// Question 5
		cout << "Did you ever hear the tragedy of Darth Plagueis The Wise? ";
		cin >> ans;
			if (ans == 'Y')
			s5 = -5;
	
			else if (ans == 'N')
			s5 = +5;

			else
			s5 = 0;

		cout << " " << endl;
		cout << "I thought not. It's not a story the Jedi would tell you. It's a Sith legend. Darth Plagueis was a Dark Lord of the Sith, so powerful and so wise he could use the Force to influence the midichlorians to create life... He had such a knowledge of the dark side that he could even keep the ones he cared about from dying. The dark side of the Force is a pathway to many abilities some consider to be unnatural. He became so powerful... the only thing he was afraid of was losing his power, which eventually, of course, he did. Unfortunately, he taught his apprentice everything he knew, then his apprentice killed him in his sleep. It's ironic he could save others from death, but not himself." << endl;
		cout << " " << endl;
		
		// Question 6
		cout << "Is it possible to learn this power? ";
		cin >> ans;
	 		if (ans == 'Y')
			s6 = -5;

			else if (ans == 'N')
			s6 = +5;

			else
			s6 = 0; 
		
		// Question 7
		cout << "Are you The Senate? ";
		cin >> ans;
			if (ans == 'Y')
			s7 = -5;
		
			else if (ans == 'N')
			s7 = +5;

			else
			s7 = 0;

		// SCORE CALCULATION
		score= 0 + s1 + s2 + s3 + s4 + s5 + s6 + s7;
			if (score > 0)
			cout << "Congratulations. You are on this council, but we do not grant you the rank of Master." << endl;
		
			else	
			cout << "Only a Sith deals in absolutes. I will do what I must." << endl;
		}

	// INVALID ENTRIES
	else
            {
	    cout << "Invalid Entry, Goodbye!" << endl;
            return -1;
            } 
}

