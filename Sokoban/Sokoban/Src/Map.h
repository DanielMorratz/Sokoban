#pragma once
#include "game.h"

class Map 
{
public:
	Map();
	~Map();

	void LoadMap(int[20][25]);
	void DrawMap();
	int lvl1[20][25];
	int map[20][25];

private:

	SDL_Rect src, dest;
	SDL_Texture* wall;
	SDL_Texture* floor;
	SDL_Texture* black_floor;

	

};