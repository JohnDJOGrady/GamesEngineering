#include <Entitys/Entity.h>

Entity::Entity()
{
}

void Entity::addComponent(Component* com)
{
	m_components.push_back(com);
}

void Entity::removeComponent(Component* com)
{
	if (!m_components.empty())
	{
		m_components.erase(std::remove(m_components.begin(), m_components.end(), com), m_components.end());
	}
}

std::vector<Component*> Entity::getComponents()
{
	return m_components;
}
