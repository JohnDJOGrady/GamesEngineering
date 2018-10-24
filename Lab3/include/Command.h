#ifndef COMMAND_H
#define COMMAND_H

#include <iostream>
#include <Animation.h>

class Command
{
public:
	virtual ~Command() {};
	virtual void execute(Animation*a) = 0;
	virtual void undo() = 0;

protected:
	Command() {};
};

#endif // !COMMAND_H