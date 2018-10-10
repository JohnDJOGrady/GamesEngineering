/// <summary>
/// @mainpage Command Pattern lab
/// @author(s) John O'Grady
/// @version 1.0
/// @brief none
/// </summary>

#include <iostream>
#include <InputHandler.h>
#include <SDL.h>

//Screen dimension constants 
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 460;

//The window we'll be rendering to 
SDL_Window* m_window = NULL;
//The surface contained by the window 
SDL_Surface* m_screenSurface = NULL;

//The image we will load and show on the screen 
SDL_Surface* m_media = NULL;

/// <summary>
/// Initialse the SDL entity and initialse the SDL window
/// </summary>
/// <returns>success flag boolean, throws an error if false</returns>
bool init()
{
	// init check
	bool success = true;

	// Init SDL Visual Elements
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		std::cout << ("SDL could not initialize! SDL_Error: %s\n", SDL_GetError()) << std::endl;

		return false;
	}

	else
	{
		//Create window 
		m_window = SDL_CreateWindow("SDL Command Pattern", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (m_window == NULL)
		{
			std::cout << ("Window could not be created! SDL_Error: %s\n", SDL_GetError()) << std::endl;
			success = false;
		}
		else
		{
			// Get window surface
			m_screenSurface = SDL_GetWindowSurface(m_window);
		}
		return success;
	}
}

/// <summary>
/// Optimised Surface loading
/// </summary>
SDL_Surface * loadSurface(std::string &path)
{
	SDL_Surface* surface = NULL;
	SDL_Surface* loadedSurface = SDL_LoadBMP(path.c_str());
	if (loadedSurface == NULL)
	{
		std::cout << ("Failure to load surface %s! SDL Error: %s", path.c_str(), SDL_GetError()) << std::endl;
	}
	else
	{
		surface = SDL_ConvertSurface(loadedSurface, m_screenSurface->format, NULL);
		if (surface == NULL)
		{
			std::cout << ("Failure to optimised loaded surface %s! SDL Error: %s", path.c_str(), SDL_GetError()) << std::endl;
		}
		SDL_FreeSurface(loadedSurface);
	}
	return surface;	
}

/// <summary>
/// handle safe deletion of any surfaces and quit out of the SDL window
/// </summary>
void close()
{
	//Deallocate surface 
	SDL_FreeSurface(m_media);
	m_media = NULL;

	// Destroy Window
	SDL_DestroyWindow(m_window);
	m_window = NULL;
	SDL_Quit();
}

// main game loop
int main(int argc, char * argv[])
{
	bool quit = false;
	SDL_Event e;
	InputHandler * keys = new InputHandler();
	std::string path = "hello";

	if (!init())
	{
		std::cout << "Failed to init" << std::endl;
		SDL_Delay(2000);
	}
	else
	{
		if (!loadSurface(path))
		{
			std::cout << "Failed to load media" << std::endl;
			SDL_Delay(2000);
		}
		else
		{
			SDL_BlitSurface(m_media, NULL, m_screenSurface, NULL);
			SDL_UpdateWindowSurface(m_window);
		}

		while (!quit)
		{
			while (SDL_PollEvent(&e) != 0)
			{
				if (e.type == SDL_QUIT)
				{
					quit = true;
				}


				//update()
				//render()
				keys->handleInput(e);
			}
		}
		close();
		return 0;
	}
}