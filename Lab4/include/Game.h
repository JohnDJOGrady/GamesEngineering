#ifndef GAME_H
#define GAME_H

#include <SDL.h>
#include <SDL_image.h>
#include <Entitys/Entity.h>
#include <Systems/RenderSystem.h>
#include <Systems/HealthSystem.h>
#include <Systems/ControlSystem.h>
#include <Systems/AISystem.h>
#include <iostream>
#include <string>
#include <vector>
#include <stdio.h> 
#include <stdlib.h>  
#include <time.h>

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

private:
	// default resource path
	std::string m_resourcePath = ".\\resources\\";

	// The window we'll be rendering to and the renderer
	SDL_Window* m_window = nullptr;
	SDL_Renderer* m_renderer = nullptr;

	//The surface contained by the window 
	SDL_Surface* m_screenSurface = nullptr;
	SDL_Texture* m_spriteSheet;

	Entity player, alien, cat, dog;

	RenderSystem renderSys;
	HealthSystem healthSys;
	ControlSystem controlSys;
	AISystem aiSys;
};

#endif // ! GAME_H