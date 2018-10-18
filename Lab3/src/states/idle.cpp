#include <States/Idle.h>

void Idle::jumping(Animation * a)
{
	std::cout << "Jumping" << std::endl;
	a->setCurrent(new Idle());
	delete this;
}

void Idle::action(Animation * a)
{
	std::cout << "Action" << std::endl;
	a->setCurrent(new Idle());
	delete this;
}
