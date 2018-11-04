#ifndef COMPONENT_H
#define COMPONENT_H

enum ComponentType
{
	BASE,
	HEALTH,
	POSITION,
	RENDER,
	CONTROL
};

class Component
{
public:
	virtual ~Component() {};

	int getId() { return m_id; };
	void setID(int id) { m_id = id; };

	ComponentType getType() { return m_type; };
	void setType(ComponentType type) { m_type = type; };
protected:
	int m_id;
	ComponentType m_type;
};

#endif // !COMPONENT_H
