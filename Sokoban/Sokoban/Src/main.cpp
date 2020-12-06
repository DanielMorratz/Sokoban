#define SDL_MAIN_HANDLED
#include "game.h"
//Todo til level editor: Læs op på Factory pattern.	 https://stackoverflow.com/questions/4007382/how-to-create-class-objects-dynamically
//													 https://www.javatpoint.com/factory-method-design-pattern
Game* game = nullptr;
int main()
{
	const int FPS = 60;
	const int frameDelay = 1000 / FPS; //max time between frames

	uint32_t frameStart;
	int frameTime;


	game = new Game();
	game->init("Sokoban Engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 640, false); 

	while (game->isRunning)
	{
		frameStart = SDL_GetTicks(); //miliseconds since we initialized SDL.


		game->handleEvents();
		game->update();
		game->render();

		frameTime = SDL_GetTicks() - frameStart; // milliseconds it has taken to update and render everything

		if (frameDelay > frameTime) // sets af cap to 60 fps
		{
			SDL_Delay(frameDelay - frameTime);
		}
	}

	std::cout << "Thank you for playing" << std::endl;

	game->clean();
	return 0;
}