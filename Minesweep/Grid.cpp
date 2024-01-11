#include "Grid.h"

#include "Block.h"
#include <iostream>
#include <vector>
#include <random>
using namespace std;

Grid::Grid(int row, int column) {
	this->rows = row;
	this->columns = column;

	
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

	for (int i = 0; i <= this->number_of_mines; i++) {
		int mine_row = rand() % row;
		int mine_column = rand() % row;

		this->GridVector[mine_row][mine_column].setbomb();

	}


}

void Grid::showgrid() {
	if (this->rows == 10) {
		cout << "\t  A B C D E F G H I J"<<endl;
	}
	else if (this->rows == 15) {
		cout << " \t  A B C D E F G H I J K L M N O"<<endl;
	}
	else {
		cout << " \t  A B C D E F G H I J K L M N O P Q R S T" << endl;
	}
	char characterFromAscii;
	for (int i = 0; i < rows; i++) {
		characterFromAscii = static_cast<char>(i+65);
		std::cout << "\t" << characterFromAscii << " ";
		for (int j = 0; j < rows; j++) {
			std::cout << this->GridVector[i][j].block << " ";
		}
		cout << endl;
	}
}

int Grid::playGame() {
	int flag_sets=0;
	this->showgrid();

	while (flag_sets < this->number_of_mines) {
		cout << "Commands\n\n";
		cout << "F - place a flag on the location\nR - reveal the uncovered location\n\n";
		char row, column, command;
		cout << "Enter three letters in <row letter> <column letter> <command>: ";
		cin >> row >> column >> command;
		if (command != 'r' && command != 'f' && command != 'R' && command != 'F')
		{
			cout << "Invalid command! Try again!!\n";
			return -1;

		}
		else {
			/*if (command == 'f' || command == 'F') {
				this->flag(row, column);
			}
			else {
				this->reveal(row, column);
			}*/
			cout << "Exiting!!"<<endl;
			system("pause");
			return -1;


		}

	}

}

