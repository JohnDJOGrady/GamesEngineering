#ifndef FACTORY_H
#define FACTORY_H

#include "Character.h"

class Factory
{
public:
	virtual Character* CreatePlayer() = 0;
	virtual Character* CreateEnemies() = 0;
};

#endif // !FACTORY_H

#ifndef CHARACTERFACTORY_H
#define CHARACTERFACTORY_H

class CharacterFactory : public Factory
{
public:
	Character * CreatePlayer()
	{
		return new Player;
	}
	Character* CreateEnemies()
	{
		return new Boss;
	}
};

#endif // !CHARACTERFACTORY_H
#pragma once
