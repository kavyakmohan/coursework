/* Kavya Mohan 2001362917 CS 135 Section 1020 Assignment05
 * Description: While and For Loops Assignment
 * Input: Numbers 1-10, a single word and number of times to repeat, a base number, and exponent
 * Output: A guessing game, a word will be repeated, and a power */

// CS 135 Assignment 5: Loops
#include <iostream>
#include <string>
#include <time.h>    //For Time
#include <stdlib.h>  //For srand
//Not allowed to use cmath or any absolute value function.
using namespace std;

void guessAnumber(int s){
    int random = rand() % s + 1; //random number in range [1 to s]
    int guess;
    bool done = false;
    cout << "Guess a Number between 1 and "<< s << endl;
    //Your Code Here
   
    cin >> guess; //prompts user to input guess
    	
    //loop if guess is incorrect
    while (guess != random){
	cout << "The force is not with you. Try Again!" << endl; //prints error message
 	cin >> guess; //prompts user for another guess
    }
	
    //loop if guess is correct
    while (guess == random){
	cout << "The force is strong with this one! You win!" << endl; //prints success message
	break; //terminates loop
    }
}

void repeatWord(){
    int repeats;
    string word;
    cout << "Enter a Single word to repeat: ";
    cin >> word;
    cout << "\nEnter How many times  to repeat: ";
    cin >> repeats;
    /* Your Code Here
     * loop to repeat word
     * initial statement: i = 0
     * loop expression: i < # of repeats
     * update expression: i++ (add 1 to i each time loop is repeated) */
    
    for (int i = 0; i < repeats; i++){
	cout << word << endl; //print word each time i < repeats until loops terminates
	}

    cout << "Done repeating word " << repeats << " times!" << endl; //prints message
}

void mypow(){ //Note, instead of return 0 or 1, simply type return.
    //Use floats! You must use a loop!
    float base;
    float exponent;
    float answer;
    cout << "My Power Function!\n";
    //Your Code Here 
    float exponentp; //variable to store absolute value of user input exponent
    float basep; //variable to store absolute value of user input base

    cout << "Enter base number: ";
    cin >> base; //prompts user to input base

    cout << "Enter exponent: ";
    cin >> exponent; //prompts user to input exponent

    cout << "The Answer is: ";
    answer = 1; //initalizes answer to 1

    if (exponent < 0) //if exponent is negative
	exponentp = exponent * -1; //turns user input exponent positive and stores to new variable

    else //if exponent is positive
	exponentp = exponent; //user input exponent is initialized

    if (base < 0) //if base is negative
	basep = base * -1; //turns user input base positive and stores to new variable

    else //if base is positive
	basep = base; //user input base is initialized

    for (int i = 0; i < exponentp; i++) //loops repeats until i is less than absolute value of exponent
        answer = answer * basep; //answer is updated each time as it is multiplied by the absolute value of the base

    if (exponent < 0 && base > 0) //positive base, negative exponent
	cout << "1/" << answer << endl;

    else if (exponent < 0 && base < 0 && (int) exponent % 2 != 0) //negative base, odd negative exponent
	cout << "-1/" << answer << endl;

    else if (exponent < 0 && base < 0 && (int) exponent % 2 == 0) //negative base, even negative exponent
	cout << "1/" << answer << endl;

    else if (exponent > 0 && base < 0 && (int) exponent % 2 != 0) //negative base, odd positive exponent
	cout << "-" << answer << endl;

    else //all other cases
    cout << answer <<endl; 
}

//Don't touch Main
int main(int argc, char *argv[]){
    srand(time(NULL));
    guessAnumber(10);
    repeatWord();
    mypow();
    cout << "Thanks for playing, Goodbye!" << endl;
    return 0;
}
