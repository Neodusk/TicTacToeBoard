/**
 * Unit Tests for TicTacToeBoard
**/

#include <gtest/gtest.h>
#include "TicTacToeBoard.h"
 
class TicTacToeBoardTest : public ::testing::Test
{
	protected:
		TicTacToeBoardTest(){} //constructor runs before each test
		virtual ~TicTacToeBoardTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor) 
};

/* EXAMPLE TEST FORMAT
TEST(TicTacToeBoardTest, unitTestName)
{
	ASSERT_TRUE(true);
}
*/


TEST(TicTacToeBoardTest, placePieceNonExistantColumn)
{
	int row = 0;
	int column = 4;
	int columnNeg = 4;
	TicTacToeBoard board;
	ASSERT_TRUE(board.placePiece(row, column) == Invalid);
	ASSERT_TRUE(board.placePiece(row, columnNeg) == Invalid);
}

TEST(TicTacToeBoardTest, placePieceNonExistantRow)
{
	int row = 4;
	int rowNeg = -4;
	int column = 0;
	TicTacToeBoard board;
	ASSERT_TRUE(board.placePiece(row, column) == Invalid);
	ASSERT_TRUE(board.placePiece(rowNeg, column) == Invalid);

}

TEST(TicTacToeBoardTest, placePieceOverOtherPiece)
{
	int row = 0;
	int column = 0;
	TicTacToeBoard board;
	board.placePiece(row, column);
	ASSERT_FALSE(board.placePiece(row, column) == O);
}

TEST(TicTacToeBoardTest, getBlankPiece)
{
	int row = 0;
	int column = 0;
	TicTacToeBoard board;
	ASSERT_TRUE(board.getPiece(row, column) == Blank);
}

TEST(TicTacToeBoardTest, checkColumnWinner)
{
	TicTacToeBoard board;
	board.placePiece(0,0); // x
	board.placePiece(1,0);
	board.placePiece(0,1); // x
	board.placePiece(2,1);
	board.placePiece(0,2); // x
	ASSERT_TRUE(board.getWinner() == X);
}

TEST(TicTacToeBoardTest, checkRowWinner)
{
	TicTacToeBoard board;
	board.placePiece(1,0);  // x
	board.placePiece(2,0);  
	board.placePiece(1,1);  // x
	board.placePiece(2,1);
	board.placePiece(1,2);  // x
	ASSERT_TRUE(board.getWinner() != O);
}



TEST(TicTacToeBoardTest, checkDiagonalWinner)
{
	TicTacToeBoard board;
	board.placePiece(0,0); // x
	board.placePiece(0,1); 
	board.placePiece(1,1); // x
	board.placePiece(0,2); 
	board.placePiece(2,2); // x
	ASSERT_TRUE(board.getWinner() == X);
}

TEST(TicTacToeBoardTest, checkFullBoardWinner)
{
	TicTacToeBoard board;
	for (int i = 0; i < BOARDSIZE; i++) {
		for (int j = 0; j < BOARDSIZE; j++) {
			board.placePiece(i, j);
		}
	}
	ASSERT_TRUE(board.getWinner() == X);
}

TEST(TicTacToeBoardTest, checkFullBoardNoWinner)
{
	TicTacToeBoard board;
	board.placePiece(0, 2); // x
	board.placePiece(0, 0);
	board.placePiece(1, 0); // x
	board.placePiece(0, 1);
	board.placePiece(1, 1); // x
	board.placePiece(1, 2);
	board.placePiece(2, 1); // x
	board.placePiece(2, 1);
	
	ASSERT_TRUE(board.getWinner() == Blank);
}