#ifndef INPUT_HANDLER_H
#define INPUT_HANDLER_H

#include <SDL.h>
#include <ConcreteCommand.h>

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
};

#endif // !INPUT_HANDLER_H
