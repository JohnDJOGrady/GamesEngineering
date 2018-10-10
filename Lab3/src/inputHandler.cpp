#include <InputHandler.h>

//Key press surfaces constants
enum KeyPressSurfaces 
{ 
	KEY_PRESS_SURFACE_DEFAULT, 
	KEY_PRESS_SURFACE_UP, 
	KEY_PRESS_SURFACE_DOWN, 
	KEY_PRESS_SURFACE_LEFT, 
	KEY_PRESS_SURFACE_RIGHT, 
	KEY_PRESS_SURFACE_TOTAL 
};

InputHandler::InputHandler()
{
	m_keyX_ = new FireCommand();
	m_keyY_ = new MeleeCommand();
	m_spaceBar_ = new JumpCommand();
	m_keyD_ = new ShieldCommand();
	m_keyA_ = new CrouchCommand();
}

InputHandler::~InputHandler()
{
	delete this;
}

void InputHandler::handleInput(SDL_Event &e)
{
	if (e.key.keysym.sym == SDLK_SPACE) { m_spaceBar_->execute(); };
	if (e.key.keysym.sym == SDLK_d) { m_keyD_->execute(); };
	if (e.key.keysym.sym == SDLK_a) { m_keyA_->execute(); };
	if (e.key.keysym.sym == SDLK_y) { m_keyY_->execute(); };
	if (e.key.keysym.sym == SDLK_x) { m_keyX_->execute(); };
}
