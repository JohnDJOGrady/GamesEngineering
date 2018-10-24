#ifndef ANIMATION_H
#define ANIMATION_H
#include <iostream>

enum Anim {
	IDLE,
	JUMP,
	ACTION
};

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

	void setMaxFrames(int max);
	void setFrameRate(int rate);
	void setCurrentFrame(int frame);
	int getcurrentFrame();
	Anim getCurrentState();

private:
	Anim m_currentState;
	int m_currentFrame;
	int m_maxFrames;
	int m_frameRate;
};

#endif // !ANIMATION_H
