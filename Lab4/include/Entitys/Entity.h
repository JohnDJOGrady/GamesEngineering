#ifndef ENTITY_H
#define ENTITY_H

#include <Components/Component.h>
#include <vector>
#include <algorithm>

class Entity 
{
	int id;
public:
	Entity();
	void addComponent(Component c);
	void removeComponent(Component c);
	std::vector<Component> getComponents();

private:
	std::vector<Component> m_components;
};

#endif // !ENTITY_H
