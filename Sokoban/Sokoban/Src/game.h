#pragma once
#ifndef game_h
#define game_h
#include "SDL.h"
#include "SDL_image.h"
#include <iostream>

class Game {
public:
	Game();
	~Game();

	void init(const char* title, int xpos, int ypos, int width, int heigth, bool fullscreen); // initializer <-- Create game window
	void handleEvents();	//Handle userinput e.g keypress
	void update();			//Update all gameobjects
	void render();			// Render to screen
	void clean();			//memory managment
	bool running() { return isRunning; } //lets the game function know whether  the game should or should not be running. If true, runs 
	static SDL_Renderer* renderer;
	bool isRunning = true;

private:
	
	SDL_Window* window;

};

#endif // !game_h

