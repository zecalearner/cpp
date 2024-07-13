#include "TicTacToe.h"

TicTacToe::TicTacToe()
{
	std::cout << "Enter your desired grid size NxN (10 is the maximum)\n";
	unsigned int grid_size = 3;
	std::cin >> grid_size;
	if (grid_size > MAX_GRID_SIZE)
		grid_size = MAX_GRID_SIZE;
	TicTacToe::SetGridSize(grid_size);
	TicTacToe::ResetMove();
	TicTacToe::ResetGrid();
}

bool TicTacToe::FindWinner()
{
	bool winner_found = false;

	for (size_t i = 0; i < board.size() && !winner_found; i++)
	{
		if (board.at(i) == 'x' || board.at(i) == 'o')
		{
			char player_char = board.at(i);
			unsigned int grid_size = TicTacToe::GetGridSize();
			 // check for same row wins assuming you are at the middle point
			if (i % grid_size != 0 && i % grid_size + 1 != 0) // this covers first and last column
			{
				if (player_char == board.at(i - 1) && player_char == board.at(i + 1))
				{
					TicTacToe::WinnerFound(player_char);
					winner_found = true;
				}
			}
			//check for same column wins assuming you are at the middle point
			if (i > grid_size && i < (grid_size - 1) * (grid_size + 1)) // exclude first and last row
			{
				if (player_char == board.at(i - grid_size - 1) && player_char == board.at(i + grid_size + 1))
				{
					TicTacToe::WinnerFound(player_char);
					winner_found = true;
				}
			}
				// check for diagonal wins
			if (i % grid_size != 0 && i % grid_size + 1 != 0 && i > grid_size && i < (grid_size - 1) * (grid_size + 1)) // exclude first and last column, and first and last row
			{
				if (player_char == board.at(DIAGONAL_LB + i) && player_char == board.at(i + (int)DIAGONAL_RA)
					|| player_char == board.at(DIAGONAL_LA + i) && player_char == board.at(DIAGONAL_RB + i)
					)
				{
					TicTacToe::WinnerFound(player_char);
					winner_found = true;
				}
			}
				
		}
	}
	return winner_found;
}

void TicTacToe::WinnerFound(char PlayerChar)
{
	std::cout << "WINNER WINNER CHICKEN DINNER! Congratulations player " << PlayerChar << "\n";
	TicTacToe::PrintGrid();
}


void TicTacToe::PlayGame()
{
	while (true)
	{
		TicTacToe::PrintGrid();
		unsigned int row = MAX_GRID_SIZE + 1;
		unsigned int col = MAX_GRID_SIZE + 1;
		unsigned int grid_size = TicTacToe::GetGridSize();
		size_t position_in_string = 0;
		bool not_valid_play = true;
		while (not_valid_play)
		{
			std::cout << " Enter row then column where you want to play\n";
			while (row > grid_size)
			{
				std::cin >> row;
				if (row > grid_size)
				{
					std::cout << " Grid size is smaller than the input number, try again\n";
				}
			}
			while (col > grid_size)
			{
				std::cin >> col;
				if (col > grid_size)
				{
					std::cout << " Grid size is smaller than the input number, try again\n";
				}
			}
			position_in_string = col - 1 + (row - 1) * (grid_size + 1);
			if (board.at(position_in_string) == '+')
			{
				not_valid_play = false;
			}
			else
			{
				row = MAX_GRID_SIZE + 1;
				col = MAX_GRID_SIZE + 1;
			}
		}
		board.replace(position_in_string, 1, TicTacToe::GetMoves() % 2 == 0 ? "x" : "o");
		TicTacToe::AddMove();
		if (TicTacToe::FindWinner())
		{
			break;
		}
	}
}