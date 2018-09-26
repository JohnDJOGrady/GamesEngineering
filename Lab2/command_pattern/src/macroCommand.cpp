#include "MacroCommand.h"

MacroCommand::MacroCommand()
{
}

MacroCommand::~MacroCommand()
{
}

void MacroCommand::add(Command * c)
{
	commands->push_back(c);
}

void MacroCommand::remove(Command * c)
{
	if (c != nullptr)
	{
		commands->remove(c);
	}
}

void MacroCommand::execute()
{
	std::list<Command*>::iterator iter;
	for (iter = commands->begin(); iter != commands->end(); iter++)
	{
		(*iter)->execute();
	}
}

void MacroCommand::undo()
{
	if (!commands->empty())
	{
		std::list<Command*>::iterator iter = commands->end();
		--iter;
		remove(*iter);
	}
}
