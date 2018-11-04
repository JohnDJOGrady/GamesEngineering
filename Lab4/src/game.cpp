#include <Game.h>

///<summary>
/// Default constructor
///</summary>
Game::Game() : player(1), alien(2), cat(3), dog(4)
{
	srand(time(NULL));
	if (!init())
	{
		log("Failed to init SDL elements");
	}

	std::string path = m_resourcePath + "grid.png";
	m_spriteSheet = loadTexture(path);
	player.addComponent(new HealthComponent("Player", 150));
	player.addComponent(new PositionComponent(200, 400));
	player.addComponent(new SpriteComponent(m_spriteSheet, 0, 0, 85, 85));
	player.addComponent(new ControlComponent());

	alien.addComponent(new HealthComponent("Alien", 75));
	alien.addComponent(new PositionComponent(400, 200));
	alien.addComponent(new SpriteComponent(m_spriteSheet, 85, 0, 85, 85));

	cat.addComponent(new HealthComponent("Cat", 300));
	cat.addComponent(new PositionComponent(500, 700));
	cat.addComponent(new SpriteComponent(m_spriteSheet, 170, 0, 85, 85));

	dog.addComponent(new HealthComponent("Dog", 500));
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

	aiSys.addEntity(alien);
	aiSys.addEntity(cat);
	aiSys.addEntity(dog);

	controlSys.addEntity(player);
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
	if (e.type == SDL_QUIT)
	{
	}
	if (e.type == SDL_KEYDOWN)
	{
		controlSys.handle(e.key.keysym.sym);
	}
}

///<summary>
/// common update loop, called every game cycle
/// @param e - event handler
///</summary>
void Game::update()
{
	healthSys.update();
	aiSys.update();
	controlSys.updatePosition();
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