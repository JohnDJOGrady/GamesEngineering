#include <Entitys/Entity.h>

Entity::Entity()
{
}

void Entity::addComponent(Component c)
{
	m_components.push_back(c);
}

void Entity::removeComponent(Component c)
{
	if (!m_components.empty())
	{
		m_components.erase(std::remove(m_components.begin(), m_components.end(), c), m_components.end());
	}
}

std::vector<Component> Entity::getComponents()
{
	return m_components;
}
