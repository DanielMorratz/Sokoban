#pragma once
#include "game.h"


class GameLogic
{
public:
	GameLogic();
	~GameLogic();
	bool ismovevalid(int, int, std::string, int[20][25], int[20][25]);
	bool islevelcomplete(int[20][25]);

private: 
};