#ifndef ANIMATION_H
#define ANIMATION_H
#include <iostream>

class Animation
{
	class State* m_current;
	class State* m_previous;
public:
	Animation();
	void setCurrent(State *s) { m_current = s; };
	void setPrevious(State *s) { m_previous = s; };
	void idle();
	void jumping();
	void action();

private:
};

#endif // !ANIMATION_H
