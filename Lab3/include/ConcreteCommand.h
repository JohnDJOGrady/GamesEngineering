#ifndef CONCRETE_COMMANDS_H
#define CONCRETE_COMMANDS_H
#include <Command.h>

class JumpCommand : public Command
{
public:
	virtual void execute(Animation*a) { jump(a); };
	virtual void undo() {};
private:
	void jump(Animation* a) { a->jumping(); };
};

class FireCommand : public Command
{
public:
	virtual void execute(Animation*a) { fire(a); };
	virtual void undo() {};
private:
	void fire(Animation*a) { std::cout << "fire" << std::endl << std::endl; };
};

class CrouchCommand : public Command
{
public:
	virtual void execute(Animation*a) { crouch(a); };
	virtual void undo() {};
private:
	void crouch(Animation*a) { std::cout << "crouching" << std::endl << std::endl; };
};

class ShieldCommand : public Command
{
public:
	virtual void execute(Animation*a) { shield(a); };
	virtual void undo() {};
private:
	void shield(Animation* a) { std::cout << "shielding" << std::endl << std::endl; };
};

class MeleeCommand : public Command
{
public:
	virtual void execute(Animation*a) { melee(a); };
	virtual void undo() {};
private:
	void melee(Animation* a) { a->action(); };
};

#endif // !CONCRETE_COMMANDS_H
