#include "TicTacToeBoard.h"
#include <iostream>
/**
 * Class for representing a 3x3 Tic-Tac-Toe game board, using the Piece enum
 * to represent the spaces on the board.
**/

//Constructor sets an empty board and specifies it is X's turn first
TicTacToeBoard::TicTacToeBoard()
{
  turn = X;
  for(int i=0; i<BOARDSIZE; i++)
    for(int j=0; j<BOARDSIZE; j++)
      board[i][j] = Blank;
}

/**
 * Switches turn member variable to represent whether it's X's or O's turn
 * and returns whose turn it is
**/
Piece TicTacToeBoard::toggleTurn()
{
  if (turn == O) {
    turn = X;
  } else if (turn == X) {
    turn = O;
  }
  return turn;
}

/**
 * Places the piece of the current turn on the board, returns what
 * piece is placed, and toggles which Piece's turn it is. placePiece does 
 * NOT allow to place a piece in a location where there is already a piece.
 * In that case, placePiece just returns what is already at that location. 
 * Out of bounds coordinates return the Piece Invalid value. When the game
 * is over, no more pieces can be placed so attempting to place a piece
 * should neither change the board nor change whose turn it is.
**/ 
Piece TicTacToeBoard::placePiece(int row, int column)
{
  // get the piece in the location specified
  Piece piece = getPiece(row, column);
  if (piece == X || piece == O) {
    return piece;
  } else if (piece == Blank) {
    board[row][column] = turn;
    toggleTurn();
    return board[row][column];
  } else if (piece == Invalid) {
    return  Invalid;
  }
  // if piece can be placed
  if (getWinner() != Invalid) {
    return getWinner();
  }
  return piece;
}

/**
 * Returns what piece is at the provided coordinates, or Blank if there
 * are no pieces there, or Invalid if the coordinates are out of bounds
**/
Piece TicTacToeBoard::getPiece(int row, int column)
{
   // if spot not on the board
  if (row  > BOARDSIZE-1 || row < 0 || column > BOARDSIZE-1 || column < 0 ) {
    return Invalid;
  } 
  return board[row][column];
}

/**
 * Returns which Piece has won, if there is a winner, Invalid if the game
 * is not over, or Blank if the board is filled and no one has won.
**/
Piece TicTacToeBoard::getWinner()
{
  Piece firstPiece = getPiece(0, 0);
  bool blank = false;
  // check first column
  for(int i = 1; i < BOARDSIZE; i++) {
    Piece newPiece = getPiece(i, 0);
    if (firstPiece == newPiece) {
      firstPiece = newPiece;
      if (i == BOARDSIZE - 1) {
        return firstPiece;
      }
    } else {
      if (firstPiece == Blank) {
        blank = true;
      }
      break;
    }
  }
  // check first row
  for(int i = 1; i < BOARDSIZE; i++) {
    Piece newPiece = getPiece(0, i);
    if (firstPiece == newPiece) {
      firstPiece = newPiece;
      if (i == BOARDSIZE - 1) {
        return firstPiece;
      }
    } else {
      if (firstPiece == Blank) {
        blank = true;
      }
      break;
    }
  }
// ------------------------------------------------
  firstPiece = getPiece(0, 1);
  // check second column
  for(int i = 1; i < BOARDSIZE; i++) {
    Piece newPiece = getPiece(i, 1);
    if (firstPiece == newPiece) {
      firstPiece = newPiece;
      if (i == BOARDSIZE - 1) {
        return firstPiece;
      }
    } else {
      if (firstPiece == Blank) {
        blank = true;
      }
      break;
    }
  }

  firstPiece = getPiece(1, 0);
  // check second row
  for(int i = 1; i < BOARDSIZE; i++) {
    Piece newPiece = getPiece(1, i);
    if (firstPiece == newPiece) {
      firstPiece = newPiece;
      if (i == BOARDSIZE - 1) {
        return firstPiece;
      }
      if (firstPiece == Blank) {
        blank = true;
      }
    } else {
       if (firstPiece == Blank) {
        blank = true;
      }
      break;
    }
  }

//-----------------------------------------------------------------
  firstPiece = getPiece(2, 0);
  // check third row
  for(int i = 1; i < BOARDSIZE; i++) {
    Piece newPiece = getPiece(2, i);
    if (firstPiece == newPiece) {
      firstPiece = newPiece;
      if (i == BOARDSIZE - 1) {
        return firstPiece;
      }
    } else {
      if (firstPiece == Blank) {
        blank = true;
      }
      break;
    }
  }
  firstPiece = getPiece(2, 0);
  // check third column
  for(int i = 1; i < BOARDSIZE; i++) {
    Piece newPiece = getPiece(2, i);
    if (firstPiece == newPiece) {
      firstPiece = newPiece;
      if (i == BOARDSIZE - 1) {
        return firstPiece;
      }
    } else {
      if (firstPiece == Blank) {
        blank = true;
      }
      break;
    }
  }
//--------------------------------------------------------------------
  // check diagonals
  if (getPiece(0,0) == getPiece(1,1) && getPiece(1,1) == getPiece(2,2)) {

    return getPiece(0,0);
  }
  if (getPiece(2,0) == getPiece(1,1) && getPiece(1,1) == getPiece(0,2)) {
    return getPiece(2,0);
  }
  
  if (blank) {
    return Blank;
  }
  return Invalid;
}
