#include <Player.h>

Player::Player()
{
	frame_dim = 64;
	frame_count = 3;
	m_srcRect.x = 0;
	m_srcRect.y = 0;
	m_srcRect.w = frame_dim;
	m_srcRect.h = frame_dim;

	m_targetRect.x = 0;
	m_targetRect.y = 0;
	m_targetRect.w = frame_dim;
	m_targetRect.h = frame_dim;
}

Player::Player(float x, float y) : Player::Player()
{
	m_pos.x = x;
	m_pos.y = y;
	m_targetRect.x = m_pos.x;
	m_targetRect.y = m_pos.y;
}

Player::~Player()
{
	delete this;
}

void Player::handleInput(SDL_Event & e)
{
	m_keys.handleInput(e);
}

void Player::update()
{
	m_srcRect.x = frame_dim * frame_count;
	frame_count += 1;
	if (frame_count > 5)
	{
		frame_count = 3;
	}
	SDL_Delay(500);
}

void Player::render(SDL_Renderer* renderer)
{
	renderTexture(renderer, m_texture);
}

void Player::cleanup()
{
	SDL_DestroyTexture(m_texture);
}

///<summary>
/// Render the texture at the location provided, query texture for it's original width and height
/// @param texture - pointer to texture object we want to render
/// @param x - the target x position of where we want to render
/// @param y - the target y position of where we want to render
///</summary>
void Player::renderTexture(SDL_Renderer* renderer, SDL_Texture * texture)
{
	SDL_RenderCopy(renderer, texture, &m_srcRect, &m_targetRect);
}

void Player::setTexture(SDL_Texture* texture)
{
	m_texture = texture;
}
