#ifndef RENDERSYSTEM_H
#define RENDERSYSTEM_H

#include <Systems/System.h>
#include <Components/SpriteComponent.h>

class RenderSystem : public System
{
public:
	RenderSystem() {};
	void addEntity(Entity ent) override;
	void updateComponent(Component *com) override {};
	void draw(SDL_Renderer * renderer); // custom draw method, issues with nullptrs
};

#endif // !RENDERSYSTEM_H
