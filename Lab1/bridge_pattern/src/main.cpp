/// <summary>
/// @mainpage Handle Bridge Pattern, "Chesire Cat" Pattern
/// @author(s) John O'Grady
/// @version 1.0
/// @brief implementation and demonstration of Bridge Pattern algorithim
/// </summary>

#include <iostream>
#include "Character.h"
#include "API.h"
#include "CharacterAPI.h"

int main()
{
	HandleToCharacter handle;
	handle -> Print();

	std::cout << std::endl << "-------------------" << std::endl << std::endl;

	DrawAPI* api = new DrawImpl();
	CharacterAPI* character = new Player(api);
	character->Draw();

	std::cin.get();
	return 1;
}