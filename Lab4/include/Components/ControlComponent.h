#ifndef CONTROLCOMPONENT_H
#define CONTROLCOMPONENT_H

#include <SDL.h>
#include <Components/Component.h>


class ControlComponent : public Component
{
public:
	ControlComponent() { m_type = CONTROL; m_direction = Direction::UP;};
	void setDirection(Direction dir) { m_direction = dir; };
	Direction getDirection() { return m_direction; };
	Direction m_direction = Direction::UP;
};

#endif // !CONTROLCOMPONENT_H
