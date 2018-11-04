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

	std::string path = m_resourcePath + "grid.png";
	m_spriteSheet = loadTexture(path);
	player.addComponent(new HealthComponent("Player"));
	player.addComponent(new PositionComponent(200, 400));
	player.addComponent(new SpriteComponent(m_spriteSheet, 0, 0, 85, 85));

	alien.addComponent(new HealthComponent("Alien"));
	alien.addComponent(new PositionComponent(400, 200));
	alien.addComponent(new SpriteComponent(m_spriteSheet, 85, 0, 85, 85));

	cat.addComponent(new HealthComponent("Cat"));
	cat.addComponent(new PositionComponent(500, 700));
	cat.addComponent(new SpriteComponent(m_spriteSheet, 170, 0, 85, 85));

	dog.addComponent(new HealthComponent("Dog"));
	dog.addComponent(new PositionComponent(1000, 300));
	dog.addComponent(new SpriteComponent(m_spriteSheet, 255, 0, 85, 85));
	
	renderSys.addEntity(player);
	renderSys.addEntity(alien);
	renderSys.addEntity(cat);
	renderSys.addEntity(dog);

	healthSys.addEntity(player);
	healthSys.addEntity(alien);
	healthSys.addEntity(cat);
	healthSys.addEntity(dog);

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

}

///<summary>
/// common update loop, called every game cycle
/// @param e - event handler
///</summary>
void Game::update()
{
	healthSys.update();
}

///<summary>
/// render any textures and game entities to the SDL_Renderer
///</summary>
void Game::render()
{
	SDL_RenderClear(m_renderer);
	renderSys.draw(m_renderer);
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