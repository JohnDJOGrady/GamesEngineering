#include <MacroCommand.h>

MacroCommand::MacroCommand()
{
	commands = new std::list<Command*>;
	undone_commands = new std::list<Command*>;
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
	if (!commands->empty())
	{
		std::list<Command*>::iterator iter;
		for (iter = commands->begin(); iter != commands->end(); iter++)
		{
			(*iter)->execute();
		}
	}
}

void MacroCommand::undo()
{
	if (!commands->empty())
	{
		std::list<Command*>::iterator iter = commands->end();
		--iter;
		undone_commands->push_back(*iter);
		remove(*iter);
	}
}

void MacroCommand::redo()
{
	if (!undone_commands->empty())
	{
		std::list<Command*>::iterator iter = undone_commands->end();
		--iter;
		add(*iter);
		undone_commands->remove(*iter);
	}
}

void MacroCommand::reset()
{
	if (!commands->empty() || !undone_commands->empty())
	{
		commands->clear();
		undone_commands->clear();
	}
}
