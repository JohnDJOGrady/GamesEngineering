#include <InputHandler.h>

InputHandler::InputHandler()
{
	m_keyX_ = new FireCommand();
	m_keyY_ = new MeleeCommand();
	m_spaceBar_ = new JumpCommand();
	m_keyD_ = new ShieldCommand();
	m_keyA_ = new CrouchCommand();

	m_macro = new MacroCommand();
}

InputHandler::~InputHandler()
{
	delete this;
}

void InputHandler::handleInput(SDL_Event &e)
{
	if (e.key.keysym.sym == SDLK_SPACE) { m_macro->add(m_spaceBar_); };
	if (e.key.keysym.sym == SDLK_d) { m_macro->add(m_keyD_); };
	if (e.key.keysym.sym == SDLK_a) { m_macro->add(m_keyA_); };
	if (e.key.keysym.sym == SDLK_y) { m_macro->add(m_keyY_); };
	if (e.key.keysym.sym == SDLK_x) { m_macro->add(m_keyX_); };
	if (e.key.keysym.sym == SDLK_1) { m_macro->undo(); };
	if (e.key.keysym.sym == SDLK_2) { m_macro->redo(); };
	if (e.key.keysym.sym == SDLK_RETURN) 
	{
		m_macro->execute();
		m_macro->reset();
	};
}
