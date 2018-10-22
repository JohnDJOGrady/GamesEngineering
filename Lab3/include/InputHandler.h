#ifndef INPUT_HANDLER_H
#define INPUT_HANDLER_H

#include <SDL.h>
#include <ConcreteCommand.h>
#include <Animation.h>

class InputHandler
{
public:
	InputHandler();
	~InputHandler();
	void handleInput(SDL_Event &e);

private:
	Command * m_keyX_;
	Command * m_keyY_;
	Command * m_spaceBar_;
	Command * m_keyD_;
	Command * m_keyA_;

	Animation * animation;
};

#endif // !INPUT_HANDLER_H
