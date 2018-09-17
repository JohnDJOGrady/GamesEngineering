#include <iostream>

#ifndef CHARACTER_H
#define CHARACTER_H

class Character
{
public:
	Character() {};
	virtual ~Character() {};
	virtual void draw() = 0;
};

#endif // !CHARACTER_H

#ifndef PLAYER_H
#define PLAYER_H

class Player : public Character
{
public:
	void draw()
	{
		std::cout << "---Draw Player---" << std::endl;
	}
};

#endif // !PLAYER_H


#ifndef BOSS_H
#define BOSS_H

class Boss : public Character
{
public:
	void draw()
	{
		std::cout << "+++Draw Boss+++" << std::endl;
	}
};

#endif // !BOSS_H

