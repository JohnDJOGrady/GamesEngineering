#include <Animation.h>
#include <States/Idle.h>

Animation::Animation()
{
	m_current = new Idle();
}

void Animation::idle()
{
	this->setPrevious(this->m_current);
	m_current->idle(this);
	m_currentState = IDLE;
}

void Animation::jumping()
{
	this->setPrevious(this->m_current);
	m_current->jumping(this);
	m_currentState = JUMP;
}

void Animation::action()
{
	this->setPrevious(this->m_current);
	m_current->action(this);
	m_currentState = ACTION;
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
