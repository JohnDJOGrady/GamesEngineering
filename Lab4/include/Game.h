#ifndef GAME_H
#define GAME_H

#include <SDL.h>
#include <SDL_image.h>
#include <Entitys/Entity.h>
#include <Systems/RenderSystem.h>
#include <Systems/HealthSystem.h>
#include <iostream>
#include <string>
#include <vector>

//Screen dimension constants 
const int SCREEN_WIDTH = 1600;
const int SCREEN_HEIGHT = 900;

class Game
{
public:
	Game();
	~Game();
	bool init();
	void run();
	void event(SDL_Event &e);
	void update();
	void render();
	void cleanup();

	void log(const std::string &message);

	SDL_Texture* loadTexture(std::string &path);
	void renderTexture(SDL_Texture* texture, int x, int y);
	void renderTexture(SDL_Texture* texture, int x, int y, int w, int h);

private:
	// default resource path
	std::string m_resourcePath = ".\\resources\\";
	// pointer to the currentKey state, updated every time SDL polls and event
	const Uint8* m_currentKeys = SDL_GetKeyboardState(NULL);

	// The window we'll be rendering to and the renderer
	SDL_Window* m_window = nullptr;
	SDL_Renderer* m_renderer = nullptr;

	//The surface contained by the window 
	SDL_Surface* m_screenSurface = nullptr;
	SDL_Texture* m_spriteSheet;

	Entity player, alien, cat, dog;
	RenderSystem renderSys;
	HealthSystem healthSys;
};

#endif // ! GAME_H