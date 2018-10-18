#ifndef ACTION_H
#define ACTION_H
#include <States/State.h>

class Action : public State
{
public:
	Action() {};
	~Action() {};
	void idle(Animation*a);
};
#endif // !ACTION_H
