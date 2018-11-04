#include <Systems/ControlSystem.h>

void ControlSystem::addEntity(Entity ent)
{
	m_entities.push_back(ent);
}

void ControlSystem::updateComponent(Component * com)
{
}

///<summary>
/// custome handle loop, diffculty with invalid pointers using the "update component" loop, set the direction of control component based on last key press
///</summary>
void ControlSystem::handle(SDL_Keycode key)
{
	for (Entity& entity : m_entities)
	{
		for (Component * com : entity.getComponents())
		{
			if (com->getType() == CONTROL)
			{
				m_control = dynamic_cast<ControlComponent *>(com);
				switch (key)
				{
				case SDLK_UP:
					m_control->setDirection(UP);
					break;
				case SDLK_DOWN:
					m_control->setDirection(DOWN);
					break;
				case SDLK_LEFT:
					m_control->setDirection(LEFT);
					break;
				case SDLK_RIGHT:
					m_control->setDirection(RIGHT);
					break;
				default:
					break;
				}
			}
		}
	}
}

///<summary>
/// itterate through entities within the list and update their position component based on the value of the direction in the control component
///</summary>
void ControlSystem::updatePosition()
{
	for (Entity & entity : m_entities)
	{
		for (Component* com : entity.getComponents())
		{
			if (com->getType() == CONTROL)
			{
				Direction dir = dynamic_cast<ControlComponent*>(com)->getDirection();
				for (Component * faux_com : entity.getComponents())
				{
					if (faux_com->getType() == POSITION)
					{
						PositionComponent* position = dynamic_cast<PositionComponent*>(faux_com);
						int x = position->getX();
						int y = position->getY();
						
						switch (dir)
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
					}
				}
			}
		}
	}
}
