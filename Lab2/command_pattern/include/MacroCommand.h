#ifndef MACRO_COMMAND_H
#define MACRO_COMMAND_H

#include <Command.h>
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
	virtual void redo();
	virtual void reset();

private:
	std::list<Command*>* commands;
	std::list<Command*>* undone_commands;
};

#endif // !MACRO_COMMAND_H
