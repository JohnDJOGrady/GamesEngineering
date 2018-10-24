#include <Animation.h>
#include <States/Idle.h>

Animation::Animation()
{
	m_current = new Idle();
}

void Animation::idle()
{
	this->setPrevious(this->m_current);
	m_SrcRect->x = 0;
	m_SrcRect->y = 0;
	m_current->idle(this);
	m_currentState = IDLE;
}

void Animation::jumping()
{
	this->setPrevious(this->m_current);
	m_SrcRect->x = 256;
	m_SrcRect->y = 64;
	m_current->jumping(this);
	m_currentState = JUMP;
}

void Animation::action()
{
	this->setPrevious(this->m_current);
	m_SrcRect->x = 192;
	m_SrcRect->y = 0;
	m_current->action(this);
	m_currentState = ACTION;
}

void Animation::setRect(SDL_Rect * src)
{
	m_SrcRect = src;
}

void Animation::setMaxFrames(int max)
{
	m_maxFrames = max;
}

void Animation::setFrameRate(int rate)
{
	m_frameRate = rate;
}

void Animation::setCurrentFrame(int frame)
{
	m_currentFrame = frame;
}

int Animation::getcurrentFrame()
{
	return m_currentFrame;
}

Anim Animation::getCurrentState()
{
	return m_currentState;
}
