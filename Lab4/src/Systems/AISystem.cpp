#include <Systems/AISystem.h>

AISystem::AISystem()
{
}

void AISystem::addEntity(Entity ent)
{
	m_entities.push_back(ent);
}

void AISystem::updateComponent(Component * com)
{
}

///<summary>
/// custom update loop that checks the direction of the entity and applies a position change
///</summary>
void AISystem::update()
{
	for (Entity& entity : m_entities)
	{
		for (Component* com : entity.getComponents())
		{
			if (com->getType() == POSITION)
			{
				PositionComponent* position = dynamic_cast<PositionComponent*>(com);
				if (position != nullptr)
				{
					int x = position->getX();
					int y = position->getY();

					switch (entity.getDir())
					{
					case UP:
						position->setY(y - 1);
						break;
					case DOWN:
						position->setY(y + 1);
						break;
					case LEFT:
						position->setX(x - 1);
						break;
					case RIGHT:
						position->setX(x + 1);
						break;
					default:
						break;
					}
					boundry(position);
				}
			}
		}
	}
}


///<summary>
/// keep the ai within bounds
///</summary>
void AISystem::boundry(PositionComponent* pos)
{
	if (pos->getX() > 1600)
	{
		pos->setX(0);
	}
	if (pos->getX() < 0)
	{
		pos->setX(1600);
	}
	if (pos->getY() > 900)
	{
		pos->setY(0);
	}
	if (pos->getY() < 0)
	{
		pos->setY(900);
	}
}
