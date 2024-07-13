#pragma once
#include <iostream>
#include <string>

#define MAX_GRID_SIZE	(10U)
#define DIAGONAL_LB		(int)(TicTacToe::GetGridSize()) // left below
#define DIAGONAL_LA		-((int)TicTacToe::GetGridSize() + (int)2) // left above
#define DIAGONAL_RB		(int)(TicTacToe::GetGridSize() + 2U) // right below
#define DIAGONAL_RA		-((int)TicTacToe::GetGridSize()) // right above



class TicTacToe
{
private:
	unsigned int grid_size = 3; // 3 default tic tac toe game
	unsigned int total_moves = 0;
	std::string board;
public:
	// Constructor
	TicTacToe();
	// Start the game
	void PlayGame();
	// Winner found, congrats the player
	void WinnerFound(char PlayerChar);
	// Finds if there is a winner
	bool FindWinner();
	// Prints the current game in the console
	void PrintGrid()
	{
		std::cout << board;
	}
	// Sets the grid size
	void SetGridSize(unsigned int newsize)
	{
		grid_size = newsize;
	}
	// Gets the grid size
	unsigned int GetGridSize()
	{
		return grid_size;
	}
	// Increments total movements from both player
	void AddMove() 
	{
		++total_moves;
	}
	unsigned int GetMoves()
	{
		return total_moves;
	}
	void ResetMove()
	{
		total_moves = 0;
	}
	void ResetGrid()
	{
		for (int i = 0; i < grid_size; i++)
		{
			for (int n = 0; n < grid_size; n++)
			{
				board.append("+");
			}
			board.append("\n");
		}
	}
	// Deconstructor (not sure if needed)
	//~TicTacToe();

};

