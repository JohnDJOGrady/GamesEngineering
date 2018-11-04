#include <Entitys/Entity.h>

Entity::Entity(int id)
{
	m_id = id; // unique entity id
	m_direction = (Direction)(rand() % 4 + 0);
}

void Entity::addComponent(Component* com)
{
	com->setID(m_id); // anytime a component is added link it to the unique id of the entity
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

Component * Entity::getComponent(ComponentType type)
{
	for (Component* com : m_components)
	{
		if (com->getType() == type)
		{
			return com;
		}
		else
		{
			return nullptr;
		}
	}
}
