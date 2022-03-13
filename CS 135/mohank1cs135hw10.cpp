/* Kavya Mohan 2001362917 CS135 Section 1020
 * Description: magic box puzzle game
 * Input: user inputs the direction to move the blank to solve the puzzle
 * Output: a puzzle that is solvable */

//Program made by Jorge Fonseca for CS135

#include<iostream> //cin / cout
#include<time.h>   //for seeding rand
#include<string>   //In case we use strings
#include<stdio.h>  //For getchar
#include<stdlib.h> //For Ssrand
#include<ios>	   //For <streamsize>
#include<limits>   //For numeric_limits

using namespace std; //So that we don't have to do std::cout instead of cout

//Defines
#define EMPTY -1 //To show where blank is
#define UP    0  //For directions allowed
#define DOWN  1
#define LEFT  2
#define RIGHT 3 
#define Y 1      //For Coordinates
#define X 0

//NO GLOBAL VARIABLES OR GLOBAL CONSTANTS ALLOWED. IF YOU USE ONE YOU WILL LOSE 50% OF THE GRADE

//Your Code Here: I have intentionally removed most of the parameters to the  function prototypes and function definitions.
//You must figure out what function needs what and add it back in.
//Similarly in the main function I have removed most of the actual parameters passed to the functions so add those back in.
//You are not allowed to declare any additional variables inside the main function. If you declare any you will lose 50% of the grade.
//Several Parts of the code are temporarily commented out. Uncomment them as you add back the correct code. You will notice compilation errors
//As you uncomment the code. This is normal as code is missing, once you add it in all will be fine.


//Function Prototypes:
void initRand();
void initGrid(int [][3], int GRIDX, int GRIDY);
bool argCheck(int argc, int expected);
int randomchoice();
void randomizeGrid(int grid[][3], int blank[], int GRIDX, int GRIDY, int iterations);
int getDifficulty(int argc, char *argv[]);
int getRoundCnt(int argc, char *argv[]);
void clearScreen();
void printGrid(int[][3], int GRIDX, int GRIDY);
bool checkWin(int[][3], int GRIDX, int GRIDY);
bool checkMaxRounds(int, int);
void getOptions(bool direction[], int blank[], int GRIDX, int GRIDY);
void printAvailableOptions(bool[]);
int readchoice(bool[]);
void swap(int&, int&);
void printRound(int);
void makemove(int, int[][3], int[], int, int);
void print(string const msg, int optnum = -1);

//I've commented out some code so it compiles slowly uncomment the code as you complete it.

//Main
int main(int argc, char *argv[]){ //DO NOT  DECLARE ANY ADDITIONAL VARIABLES!
	const int GRIDX = 3; //Dimensions of Puzzle
	const int GRIDY = 3;
	const int COORDINATE = 2;
	int grid[GRIDY][GRIDX]; //Grid Size
	int blank[COORDINATE] = {2,2};
	initRand(); //Initialize srand
	initGrid(grid, GRIDX, GRIDY); 	//Initialize Grid to 123,456, 78_
	argCheck(argc, 3); //Check that we have 3 arguments
	randomizeGrid(grid, blank, GRIDX, GRIDY, getDifficulty(argc, argv)); //Mix it up randomly n number of times (3rd argument)
//Uncomment this as you complete the assignment.
	for(int round = 0; round<getRoundCnt(argc, argv); round++){ //Loop a max number of rounds passed in 2nd argument
		clearScreen(); //Clear the screen to re-draw each time
		printGrid(grid, GRIDY, GRIDX); //print the status of puzzle
		if(checkWin(grid, GRIDY, GRIDX) /* Check if we reached limit */
		|| checkMaxRounds(round, getRoundCnt(argc, argv))) break; //or if we have solved Puzzle. In either case. Finish.
		//Attempt to Solve:
		bool direction[4] = {0,0,0,0}; //stores which moves are allowed
		getOptions(direction, blank, GRIDY, GRIDX); //Find out which moves are allowed
		printAvailableOptions(direction); //Print out our available moves
		printRound(round); //Prints Current Round
		makemove(readchoice(direction), grid, blank, GRIDY, GRIDX); //Read user input and make the move
	}
	print("Game Over!\n"); //Simple Print that prints game over.
	return 0;
}

//Don't forget to document your functions according to guidelines!
//Functions:
void initRand(){
	//seeds number for rand function
	//expects time
	//generates a rand number to assist randomchoice function
	srand(time(NULL)); //Comment out to always have the same random digits for debugging
}

void initGrid(int grid[][3], int GRIDX, int GRIDY){
	//initialize grid to correct order of values
	//expects grid dimensions for array
	//will print values 1-8 and blank in the grid
	int val = 49; //ascii value for 1
	//loop assigns values 1-8
	for (int i = 0; i < GRIDY; i++){
		for (int j = 0; j < GRIDX; j++){
			grid[i][j] = val;
			val++;
		} 
	}
	grid[2][2] = ' '; //assign blank to the last square in the last row
}

bool argCheck(int argc, int expected){
	//checks for correct number of command line arguments and displays an error message if not
	//checks for argc count and compares to expencted # of arguments
	if(argc != expected){
		print("Usage: Executable Rounds Difficulty\nExample: ./a.out 30 10\n");
		exit(EXIT_FAILURE);
		return 1;
	}
}

int randomchoice(bool direction[]){
	//randomly generates which direction blank should move
	//expects direction array to compare what move to make
	//returns the randvalue
	int randValue = 0;

	do {
		randValue = rand() % 4; //assigns a randvalue direction to move to
	} while (!direction[randValue]); 

	return randValue;
}

void randomizeGrid(int grid[][3], int blank[], int GRIDX, int GRIDY, int iterations){
	//mixes up the grid
	//expects coordinates of blank, dimensions of grid array, difficulty level
	//stores the shuffled grid
	bool direction[4] = {0,0,0,0};
	for (int i = 0; i < iterations; i++){
	//You Must call the following functions here:
	getOptions(direction, blank, GRIDY, GRIDX);
	makemove(randomchoice(direction), grid, blank, GRIDY, GRIDX);
	}
}

int getDifficulty(int argc, char *argv[]){
	//stores difficulty level for randomize function
	//expects the third command line argument
	//returns the command line argument as difficulty level
	return strtol(argv[2], NULL, 10);  //Number of Rounds to Play
}

int getRoundCnt(int argc, char *argv[]){
	//stores the round count for other functions
	//expects the second command line argument
	//returns the command line argument as round count
	return strtol(argv[1], NULL, 10);
}

void clearScreen(){
	//clears the screen between rounds
		cout << "\033c" << flush;
		cout << "The Magic Square!"<< endl;
}

void printGrid(int grid[][3], int GRIDX, int GRIDY){
	//Print Grid as a nice box
	//expects grid dimensions and grid
	//prints the grid to the terminal
	for (int i = 0; i <GRIDY; i++){
		for (int j = 0; j < GRIDX; j++){
			cout << (char)grid[i][j] << ' ';
		}
		cout << endl;
	}
}

bool checkWin(int grid[][3], int GRIDX, int GRIDY){
	//loop checks to see if the puzzle has been solved correctly
	//expects grid array and dimensions
	//returns true or false depending on whether puzzle is solved
	bool win = true;
	//Your Code Here
	int val = 49;
	for (int i = 0; i < GRIDY; i++){
		for (int j = 0; j < GRIDX; j++){
			if (grid[i][j] != val){
				if (i != 2 || j != 2){
					win = false;
					break;
				}
			}
			val = val + 1;
		}
		if (win == false){
			break;
		}
	}
	if(win){
		cout << " Congratulations! You Win!" << endl;
		cout << flush;
		return true;
	}
	else
		return false;
}

bool checkMaxRounds(int round, int roundcount){
	//checks if max rounds have been reached
	//expects round number and round count
	//returns true or false depending on whether round count has been met
	if(round >= roundcount-1){
		cout << " Round Limit Reached. You lose, General Kenobi!" << endl;
		cout << flush;
		return true;
	}
	else return false;
}

void getOptions(bool direction[], int blank[], int GRIDX, int GRIDY){
	//stores what moves are allowed 
	//expects direction, coordinates of blank, and grid dimensions
	direction[UP]       = blank[Y] < GRIDY-1;
	direction[DOWN]     = blank[Y] > 0;
	direction[LEFT]     = blank[X] < GRIDX-1;
	direction[RIGHT]    = blank[X] > 0;
}

void printAvailableOptions(bool direction[]){
	//prints what moves are available
	//requires bool direction[]
	//prints out the moves that are valid
	int optionTotal = 0;
	for (int i = 0; i < 4; i++){
		if (direction[i]){
			optionTotal++;
		}
	}
	print(string(" ")+"Available Options: ", optionTotal);
	if(direction[UP])    print("Down ")  ;
	if(direction[DOWN])  print("Up ")    ;
	if(direction[LEFT])  print("Right ") ;
	if(direction[RIGHT]) print("Left ")  ;
	
	cout << endl;
}

int readchoice(bool direction[]){
	//Only Accept Valid Choices. Ignore Invalid Choices.
	//reads user inputs and makes moves
	//expects user input and direction[]
	//assigns the user input to a move
	int choice;
	do{
		if (getchar() == '\033') { // if the first value is esc
    			getchar(); // skip the [
    			switch(getchar()) { // the real value
       				case 'B':
            				choice = UP;
           				break;
        			case 'A':
            				choice = DOWN;
			        	break;
				case 'C':
            				choice = LEFT;
            				break;
			        case 'D':
            				choice = RIGHT;
            				break;
    			}
		}
	}while(!direction[choice]);
	cin.ignore(numeric_limits<streamsize>::max(),'\n');//Will Discard useless input	
	return choice;
}

void swap(int &a, int &b){
	//swaps the blank and the value whose position it's moving into
	//expects the two values to be swaped (one of which is the blank)
	int temp;
	temp = a;
	a = b;
	b = temp;
}

void printRound(int round){
	//prints the round number
	//expects the current round number
	print("Round: ");
	print("\n", round);
}

//Your move General Kenobi!
void makemove(int choice, int grid[][3], int blank[], int GRIDY, int GRIDX){
	//actually makes the moves that the user inputs
	//expects the user's choice, grid and blank arrays, and grid dimensions as well as swap function
	//while making the move, swaps the blank and other value and outputs message to terminal
	int cX= blank[X];
	int cY= blank[Y];
	int nX= blank[X];
	int nY= blank[Y];

	switch(choice){
		case UP:    cout << "CHANGING DOWN ";  // because 0,0 is top left
			    nX = blank[X];
			    nY = blank[Y] + 1;
			    break;

		case DOWN:  cout << "CHANGING UP "; 
			    nX = blank[X];
			    nY = blank[Y] - 1;
			    break;
	
		case LEFT:  cout << "CHANGING RIGHT ";
			    nX = blank[X] + 1;
			    nY = blank[Y];
			    break;

		case RIGHT: cout << "CHANGING LEFT ";
			    nX = blank[X] - 1;
			    nY = blank[Y];
			    break;
	}
	//Your Code Here
	//Call swap function here
	
	swap(grid[nY][nX], grid[cY][cX]);

	blank[X] = nX;
	blank[Y] = nY;		
}

void print(string const msg, int optnum){
	//print function
	//expects const message and optnum
	if(optnum == -1)
		cout << msg << flush;
	else
		cout << optnum << msg << flush;
}

