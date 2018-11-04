#ifndef AISYSTEM_H
#define AISYSTEM_H

#include <Systems/System.h>

class AISystem : public System
{
public:
	AISystem();
	void addEntity(Entity ent) override;
	void updateComponent(Component* com)  override;
	void update();
	void boundry(PositionComponent* pos);
};

#endif // !AISYSTEM_H

