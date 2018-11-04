#include <Systems/HealthSystem.h>

void HealthSystem::addEntity(Entity ent)
{
	m_entities.push_back(ent);
}

void HealthSystem::updateComponent(Component * com)
{
	if (com->getId() == 1)
	{
		HealthComponent* health = dynamic_cast<HealthComponent*>(com);
		if (health != nullptr)
		{
			int h = health->getHealth();
			if (h >= 0)
			{
				h--;
				health->setHealth(h);
			}
			if( h == 0)
			{
				std::cout << health->getName() << ": " << "Dead" << std::endl;
			}
			else
			{
			}
		}
	}
}
