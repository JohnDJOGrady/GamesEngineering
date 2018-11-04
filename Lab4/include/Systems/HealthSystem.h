#ifndef HEALTHSYSTEM_H
#define HEALTHSYSTEM_H

#include <Systems/System.h>

class HealthSystem : public System
{
public:
	HealthSystem() {};
	~HealthSystem() {};
	void addEntity(Entity e) override;
	void updateComponent(Component * c) override;
};

#endif // !HEALTHSYSTEM_H