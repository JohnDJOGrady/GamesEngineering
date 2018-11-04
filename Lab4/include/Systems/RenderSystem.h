#ifndef RENDERSYSTEM_H
#define RENDERSYSTEM_H

#include <Systems/System.h>
#include <Components/SpriteComponent.h>

class RenderSystem : public System
{
public:
	RenderSystem() {};
	void addEntity(Entity ent) override;
	void updateComponent(Component *c) override {};
	void draw(SDL_Renderer * renderer);
};

#endif // !RENDERSYSTEM_H
