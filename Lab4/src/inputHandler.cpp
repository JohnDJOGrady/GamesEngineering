#include <InputHandler.h>

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
	if (e.type == SDL_KEYDOWN)
	{
		if (e.key.keysym.sym == SDLK_SPACE) { m_spaceBar_->execute(); };
		if (e.key.keysym.sym == SDLK_d) { m_keyD_->execute(); };
		if (e.key.keysym.sym == SDLK_a) { m_keyA_->execute(); };
	}
}
