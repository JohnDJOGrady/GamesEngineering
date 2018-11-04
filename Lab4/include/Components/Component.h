#ifndef COMPONENT_H
#define COMPONENT_H

class Component
{
public:
	virtual ~Component() {};
	int getId() { return m_id; };
protected:
	int m_id;
};

#endif // !COMPONENT_H
