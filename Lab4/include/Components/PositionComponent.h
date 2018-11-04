#ifndef POSITIONCOMPONENT_H
#define POSITIONCOMPONENT_H

#include <Components/Component.h>
#include <iostream>

class PositionComponent : public Component
{
public:
	PositionComponent(float x, float y);
	void setPos(float x, float y);
	void setX(float value);
	void setY(float value);
	float getX() { return m_x; };
	float getY() { return m_y; };
private:
	float m_x, m_y;
};

#endif // !POSITIONCOMPONENT_H
