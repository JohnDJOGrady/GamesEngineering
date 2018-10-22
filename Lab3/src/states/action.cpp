#include <States/Action.h>
#include <States/Idle.h>

void Action::idle(Animation * a)
{
	std::cout << "Action to Idle" << std::endl;
	a->setCurrent(new Idle());
	delete this;
}
