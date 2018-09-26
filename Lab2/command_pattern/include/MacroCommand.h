#ifndef MACRO_COMMAND_H
#define MACRO_COMMAND_H

#include "Command.h"
#include <list>
class MacroCommand : public Command
{
public:
	MacroCommand();
	virtual ~MacroCommand();
	virtual void add(Command*);
	virtual void remove(Command*);
	virtual void execute();
	virtual void undo();
private:
	std::list<Command*>* commands;
};

#endif // !MACRO_COMMAND_H
