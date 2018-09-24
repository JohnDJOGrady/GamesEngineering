#include "MacroCommand.h"

MacroCommand::MacroCommand()
{
}

MacroCommand::~MacroCommand()
{
}

void MacroCommand::add(Command *)
{
}

void MacroCommand::remover(Command *)
{
}

void MacroCommand::execute()
{
	std::list<Command*>::iterator it;
	for (it = commands->begin(); it != commands->end(); it++)
	{
		(*it)->execute();
	}
}
