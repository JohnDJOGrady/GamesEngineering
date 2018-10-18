#include <states\Jumping.h>

void Jumping::idle(Animation * a)
{
	std::cout << "Jumping to Idle" << std::endl;
	a->setCurrent(new Idle());
	delete this;
}
