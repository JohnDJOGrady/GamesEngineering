#ifndef STATE_H
#define STATE_H
#include <Animation.h>

class State
{
public:
	virtual void idle(Animation *a);
	virtual void jumping(Animation *a);
	virtual void action(Animation *a);
};
#endif // !STATE_H

