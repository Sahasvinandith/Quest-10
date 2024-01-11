#include "Grid.h"

#include "Block.h"
#include <iostream>
#include <vector>
#include <cctype>
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
	//int mine_added = 0;

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

int Grid::char_to_int(char mychar) {
	char upperCaseChar = std::toupper(mychar);
	int ascii = upperCaseChar;
	return (ascii - 65);
}

void Grid::flag(char chrow, char chcolumn)
{
	int row = this->char_to_int(chrow);
	int column = this->char_to_int(chcolumn);
	this->GridVector[row][column].setchar('f');
    if (this->GridVector[row][column].bomb)
    {
		this->GridVector[row][column].bomb_found = 1;
		(this->bomb_found)++;
		(this->flags_success)++;

    }
	this->showgrid();
}

void Grid::showfinal() {
	if (this->rows == 10) {
		cout << "\t  A B C D E F G H I J" << endl;
	}
	else if (this->rows == 15) {
		cout << " \t  A B C D E F G H I J K L M N O" << endl;
	}
	else {
		cout << " \t  A B C D E F G H I J K L M N O P Q R S T" << endl;
	}
	char characterFromAscii;
	for (int i = 0; i < rows; i++) {
		characterFromAscii = static_cast<char>(i + 65);
		std::cout << "\t" << characterFromAscii << " ";
		for (int j = 0; j < rows; j++) {
			if (this->GridVector[i][j].block == 'f' && !(this->GridVector[i][j].bomb)) {
				std::cout << "\033[1;31mf\033[0m" <<  " ";
			}
			else if (this->GridVector[i][j].block != 'f' && (this->GridVector[i][j].bomb)) {
				std::cout << "\033[1;31mb\033[0m" << " ";
			}
			else {
				std::cout << this->GridVector[i][j].block << " ";
			}
			
		}
		cout << endl;
	}
	cout << "\n\tMines found : " << this->bomb_found << endl;
	cout << "\n\tmines left : " << (this->number_of_mines) - (this->bomb_found)<<endl;
	system("pause");
}

void Grid::showgrid() {
	cout << "\n\n\tFlags left: " << ((this->number_of_mines) - (this->bomb_found))<<endl<<endl;
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
		cout << "\nCommands\n\n";
		cout << "F - place a flag on the location\nR - reveal the uncovered location\n\n";
		char inrow, incolumn, command,row,column;
		cout << "Enter three letters in <row letter> <column letter> <command>: ";
		cin >> inrow >> incolumn >> command;
		row = std::toupper(inrow);
		column = std::toupper(incolumn);
		if (command != 'r' && command != 'f' && command != 'R' && command != 'F')
		{
			cout << "Invalid command! Try again!!\n";
			system("pause");
		}
		if (this->char_to_int(row) > this->GridVector.size() && this->char_to_int(column) > this->GridVector.size()) {
			cout << "Invalid command! Try again!!\n";
			system("pause");
		}
		else {
			if (command == 'f' || command == 'F') {
				this->flag(row, column);
				flag_sets++;
			}
			else {
				if (this->reveal(row, column)==1) {
					//output for revealing a bomb
					cout << "Mission failed!!! You stepped on a bomb\n"<<endl;
					this->showfinal();
					return -1;
				}
			}
			
		}

	}
	if (this->bomb_found == this->number_of_mines) {
		return 0;
		showfinal();
	}
	else {
	//output for putting all the flags but incorrectly
		cout << "Mission failed!! You did not find all the mines...\n";
		this->showfinal();
		return -1;
	}
	

}

int Grid::countNeighboringBombs(int row, int column) {
    	int count = 0;
		int prev_colm_digit=column-1;
		int next_colm_digit=column+1;
		int prev_row_digit=row-1;
		int next_row_digit=row+1;
		if (column == 0) {
			prev_colm_digit = 0;
			next_colm_digit = 1;
			prev_row_digit = 0;
			next_row_digit = 1;

		}
		if (column == (this->GridVector[0].size() - 1)) {
			prev_colm_digit = column - 1;
			next_colm_digit = column;
		}
		if (row == 0) {
			prev_row_digit = 0;
			next_row_digit = 1;
		}
		if (row == (this->GridVector.size() - 1)) {
			prev_row_digit = column - 1;
			next_row_digit = column;
		}
		for (int i = prev_row_digit; i <= next_row_digit; ++i) {
			for (int j = prev_colm_digit; j <= next_colm_digit; ++j) {
				// Skip the center cell
				if (i == 0 && j == 0) {
					continue;
				}

				// Check if the calculated cell is a valid cell in the grid and contains a bomb
				if (this->GridVector[i][j].bomb && this->GridVector[i][j].bomb_found==0) {
					++count;
				}
			}
		}
		
		return count;
}

bool Grid::isValidCell(int row, int column) {
    return row >= 0 && row < this->GridVector.size() && column >= 0 && column < GridVector[row].size();
}


	
bool Grid::reveal(char chrow, char chcolumn)
		
{
	int row = this->char_to_int(chrow);
	int column = this->char_to_int(chcolumn);
		
		
		char GridChar = this->GridVector[row][column].block;
		if (this->GridVector[row][column].bomb) {
					
				return 1; //reveal return 1 means player revealed an bomb
		}
		else{
			int numBombs = countNeighboringBombs(row, column);
			if (numBombs == 0) {
            // No neighboring bombs - reveal a dot
            	GridVector[row][column].block = '.';
        	} else {
            	// Reveal the number of neighboring bombs
            	GridVector[row][column].block = static_cast<char>(numBombs + '0');
        	}
		}
		
	cout << "\n**********************************************************************\n\nRevealed: " << chrow << chcolumn << endl;
	this->showgrid();
}


