#include <Components/HealthComponent.h>

HealthComponent::HealthComponent(std::string name)
{
	m_type = HEALTH;
	m_health = 100;
	m_name = name;
}

HealthComponent::HealthComponent(std::string name, int health)
{
	m_type = HEALTH;
	m_health = health;
	m_name = name;
}

std::string HealthComponent::getName()
{
	return m_name;
}

int HealthComponent::getHealth()
{
	return m_health;
}

void HealthComponent::setHealth(int value)
{
	m_health = value;
}
