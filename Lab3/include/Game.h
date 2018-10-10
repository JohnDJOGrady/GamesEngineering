#ifndef GAME_H
#define GAME_H

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
	void update(SDL_Event &e);
	void render();
	void cleanup();

	void handleInput();
	void log(const std::string &message);
	bool loadResources();

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
	SDL_Texture* m_texture = nullptr;

	std::vector<SDL_Texture*> m_textures;
};

#endif // ! GAME_H