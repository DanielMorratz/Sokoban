#pragma once
#include "game.h"
class Foreground
{
public:  	
	Foreground();
	~Foreground();
	void LoadMap(int arr[20][25]);
	void DrawMap();
	int lvl1_blocks[20][25];
	int map[20][25];

private:

	SDL_Rect src, dest;
	SDL_Texture* block;

	

	
};