#include <iostream>
#include "sixteen.h"
using namespace std;

//FUNCTION PROTOTYPES
void promptAction(char&, sixteen&);

int main()
{
  sixteen game;
  char userAction;
  int gameState = 0;

  game.output();
  
  while (gameState == 0)
  {
    promptAction(userAction, game);

    gameState = game.over();

    if (gameState == 1)
      cout << "You Won!" << endl;
    else if (gameState == -1)
      cout << "You Lost!" << endl;
  }

  return 0;
}

/************************************************
 FUNCTION NAME: promptAction
 PARAMETERS: char userAction, sixteen class object game
 RETURN TYPE: void
 DESCRIPTION: prompt user for a move and execute the move by calling class member functions
*************************************************/
void promptAction(char& userAction, sixteen& game)
{ 
  bool validMove = false;

  while (validMove == false)
  {
    cout << "Which direction would you like to move? (U, D, L, R): ";
    cin >> userAction;

    if (userAction == 'l' || userAction == 'L' || userAction == 'r' || userAction == 'R' || 
        userAction == 'u' || userAction == 'U' || userAction == 'd' || userAction == 'D')
      validMove = true;
    else
      cout << "Invalid move" << endl;
  }
  
  if (userAction == 'l' || userAction == 'L')
    game.moveLeft();

  else if (userAction == 'r' || userAction == 'R')
    game.moveRight();

  else if (userAction == 'u' || userAction == 'U')
    game.moveUp();

  else if (userAction == 'd' || userAction == 'D')
    game.moveDown();

  game.output();
}
  
