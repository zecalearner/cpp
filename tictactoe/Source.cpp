#include "TicTacToe.h"

int main(void)
{
	do
	{
		TicTacToe game;
		game.PlayGame();
		std::cout << "STARTING NEW GAME, GOOD LUCK! \n";
	} while (true);
	
	return 0;
}