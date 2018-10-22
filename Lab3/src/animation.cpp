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
}

void Animation::jumping()
{
	this->setPrevious(this->m_current);
	m_current->jumping(this);
}

void Animation::action()
{
	this->setPrevious(this->m_current);
	m_current->action(this);
}
