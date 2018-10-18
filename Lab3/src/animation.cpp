#include <Animation.h>
#include <States/Idle.h>

Animation::Animation()
{
	m_current = new Idle();
}

void Animation::idle()
{
}

void Animation::jumping()
{
}

void Animation::action()
{
}
