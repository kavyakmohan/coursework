/* Kavya Mohan 2001362917 CS135 Section 1020 Assignment04
 * Description: ROT13 Cypher
 * Input: character inputted as a command line argument
 * Output: the message is displayed in all caps, each character is shifted 13 letters */

#include <iostream>

using namespace std;

char cipher(char letter){
    //CODE YOUR SWITCH STATEMENT HERE
#include <cctype>
letter = toupper(letter);    
switch(letter){
    case 'A':
    	letter = 'N';
    	break;

    case 'B':
    	letter = 'O';
    	break;

    case 'C':
    	letter = 'P';
    	break;

    case 'D':
    	letter = 'Q';
    	break;

    case 'E':
    	letter = 'R';
    	break;
    
    case 'F':
    	letter = 'S';
    	break;

    case 'G':
    	letter = 'T';
    	break;

    case 'H':
    	letter = 'U';
    	break;

    case 'I':
    	letter = 'V';
    	break;

    case 'J':
    	letter = 'W';
    	break;

    case 'K':
    	letter = 'X';
    	break;

    case 'L':
    	letter = 'Y';
    	break;

    case 'M':
    	letter = 'Z';
    	break;

    case 'N':
    	letter = 'A';
    	break;

    case 'O':
    	letter = 'B';
    	break;

    case 'P':
    	letter = 'C';
    	break;

    case 'Q':
    	letter = 'D';
    	break;

    case 'R':
    	letter = 'E';
    	break;

    case 'S':
    	letter = 'F';
    	break;

    case 'T':
    	letter = 'G';
    	break;

    case 'U':
    	letter = 'H';
    	break;

    case 'V':
    	letter = 'I';
    	break;

    case 'W':
    	letter = 'J';
    	break;

    case 'X':
    	letter = 'K';
    	break;

    case 'Y':
    	letter = 'L';
    	break;

    case 'Z':
    	letter = 'M';
    	break;

    default:
    ;
    }
    //END OF YOUR CODE. DON'T TOUCH ANYTHING ELSE
    return letter;
}

int main(int argc, char *argv[]) {
    // Made by ben, the sweater guy
    for (char **p = ++argv, *letter = *p;
        *  p && argc >= 2;
        *  letter? cout << cipher(*letter++) : (letter = *++p, cout << ' '))
        ;
    cout << endl;
    return 0;
}
