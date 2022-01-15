#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "sixteen.h"
using namespace std;

//DEFAULT CONSTRUCTOR initializes board to 0 except for [0][0] and [2][0]
sixteen::sixteen()
{
  for (int i = 0; i < SIZE; i++)
  {
    for (int j = 0; j < SIZE; j++)
    {
      if (i == 0 && j == 0 || i == 2 && j == 0)
      {
        board[i][j] = 2;
      }

      else    
        board[i][j] = 0;
    }  
  }
/*
  //CHECK FOR LOSS
  board[0][0] = 2;
  board[0][1] = 4;
  board[0][2] = 2;

  board[1][0] = 4;
  board[1][1] = 2;
  board[1][2] = 4;

  board[2][0] = 2;
  board[2][1] = 4;
  board[2][2] = 2;
*/
}

/*****************************
 NAME: moveLeft()
 PARAMETERS: none
 RETURN TYPE: void
 DESCRIPTION: slides all the tiles on each row to the left
*****************************/
void sixteen::moveLeft()
{ 
  bool empty = false;
  int y, x;

  //SLIDING TILES TO THE LEFT
  for (int i = 0; i < SIZE; i++) //repeats for each row
  {
    if (board[i][0] == 0 && board[i][1] == 0 && board[i][2] != 0) //if first two values in row are zero
    { 
      board[i][0] = board[i][2]; //move board[i][2] to board[i][0]
      board[i][2] = 0;
    }

    for (int j = 0; j < SIZE - 1; j++) //looping through columns
    {
      if (board[i][j] == 0 && board[i][j+1] != 0) //if board[i][j] is empty
      {
        board[i][j] = board[i][j+1]; //swap
        board[i][j+1] = 0;
      } 
    
      for (int k = 0; k < SIZE - 1; k++)
      {
        if (board[i][k] == board[i][k+1] && board[i][k] != 0 && board[i][k+1] != 0) //combines terms if necessary
        {
          board[i][k] = board[i][k] + board[i][k+1];
          board[i][k+1] = 0;
        }
      } //end of combination loop
    } //end of sliding loop
  } //end of column and loop moves on to the next row

  //SPAWN 2 INTO RANDOM EMPTY SQUARE
  while (empty == false)
  {
    y = rand() % 3;
    x = rand() % 3;
    
    if (board[y][x] == 0)
      empty = true;
  }
  board[y][x] = 2; 
}

/*****************************
 NAME: moveRight()
 PARAMETERS: none
 RETURN TYPE: void
 DESCRIPTION: slides all the tiles on each row to the right
*****************************/
void sixteen::moveRight()
{ 
  bool empty = false;
  int y, x;
  for (int i = 0; i < SIZE; i++) //repeats for each row
  {
    if (board[i][1] == 0 && board[i][2] == 0 && board[i][0] != 0)
    { 
      board[i][2] = board[i][0];
      board[i][0] = 0;
    }

    for (int j = 2; j > 0; j--)
    { 
      if (board[i][j] == 0 && board[i][j-1] != 0)
      { 
        board[i][j] = board[i][j-1];
        board[i][j-1] = 0;
      }

      for (int k = 2; k > 0; k--)
      {
        if (board[i][k] == board[i][k-1] && board[i][k] != 0 && board[i][k-1] != 0)
        {
          board[i][k] = board[i][k] + board[i][k-1];
          board[i][k-1] = 0;
        }
      }
    }
  }
//SPAWN RANDOM 2
  while (empty == false)
  {
    y = rand() % 3;
    x = rand() % 3;
    
    if (board[y][x] == 0)
      empty = true;
  }
  board[y][x] = 2; 
}

/*****************************
 NAME: moveUp()
 PARAMETERS: none
 RETURN TYPE: void
 DESCRIPTION: slides all the tiles on each row to the top
*****************************/
void sixteen::moveUp()
{
  bool empty = false;
  int y, x;

  for (int j = 0; j < SIZE; j++)
  {
    if (board[0][j] == 0 && board[1][j] == 0 && board[2][j] != 0)
    {
      board[0][j] = board[2][j];
      board[2][j] = 0;
    }

    for (int i = 0; i < SIZE - 1; i++)
    {
      if (board[i][j] == 0 && board[i+1][j] != 0)
      {
        board[i][j] = board[i+1][j];
        board[i+1][j] = 0;
      }

      for (int k = 0; k < SIZE - 1; k++)
      {
        if (board[k][j] == board[k+1][j] && board[k][j] != 0 && board[k+1][j] != 0)
        {
          board[k][j] = board[k][j] + board[k+1][j];
          board[k+1][j] = 0;
        }
      }
    }
  }

  while (empty == false)
  {
    y = rand() % 3;
    x = rand() % 3;
    
    if (board[y][x] == 0)
      empty = true;
  }
  board[y][x] = 2; 
}

/*****************************
 NAME: moveDown()
 PARAMETERS: none
 RETURN TYPE: void
 DESCRIPTION: slides all the tiles on each row to the bottom
*****************************/
void sixteen::moveDown()
{
  bool empty = false;
  int y, x;

  for (int j = 0; j < SIZE; j++)
  {
    if (board[1][j] == 0 && board[2][j] == 0 && board[0][j] != 0)
    { 
      board[2][j] = board[0][j];
      board[0][j] = 0;
    }

    for (int i = 2; i > 0; i--)
    {
      if (board[i][j] == 0 && board[i-1][j] != 0)
      { 
        board[i][j] = board[i-1][j];
        board[i-1][j] = 0;
      }

      for (int k = 2; k > 0; k--)
      {
        if (board[k][j] == board[k-1][j] && board[k][j] != 0 && board[k-1][j] != 0)
        { 
          board[k][j] = board[k][j] + board[k-1][j];
          board[k-1][j] = 0;
        }
      }
    }
  }
  while (empty == false)
  {
    y = rand() % SIZE;
    x = rand() % SIZE;
    
    if (board[y][x] == 0)
      empty = true;
  }
  board[y][x] = 2; 
}

/*****************************************
 FUNCTION NAME: over() const
 PARAMETERS: none
 RETURN TYPE: int
 DESCRIPTION: loops through board array to check if game has been lost, won, or if in progress
*****************************************/
int sixteen::over() const
{
  int emptySquares = 0;

  for (int i = 0; i < SIZE; i++)
  {
    for (int j = 0; j < SIZE; j++)
    {
      if (board[i][j] == WIN)
        return 1;

        else if (board[i][j] == 0)
          emptySquares++;
    }
  }
 
  if (emptySquares > 0)
    return 0;
  else
    return -1;
}

/******************************************
 FUNCTION NAME: output() const
 PARAMETERS: none
 RETURN TYPE: void
 DESCRIPTION: outputs board array to terminal
*******************************************/
void sixteen::output() const
{
  //use right and setw
  for (int i = 0; i < SIZE; i++)
  {
    for (int j = 0; j < SIZE; j++)
    {
      if (board[i][j] == 0)
      { 
        cout << setw(3) << right << "-";
      }

      else
      {
        cout << setw(3) << right << board[i][j];
      }
    }
    
    cout << endl;
  }
  cout << endl;
} 
