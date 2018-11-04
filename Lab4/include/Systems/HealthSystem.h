#ifndef HEALTHSYSTEM_H
#define HEALTHSYSTEM_H

#include <Systems/System.h>

class HealthSystem : public System
{
public:
	HealthSystem() {};
	~HealthSystem() {};
	void addEntity(Entity ent) override;
	void updateComponent(Component * com) override;
};

#endif // !HEALTHSYSTEM_H