#pragma once
#include <vector>
#include "Block.h"

class Grid
{
public:
	std::vector<std::vector<Block>> GridVector;
	int  number_of_mines;
	Grid(int row, int column);

	void flag(char row, char column);

	void reveal(char row, char colum);

	void showgrid();


};

