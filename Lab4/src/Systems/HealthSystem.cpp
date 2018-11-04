#include <Systems/HealthSystem.h>

void HealthSystem::addEntity(Entity ent)
{
	m_entities.push_back(ent);
}

///<summary>
/// cycle through each health component and decrement by one, when the characters value reaches 0, announce dead via the console
///</summary>
void HealthSystem::updateComponent(Component * com)
{
	if (com->getType() == HEALTH)
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
