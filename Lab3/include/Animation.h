#ifndef ANIMATION_H
#define ANIMATION_H
#include <iostream>
#include <SDL.h>

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

	void setRect(SDL_Rect* src);
	void setMaxFrames(int max);
	void setFrameRate(int rate);
	void setCurrentFrame(int frame);
	int getcurrentFrame();
	Anim getCurrentState();

private:
	SDL_Rect* m_SrcRect;
	Anim m_currentState;
	int m_currentFrame;
	int m_maxFrames;
	int m_frameRate;
};

#endif // !ANIMATION_H
