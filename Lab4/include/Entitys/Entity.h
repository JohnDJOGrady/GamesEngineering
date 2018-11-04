#ifndef ENTITY_H
#define ENTITY_H

#include <Components/Component.h>
#include <Components/HealthComponent.h>
#include <Components/PositionComponent.h>
#include <Components/SpriteComponent.h>
#include <vector>
#include <algorithm>
#include <iostream>

// enum to control the direction of movement of the characters, used in the AISystem and ControlComponent
enum Direction {
	UP,
	DOWN,
	LEFT,
	RIGHT
};

class Entity 
{
public:
	Entity(int id);
	void addComponent(Component * com);
	void removeComponent(Component * com);
	int getId() { return m_id; }; // used for id matching with components
	Direction getDir() { return m_direction; }; // used to control AI units

	std::vector<Component*> getComponents();
	Component* getComponent(ComponentType type); // get component by type

private:
	std::vector<Component*> m_components;
	Direction m_direction;
	int m_id;
};

#endif // !ENTITY_H
