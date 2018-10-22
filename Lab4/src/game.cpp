#include <Game.h>

///<summary>
/// Default constructor
///</summary>
Game::Game()
{
	if (!init())
	{
		log("Failed to init SDL elements");
	}

	std::string grid = m_resourcePath + "grid.png";
	m_texture = loadTexture(grid);

	// loading texture vector for easy cleanup
	m_textures.push_back(m_texture);
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
			event(e);
		}
		update();
		render();
	}
	cleanup();
}

void Game::event(SDL_Event & e)
{
	m_keys.handleInput(e);
}

///<summary>
/// common update loop, called every game cycle
/// @param e - event handler
///</summary>
void Game::update()
{
}

///<summary>
/// render any textures and game entities to the SDL_Renderer
///</summary>
void Game::render()
{
	SDL_RenderClear(m_renderer);
	int width, height;
	SDL_QueryTexture(m_texture, nullptr, nullptr, &width, &height);
	int x = SCREEN_WIDTH / 2 - width / 2;
	int y = SCREEN_HEIGHT / 2 - height / 2;
	renderTexture(m_texture, x, y, 200, 200);
	SDL_RenderPresent(m_renderer);
}

/// <summary>
/// Free up memeory and quit out of sdl
/// </summary>
void Game::cleanup()
{
	// Destroy all textures
	for (auto &tex : m_textures)
	{
		SDL_DestroyTexture(tex);
	}

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

///<summary>
/// Render the texture at the location provided, query texture for it's original width and height
/// @param texture - pointer to texture object we want to render
/// @param x - the target x position of where we want to render
/// @param y - the target y position of where we want to render
///</summary>
void Game::renderTexture(SDL_Texture * texture, int x, int y)
{
	SDL_Rect targetRect;
	targetRect.x = x;
	targetRect.y = y;

	SDL_QueryTexture(texture, nullptr, nullptr, &targetRect.w, &targetRect.h);
	SDL_RenderCopy(m_renderer, texture, nullptr, &targetRect);
}

///<summary>
/// Render the texture at the location provided, allows for custom scaling of width and height
/// @param texture - pointer to the texture object we want to render
/// @param x - x loc of where we want the target rendererd
/// @param y - y loc of render target
/// @param w - width of the texture to be drawn
/// @param h - height of the texutre to be drawn
///</summary>
void Game::renderTexture(SDL_Texture * texture, int x, int y, int w, int h)
{
	SDL_Rect targetRect;
	targetRect.x = x;
	targetRect.y = y;
	targetRect.w = w;
	targetRect.h = h;
	SDL_RenderCopy(m_renderer, texture, nullptr, &targetRect);
}

///<summary>
/// Render the target location within a texture
/// @param texture - pointer to the texture object we want to render
/// @param x - start x loc of where we want the target rendererd
/// @param y - start y loc of render target
/// @param _x - the end range of the x component of the texture we want rendered
/// @param _y - the end range of the y component of the texture we want rendered
/// @param w - width of the texture to be drawn
/// @param h - height of the texutre to be drawn
///</summary>
void Game::renderTexture(SDL_Texture * texture, int x, int y, int _x, int _y, int w, int h)
{
	SDL_Rect targetRect;
	targetRect.x = x;
	targetRect.y = y;
	targetRect.w = w;
	targetRect.h = h;
	SDL_RenderCopy(m_renderer, texture, nullptr, &targetRect);
}