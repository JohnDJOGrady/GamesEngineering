#ifndef HEALTHCOMPONENT_H
#define HEALTHCOMPONENT_H

#include <Components/Component.h>
#include <string>

class HealthComponent : public Component {
public:
	HealthComponent(std::string name);
	std::string getName();
	int getHealth();
	void setHealth(int value);
private:
	int m_health;
	std::string m_name;
};

#endif // !HEALTHCOMPONENT_H