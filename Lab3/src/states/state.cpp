#include <States/State.h>

void State::idle(Animation * a)
{
	std::cout << "State::Idle" << std::endl;
}

void State::jumping(Animation * a)
{
	std::cout << "State::Jumping" << std::endl;
}

void State::action(Animation * a)
{
	std::cout << "State::Action" << std::endl;
}
