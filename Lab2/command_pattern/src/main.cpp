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

bool init()
{
	// init check
	bool success = true;

	// Init
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

int main(int argc, char * argv[])
{
	bool quit = false;
	SDL_Event e;
	InputHandler * keys = new InputHandler();

	if (!init())
	{
		std::cout << "Failed to init" << std::endl;
		SDL_Delay(2000);
	}
	else
	{
		SDL_BlitSurface(m_media, NULL, m_screenSurface, NULL);
		SDL_UpdateWindowSurface(m_window);
		SDL_Delay(2000);

		while (!quit)
		{
			while (SDL_PollEvent(&e) != 0)
			{
				if (e.type == SDL_QUIT)
				{
					quit = true;
				}
				keys->handleInput(e);
			}
		}
		close();
		return 0;
	}
}