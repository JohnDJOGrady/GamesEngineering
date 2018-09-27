/// <summary>
/// @mainpage Command Pattern lab
/// @author(s) John O'Grady
/// @version 1.0
/// @brief none
/// </summary>

#include <iostream>
#include <SDL.h>

/*int main(int argc, char * argv[])
{
	//The window we'll be rendering to 
	SDL_Window* gWindow = NULL; 
	//The surface contained by the window 
	SDL_Surface* gScreenSurface = NULL; 
	//The image we will load and show on the screen 
	SDL_Surface* gHelloWorld = NULL;
	int const SCREEN_WIDTH = 1600;
	int const SCREEN_HEIGHT = 900;

	//Main loop flag
	bool quit = false;

	//Event handler
	SDL_Event e;

	//While application is running
	while (!quit)
	{
		//Handle events on queue
		while (SDL_PollEvent(&e) != 0)
		{
			//User requests quit
			if (e.type == SDL_QUIT)
			{
				quit = true;
			}
		}
	}

	cin.get();
	return 0;
}*/

// setting up game loop

int main(int argc, char * argv[])
{
	// if SDL fails to load indicate, wait, then quit out
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		std::cout << "Failed to initialise SDL." << std::endl;

		return -1;
	}

	// initialize the SDL window with given parameters
	SDL_Window *window = SDL_CreateWindow("Demo Game",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		640,
		480,
		SDL_WINDOW_OPENGL);
	SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	// if the window doesnt init (for whatever reason) log the error and quit out
	if (window == nullptr)
	{
		SDL_Log("Window could not be created. %s", SDL_GetError());
		return -1;
	}

	// wait for event of any kind to break out of the loop
	while (true)
	{
		SDL_Event e;
		if (SDL_PollEvent(&e))
		{
			if (e.type == SDL_QUIT)
			{
				break;
			}
		}
	}

	std::cout << "Success." << std::endl;
	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}