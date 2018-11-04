#include <Systems/System.h>

System::System()
{
}

void System::update()
{
	for (Entity & entity : m_entities)
	{
		for (auto & component : entity.getComponents())
		{
			updateComponent(component);
		}
	}
}

void System::updateComponent(Component * com)
{

}

void System::addEntity(Entity ent)
{
	m_entities.push_back(ent);
}
