#ifndef COMPONENT_H
#define COMPONENT_H

#include <SDL.h>

class Component
{
	int m_id;
public:
	virtual void setID(int id) { m_id = id; };
	virtual int getID() { return m_id; };
private:
};

#endif // !COMPONENT_H
