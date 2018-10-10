/// <summary>
/// @mainpage Command Pattern lab
/// @author(s) John O'Grady
/// @version 1.0
/// @brief none
/// </summary>


#include <iostream>
#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include <InputHandler.h>

//Screen dimension constants 
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 460;

std::string resourcePath = ".\\resources\\";

//The window we'll be rendering to 
SDL_Window* m_window = nullptr;
SDL_Renderer* m_renderer = nullptr;

//The surface contained by the window 
SDL_Surface* m_screenSurface = nullptr;

//The image we will load and show on the screen 
SDL_Surface* m_media = nullptr;

void log(const std::string &message)
{
	if (SDL_GetError() != nullptr)
	{
		std::cout << message << " error: " << SDL_GetError() << std::endl;
	}
	else
	{
		std::cout << message << std::endl;
	}
}

/// <summary>
/// Initialse the SDL entity and initialse the SDL window
/// </summary>
/// <returns>success flag boolean, throws an error if false</returns>
bool init()
{
	// init check
	bool success = true;

	// Init SDL Visual Elements
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		log("Initialisation");
		return false;
	}
	else
	{
		//Create window 
		m_window = SDL_CreateWindow("SDL Command Pattern", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (m_window == nullptr)
		{
			log("Window creation");
			success = false;
		}
		else
		{
			m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
			if (m_renderer == nullptr)
			{
				SDL_DestroyWindow(m_window);
				log("Renderer creation");
				success = false;
			}

			// Get window surface
			m_screenSurface = SDL_GetWindowSurface(m_window);
			IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG); // allow for png and jpeg images to be loaded in
		}
		return success;
	}
}

bool loadResources()
{
	// return flag for succesful load;
	bool success = true;

	// queue resource loading here
	return success;
}

/// <summary>
/// Optimised texture loading
/// </summary>
SDL_Texture * loadTexture(std::string &path)
{
	SDL_Texture* texture = nullptr;
	SDL_Surface* loadedFile = IMG_Load(path.c_str());
	if (loadedFile != nullptr)
	{
		// create a texture from the loaded image file
		texture = SDL_CreateTextureFromSurface(m_renderer, loadedFile);
		SDL_FreeSurface(loadedFile);
		if (texture == nullptr)
		{
			log("Texture loading from surface");
		}
	}
	else
	{
		log("Loading IMG");
	}

	return texture;
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
	std::string texturePath = resourcePath + "grid.png";

	if (!init())
	{
		log("Failed to init SDL elements");
		SDL_Delay(2000);
	}
	else
	{
		if (!loadTexture(texturePath))
		{
			log("Failed to load media");
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