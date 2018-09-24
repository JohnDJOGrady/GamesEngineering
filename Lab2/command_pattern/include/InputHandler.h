#ifndef INPUT_HANDLER_H
#define INPUT_HANDLER_H

#include <SDL.h>
#include "ConcreteCommand.h"

class InputHandler
{
public:
	void handleInput();
	void bindCommands();

private:
	Command * m_buttonX_;
	Command * m_buttonY_;
	Command * m_buttonA_;
	Command * m_buttonB_;
	Command * m_leftClick_;

	SDL_GameController *m_controller;
};

#endif // !INPUT_HANDLER_H
