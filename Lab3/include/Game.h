#ifndef GAME_H
#define GAME_H

#include <Player.h>
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <string>
#include <vector>
#include <InputHandler.h>

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
	void update();
	void render();
	void cleanup();

	void log(const std::string &message);
	bool loadResources();

	SDL_Texture* loadTexture(std::string &path);

private:
	// default resource path
	std::string m_resourcePath = ".\\resources\\";

	// The window we'll be rendering to and the renderer
	SDL_Window* m_window = nullptr;
	SDL_Renderer* m_renderer = nullptr;

	//The surface contained by the window 
	SDL_Surface* m_screenSurface = nullptr;

	Player m_player;
};

#endif // ! GAME_H