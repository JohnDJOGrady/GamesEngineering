/// <summary>
/// @mainpage AbstractFactory
/// @authors John O'Grady
/// @brief
/// @version 1.0
/// </summary>

#include <iostream>
#include <vector>
#include "Factory.h"

int main()
{
	Factory* factory = new CharacterFactory();
	std::vector<Character*> characters;
	characters.push_back(factory->CreatePlayer());
	characters.push_back(factory->CreateEnemies());

	for (int i = 0; i < characters.size(); i++)
	{
		characters[i]->draw();
	}

	system("pause");
}