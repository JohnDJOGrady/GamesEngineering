#include <States/Action.h>
#include <States/Idle.h>

void Action::idle(Animation * a)
{
	std::cout << "Idle" << std::endl;
	a->setCurrent(new Action());
	delete this;
}
