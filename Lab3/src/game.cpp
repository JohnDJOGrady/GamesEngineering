#include <Game.h>

///<summary>
/// Default constructor
///</summary>
Game::Game() : m_player(200.f, 200.f)
{
	if (!init())
	{
		log("Failed to init SDL elements");
	}

	std::string grid = m_resourcePath + "spritesheetmegaman1.png";
	m_player.setTexture(loadTexture(grid));
}

///<summary>
/// Deconstructor
///</summary>
Game::~Game()
{
	cleanup();
	delete this;
}

/// <summary>
/// Initialse the SDL entity and initialse the SDL window
/// </summary>
/// <returns>success flag boolean, throws an error if false</returns>
bool Game::init()
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

///<summary>
/// main game loop
///</summary>
void Game::run()
{
	bool end = false;
	SDL_Event e;

	while (!end)
	{
		while (SDL_PollEvent(&e) != 0)
		{
			m_player.handleInput(e);
		}
		update();
		render();
	}
	cleanup();
}

///<summary>
/// common update loop, called every game cycle
/// @param e - event handler
///</summary>
void Game::update()
{
	m_player.update();
}

///<summary>
/// render any textures and game entities to the SDL_Renderer
///</summary>
void Game::render()
{
	SDL_RenderClear(m_renderer);
	m_player.render(m_renderer);
	SDL_RenderPresent(m_renderer);
}

/// <summary>
/// Free up memeory and quit out of sdl
/// </summary>
void Game::cleanup()
{

	// Destroy Window
	SDL_DestroyRenderer(m_renderer);
	SDL_DestroyWindow(m_window);
	SDL_Quit();
}


/// <summary>
/// Error logging function if SDL encounters and error log the message as well as the SDL error
/// also allows for generic logging for debugging
/// @param message the user specified string to be sent to the console
/// </summary>
void Game::log(const std::string &message)
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

///<summary>
/// Function to load in neccessary resources (images, sounds, fonts etc.)
///</summary>
bool Game::loadResources()
{
	// return flag for succesful load;
	bool success = true;

	// queue resource loading here
	return success;
}


/// <summary>
/// Texture loading function
/// @param path - path of the texture to be loaded
/// </summary>
/// <returns>returns a SDL texture that can be rendered</returns>
SDL_Texture * Game::loadTexture(std::string &path)
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