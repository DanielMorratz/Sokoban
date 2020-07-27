#include "Map.h"
#include "TextureManager.h"
#include "ForegroundMap.h"


Map::Map()
{
	int lvl1[20][25] = {
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,3,3,3,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,3,0,3,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,3,3,3,0,3,0,0,3,0,0,0,0,0,3,3,4,4,0,0,0,0,0,0},
	{0,0,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,4,4,0,0,0,0,0,0},
	{0,0,0,0,0,0,3,0,0,0,3,0,3,0,0,3,3,4,4,0,0,0,0,0,0},
	{0,0,0,0,0,0,3,3,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
	};

	wall = TextureManager::LoadTexture("assets/wall.png");
	floor = TextureManager::LoadTexture("assets/floor.png");
	black_floor = TextureManager::LoadTexture("assets/black_floor.png");

	LoadMap(lvl1);

	src.x = src.y   =	 0;
	src.w = dest.w  =	32;
	src.h = dest.h  =	32;
	dest.x = dest.y =	 0;

}

void Map::LoadMap(int lvl1[20][25])
{
	for(int row = 0; row < 20; row++)
	{
		for (int coloumn = 0; coloumn < 25; coloumn++)
		{
			map[row][coloumn] = lvl1[row][coloumn];
			
		}
		
	}
}

void Map::DrawMap()
{
	int type = 0;
	for (int row = 0; row < 20; row++)
	{
		for (int coloumn = 0; coloumn < 25; coloumn++)
		{
			type = map[row][coloumn];
			dest.x = coloumn * 32;
			dest.y = row * 32;
			switch (type)
			{			
			case 3: //floor
				TextureManager::Draw(floor, src, dest); break;
			case 4: //black_floor
				TextureManager::Draw(black_floor, src, dest); break;				
			default:
				TextureManager::Draw(wall, src, dest); break;
			}
			

		}
		
	}
}

