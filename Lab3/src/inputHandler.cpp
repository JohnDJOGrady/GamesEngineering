#include <InputHandler.h>

InputHandler::InputHandler()
{
	m_keyD_ = new MeleeCommand();
	m_spaceBar_ = new JumpCommand();

	animation = new Animation();
}

InputHandler::~InputHandler()
{
	delete this;
}

void InputHandler::handleInput(SDL_Event &e)
{
	if (e.type == SDL_KEYDOWN && animation->getcurrentFrame() == 0)
	{
		if (e.key.keysym.sym == SDLK_SPACE) { m_spaceBar_->execute(animation); };
		if (e.key.keysym.sym == SDLK_LSHIFT) { m_keyD_->execute(animation); };
		if (e.key.keysym.sym == SDLK_a) { animation->idle(); };
	}
}
