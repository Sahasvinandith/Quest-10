#pragma once
#include <vector>
#include "Block.h"

class Grid
{
public:
	std::vector<std::vector<Block>> GridVector;
	int  number_of_mines;
	int flags_success;
	int rows;
	int columns;
	int bomb_found = 0;
	Grid(int row, int column);

	void flag(char row, char column);

	bool reveal(char row, char colum);
	int countNeighboringBombs(int row, int column);
	bool isValidCell(int row, int column);
	int char_to_int(char charachter);
	void showgrid();
	void showfinal();

	int playGame();


};

