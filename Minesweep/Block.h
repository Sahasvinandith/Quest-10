#pragma once
#include <string>



class Block
{
public:
	char block;
	bool bomb;
	bool bomb_found=0;


	Block(char block_property);
	void setchar(char ch);
	void setbomb();
};

