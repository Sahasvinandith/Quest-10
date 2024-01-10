#include "Grid.h"

#include "Block.h"
#include <iostream>
#include <vector>
#include <random>

Grid::Grid(int row, int column) {
	
	if (row == 10) {
		this->number_of_mines = 12;
	}
	else if (row == 15) {
		this->number_of_mines = 18;

	}
	else {
		this->number_of_mines = 24;
	}
	int mine_added = 0;

	for (int i = 0; i < row; ++i) {
		// Create a new row
		
		this->GridVector.push_back(std::vector<Block>());

		for (int j = 0; j < row; ++j) {
			// Add objects to the current row
			this->GridVector[i].push_back(Block('c'));
		}
	}

	for (int i = 0; i < this->number_of_mines; i++) {
		int mine_row = rand() % row+1;
		int mine_column = rand() % row + 1;

		this->GridVector[mine_row][mine_column].setchar('b');

	}




}

