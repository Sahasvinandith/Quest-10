#include "Block.h"

Block::Block(char Block_property) {
	if (Block_property == 'b') {
		this->bomb = true;
		this->block = 'b';
	}
	else {
		this->bomb = false;
		this->block = 'c';
	}
}

void Block::setchar(char ch) {
	this->block = ch;

}

