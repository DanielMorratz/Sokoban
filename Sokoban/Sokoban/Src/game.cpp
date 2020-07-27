#include "game.h"
#include "TextureManager.h"
#include "GameObject.h"
#include "Map.h"
#include "ForegroundMap.h"
#include "GameLogic.h"

GameObject* player;
SDL_Renderer* Game::renderer = nullptr;
Map* map;
Foreground* foreground;
GameLogic* gamelogic;

Game::Game()
{}

Game::~Game()
{}

void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	int flags = 0;
	if (fullscreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		std::cout << "Subsystems Initialised!" << std::endl;

		window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, flags);
		if (window)
		{
			std::cout << "Window created!" << std::endl;
		}
		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer)
		{
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			std::cout << "Renderer created!" << std::endl;
		}		
	}

	gamelogic = new GameLogic();
	player = new GameObject("assets/player.png",384,256);
	map = new Map();
	foreground = new Foreground();



}

void Game::handleEvents()
{
	SDL_Event event;
	SDL_PollEvent(&event);

	switch (event.type)
	{
		case SDL_QUIT:
		isRunning = false; break;
	}

	if (event.type == SDL_KEYDOWN)
	{
		switch (event.key.keysym.sym)
		{
		case SDLK_UP:
			if (gamelogic->ismovevalid(player->xpos, player->ypos, "up",map->map , foreground->map) == true) 
			{
				player->Setposition(0, -32);
			}
			break;
		case SDLK_DOWN:
			if (gamelogic->ismovevalid(player->xpos, player->ypos, "down", map->map, foreground->map) == true)
			{
				player->Setposition(0, 32);
			}
			break;
		case SDLK_LEFT:
			if (gamelogic->ismovevalid(player->xpos, player->ypos, "left", map->map, foreground->map) == true)
			{
				player->Setposition(-32, 0);
			}
			break;
		case SDLK_RIGHT:
			if (gamelogic->ismovevalid(player->xpos, player->ypos, "right", map->map, foreground->map) == true)
			{
				player->Setposition(32, 0);
			}
			break;

		default:
			break;
		}
	}
}

void Game::update() // game logic
{
	player->Update();
	//map->DrawMap();
	//map->LoadMap(); implement this, so switching between maps is easy.
	//TODO: islevelcompleted();
	if (gamelogic->islevelcomplete(foreground->map) == true) {
		isRunning = false;
		std::cout << "great job, you did it!\n";
	}

}

void Game::render()
{
	SDL_RenderClear(renderer);
	map->DrawMap();
	foreground->DrawMap();
	//Add stuff to render here
	player->Render();
	
	SDL_RenderPresent(renderer);
}

void Game::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit(); // quits subsystems
	std::cout << "Game Cleaned" << std::endl;
}
