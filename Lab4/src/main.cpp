/// <summary>
/// @mainpage SDL ECS
/// @author(s) John O'Grady
/// @version 1.0
/// @brief ECS Lab - Entity Component System implementation
/// </summary>

#include <Game.h>

// main game loop
int main(int argc, char * argv[])
{
	Game game = Game();
	game.run();
	return 0;
}