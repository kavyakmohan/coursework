/* Kavya Mohan 2001362917 CS135 Section 1020 Assignment08
 * Description: Battle Royale Game
 * Input: Enter key or other keys to end game
 * Output: Grid displaying the game and storm as it grows */

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

//Important Constants
const int GRIDX = 50;
const int GRIDY = 14;
const int PLAYERCNT = 25; //Number of Players Allowed
const int ROUNDCNT = 100; //Maximum Number of Rounds to Play
const bool ALIVE = true; //Nickname for true and false
const bool DEAD = false;
const bool SAVELASTROUND = true; //save the last round to true so it doesn't get autoerased.
const int INITSTORMSIZE = GRIDX; //We will make the storm start out on a diameter of size of X grid.

//Creating Coordinates (An Enum Would be better)
const int X = 0;
const int Y = 1;
const int COORDINATE = 2; 

int main(){
	//SEED TO GENERATE RANDOM NUMBERS
	srand(time(NULL));

	//ARRAYS
	char GRID[GRIDY][GRIDX];		 //Grid Array
	int PLAYERPOS[PLAYERCNT][COORDINATE];	//stores players' positions
	bool PLAYERSTATUS[PLAYERCNT];		//stores whether players are alive

	//VARIABLES
	int stormX; // Storm center's X Coordinate
	int stormY; // Storm center's Y Coordinate
	int safezone = INITSTORMSIZE;
	int playerX; // Player's X Coordinate
	int playerY; // Player's Y Coordinate
	char lastDead; // Stores last survivor in case of a tie
	int survivorcnt = PLAYERCNT; //# of players alive

	//CENTER OF STORM
	stormX = rand() % GRIDX + 1;
	stormY = rand() % GRIDY + 1;
	cout << "Center: (" << stormX << " , " << stormY << ")" << endl;

	cout << "Mohan Battle Royale!" << endl;

	//Initialize GRID with ' ' characters
	for (int i = 0; i < GRIDY; i++){
		for (int j = 0; j < GRIDX; j++){
			GRID[i][j] = ' ';
		}
	}			

	//Generate player spawn points
	for (int i = 0; i < PLAYERCNT; i++){
		//generate random coordinates
		playerX = rand() % GRIDX;
		playerY = rand() % GRIDY;
		//initialize coordinates to PLAYERPOS array
		PLAYERPOS[i][X] = playerX;
		PLAYERPOS[i][Y] = playerY;
		//print out players on grid
		GRID[playerY][playerX] = (char)('A' + i);
	}

	//Initialize player status to ALIVE
	for (int i = 0; i < PLAYERCNT; i++){
		PLAYERSTATUS[i] = ALIVE;
	}

	//LOOP BASED OFF OF ROUND		
	for (int round = 0; round < ROUNDCNT; round++){

		//UPDATE STORM AND SAFEZONE
		for (int i = 0; i < GRIDY; i++){
			for (int j = 0; j < GRIDX; j++){
				if ( (stormX - j) > safezone || (j - stormX) > safezone || (stormY - i) > safezone || (i - stormY) > safezone){
					GRID[i][j] = 's'; //anything char outside of safezone is in storm and replaced w/ 's'
				}
			}
		}	

		//UPDATE PLAYERSTATUS
		for (int i = 0; i < PLAYERCNT; i++){
			if (PLAYERSTATUS[i] == ALIVE){
				if (GRID[PLAYERPOS[i][Y]][PLAYERPOS[i][X]] == 's'){ //player is dead if in the storm
					PLAYERSTATUS[i] = DEAD;
					survivorcnt--; //survivor count is decreased
				}	
				else{
					lastDead = (char)('A' + i); //store player in case of a tie
				}
			}
		}

		//PRINT UPDATED GRID
		for (int i = 0; i < GRIDY; i++){
			for (int j = 0; j < GRIDX; j++){
				cout << GRID[i][j];
			}
			cout << "\n";
		}
		
		//check # of survivors and print victory message
		//if there's a clear winner
		if (survivorcnt == 1){
			for (int i=0; i < PLAYERCNT; i++){
				if (PLAYERSTATUS[i] == ALIVE){ //loop to check who winner is
					cout << "Victory Royale!" << endl;
					cout << "Player \'" << (char)('A' + i) << "\' wins!" << endl;
					cout << "Game Over!" << endl;
					break;
				}
			}
			break; 
		}
	
		//if there's a tie
		if (survivorcnt == 0){
			cout << "Victory Royale!" << endl;
			cout << "Player \'" <<  lastDead << "\' nearly took the L, but won!" << endl;
			cout << "Game Over!" << endl;
			break;
		}

		//print out round number and prompt user to hit enter
		cout << "Round " << round + 1 << " Complete. Press Enter To Continue ";
		if(cin.get() != '\n'){ //Reads single character
			cout << "Error! Only Press Enter." << endl;
			return 0; //terminates game if wrong key is hit
		}

		//erase printed grid array
		for (int i = 0; i < GRIDY + 1; i++){ //grid x grid + linefeeds which are grid size
			cout << "\033[A\33[2K\r";
		}
		cout << flush;
		//End of Erase Printed Array

		//Reduce the safezone diameter
		safezone--;	
	}

return 0;
}
