#include "GameLogic.h"
#include "Map.h"
#include "ForegroundMap.h"

GameLogic::GameLogic()
{

}

bool GameLogic::ismovevalid(int xpos, int ypos, std::string keypressed, int b_map[20][25], int f_map[20][25])
{
	int map_xpos = xpos / 32;
	int map_ypos = ypos / 32;



	if (keypressed == "up") // be aware x,y are reversed! because of how arrays works
	{
		if (f_map[map_ypos - 1][map_xpos] == 2)
		{
			if (b_map[map_ypos - 2][map_xpos] == 0 || f_map[map_ypos - 2][map_xpos] == 2)
				return false;
			else
			{
				f_map[map_ypos - 2][map_xpos] = 2;
				f_map[map_ypos - 1][map_xpos] = 0;
				return true;
			}
		}
		else if (b_map[map_ypos - 1][map_xpos] == 3 || b_map[map_ypos - 1][map_xpos] == 4)
		{
			return true;
		}
		else
			return false;
	}
	else if (keypressed == "down")
	{
		if (f_map[map_ypos + 1][map_xpos] == 2)
		{
			if (b_map[map_ypos + 2][map_xpos] == 0 || f_map[map_ypos + 2][map_xpos] == 2)
				return false;
			else
			{
				f_map[map_ypos + 2][map_xpos] = 2;
				f_map[map_ypos + 1][map_xpos] = 0;
				return true;
			}
		}
		else if (b_map[map_ypos + 1][map_xpos] == 3 || b_map[map_ypos + 1][map_xpos] == 4)
		{
			return true;
		}
		else
			return false;
	}
	else if (keypressed == "right")
	{
		if (f_map[map_ypos][map_xpos + 1] == 2)
		{
			if (b_map[map_ypos][map_xpos + 2] == 0 || f_map[map_ypos][map_xpos + 2] == 2)
				return false;
			else
			{
				f_map[map_ypos][map_xpos + 2] = 2;
				f_map[map_ypos][map_xpos + 1] = 0;
				return true;
			}
		}
		else if (b_map[map_ypos][map_xpos + 1] == 3 || b_map[map_ypos][map_xpos + 1] == 4)
		{
			return true;
		}
		else
			return false;
	}
	else if (keypressed == "left")
	{
		if (f_map[map_ypos][map_xpos - 1] == 2)
		{
			if (b_map[map_ypos][map_xpos - 2] == 0 || f_map[map_ypos][map_xpos - 2] == 2)
				return false;
			else
			{
				f_map[map_ypos][map_xpos - 2] = 2;
				f_map[map_ypos][map_xpos - 1] = 0;
				return true;
			}
		}
		else if (b_map[map_ypos][map_xpos - 1] == 3 || b_map[map_ypos][map_xpos - 1] == 4)
		{
			return true;
		}
		else
			return false;
	}
	else
		throw "this shouldn't happen!"; 
		
	
}

bool GameLogic::islevelcomplete(int f_map[20][25])
{
	bool finished = true;

	int lvl1_completed[20][25] = {
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
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

	for (int row = 0; row < 20; row++)
	{
		for (int coloumn = 0; coloumn < 25; coloumn++)
		{
			if (f_map[row][coloumn] != lvl1_completed[row][coloumn])
				finished = false;

		}

	}

	return finished;
}