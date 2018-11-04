#ifndef ENTITY_H
#define ENTITY_H

#include <Components/Component.h>
#include <Components/HealthComponent.h>
#include <Components/PositionComponent.h>
#include <Components/SpriteComponent.h>
#include <vector>
#include <algorithm>
#include <iostream>

class Entity 
{
	int id;
public:
	Entity();
	void addComponent(Component * com);
	void removeComponent(Component * com);
	std::vector<Component*> getComponents();

private:
	std::vector<Component*> m_components;
};

#endif // !ENTITY_H
