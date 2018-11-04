#ifndef CONTROLSYSTEM_H
#define CONTROLSYSTEM_H

#include <Systems/System.h>
#include <Components/ControlComponent.h>

class ControlSystem : public System
{
public:
	ControlSystem() {};
	void addEntity(Entity ent) override;
	void updateComponent(Component * com) override;
	void handle(SDL_Keycode key); // processing the key inputs
	void updatePosition(); // additional method due to issues with "updateComponent"

	ControlComponent* m_control; // global component to keep scope of player direction
};

#endif // !CONTROLSYSTEM_H
