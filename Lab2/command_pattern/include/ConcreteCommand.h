#ifndef CONCRETE_COMMANDS_H
#define CONCRETE_COMMANDS_H
#include "Command.h"

class JumpCommand : public Command
{
public:
	virtual void execute() { jump(); };
private:
	void jump() { std::cout << "jumping" << std::endl << std::endl; };
};

class FireCommand : public Command
{
public:
	virtual void execute() { fire(); };
private:
	void fire() { std::cout << "fire" << std::endl << std::endl; };
};

class CrouchCommand : public Command
{
public:
	virtual void execute() { crouch(); };
private:
	void crouch() { std::cout << "crouching" << std::endl << std::endl; };
};

class ShieldCommand : public Command
{
public:
	virtual void execute() { shield(); };
private:
	void shield() { std::cout << "shielding" << std::endl << std::endl; };
};

class MeleeCommand : public Command
{
public:
	virtual void execute() { melee(); };
private:
	void melee() { std::cout << "throwing shapes" << std::endl << std::endl; };
};

#endif // !CONCRETE_COMMANDS_H
