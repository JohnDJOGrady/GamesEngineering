#ifndef PLAYER_H
#define PLAYER_H

#include <SDL.h>
#include <SDL_image.h>
#include <InputHandler.h>

struct v
{
	float x = 0;
	float y = 0;
};

class Player
{
public:
	Player();
	Player(float x, float y);
	~Player();

	void handleInput(SDL_Event &e);
	void update();
	void render(SDL_Renderer* renderer);
	void cleanup();

	void setTexture(SDL_Texture* texture);
	void renderTexture(SDL_Renderer* renderer, SDL_Texture* texture);

private:
	InputHandler m_keys;
	// pointer to the currentKey state, updated every time SDL polls and event
	const Uint8* m_currentKeys = SDL_GetKeyboardState(NULL);

	v m_pos;
	SDL_Texture* m_texture;
	SDL_Rect m_targetRect;
	SDL_Rect m_srcRect;

	int frame_count = 0;
	int frame_dim;
};

#endif // !PLAYER_H
