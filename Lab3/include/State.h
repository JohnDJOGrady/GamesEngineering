#ifndef STATE_H
#define STATE_H

#include <iostream>
#include <typeinfo>

#include <InputHandler.h>
#include <Animation.h>

class State
{
public:
	virtual void handleInput() {}

	virtual void update() {}

	virtual void idle(Animation* a)
	{
		std::cout << ("State::Idling");
	}
	virtual void jumping(Animation* a)
	{
		std::cout << ("State::Jumping");
	}
	virtual void climbing(Animation* a)
	{
		std::cout << ("State::Climbing");
	}
};

#endif // ! ANIMATION_H

