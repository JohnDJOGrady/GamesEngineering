#ifndef SYSTEM_H
#define SYSTEM_H

#include <Components/Component.h>
#include <Entitys/Entity.h>
#include <vector>

class System
{
public:
	System();
	virtual ~System() {};
	void update();
	virtual void updateComponent(Component * com);
	virtual void addEntity(Entity ent);
protected:
	std::vector<Entity> m_entities;
};

#endif // !SYSTEM_H
