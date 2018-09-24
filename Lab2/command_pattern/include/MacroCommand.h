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
	virtual void remover(Command*);
	virtual void execute();
private:
	std::list<Command*>* commands;
};

#endif // !MACRO_COMMAND_H