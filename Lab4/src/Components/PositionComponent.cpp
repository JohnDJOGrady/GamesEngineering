#include <Components/PositionComponent.h>

///<summary>
/// constructor that sets position and defines the type of component
///</summary>
PositionComponent::PositionComponent(float x, float y)
{
	m_type = POSITION;
	std::cout << x << ", " << y << std::endl;
	m_x = x;
	m_y = y;
}

///<summary>
/// set Position using user values
///</summary>
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
