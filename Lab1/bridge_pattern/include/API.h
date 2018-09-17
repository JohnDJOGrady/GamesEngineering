#ifndef DRAWAPI_H
#define DRAWAPI_H

class DrawAPI 
{
public:
	virtual void Draw() = 0;
};

#endif // !DRAWAPI_H

#ifndef DRAWIMPL_H
#define DRAWIMPL_H

#include <iostream>

class DrawImpl : public DrawAPI
{
public:
	void Draw() { std::cout << "Draw Impl" << std::endl; }
};

#endif // !DRAWIMPL_H

