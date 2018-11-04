#include <Systems/RenderSystem.h>

void RenderSystem::addEntity(Entity ent)
{
	m_entities.push_back(ent);
}

void RenderSystem::draw(SDL_Renderer * renderer)
{
	for (Entity & entity : m_entities)
	{
		for (Component* com : entity.getComponents())
		{
			if (com->getId() == 3)
			{
				SDL_Rect src = dynamic_cast<SpriteComponent*>(com)->getSource();
				SDL_Rect dest = dynamic_cast<SpriteComponent*>(com)->getDestination();
				SDL_Texture* texture = dynamic_cast<SpriteComponent*>(com)->getTexture();

				for (Component * faux_com : entity.getComponents())
				{
					if (faux_com->getId() == 2)
					{
						dest.x = (int)dynamic_cast<PositionComponent*>(faux_com)->getX();
						dest.y = (int)dynamic_cast<PositionComponent*>(faux_com)->getY();
					}
				}
				SDL_RenderCopy(renderer, texture, &src, &dest);
			}
		}
	}
}
