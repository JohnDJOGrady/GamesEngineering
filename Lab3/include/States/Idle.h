#ifndef IDLE_H
#define IDLE_H
#include <States/State.h>

class Idle : public State
{
public:
	Idle() {};
	~Idle() {};
	void jumping(Animation* a);
	void action(Animation* a);
};

#endif // IDLE_H
