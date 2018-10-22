#include <States/Idle.h>
#include <States/Action.h>
#include <States/Jumping.h>

void Idle::jumping(Animation * a)
{
	std::cout << "Jumping" << std::endl;
	a->setCurrent(new Jumping());
	delete this;
}

void Idle::action(Animation * a)
{
	std::cout << "Action" << std::endl;
	a->setCurrent(new Action());
	delete this;
}
