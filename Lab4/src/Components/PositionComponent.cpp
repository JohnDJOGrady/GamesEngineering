#include <Components/PositionComponent.h>

PositionComponent::PositionComponent(float x, float y)
{
	m_id = 2;
	std::cout << x << ", " << y << std::endl;
	m_x = x;
	m_y = y;
}

void PositionComponent::setPos(float x, float y)
{
	m_x = x;
	m_y = y;
}

void PositionComponent::setX(float value)
{
	m_x = value;
}

void PositionComponent::setY(float value)
{
	m_y = value;
}
