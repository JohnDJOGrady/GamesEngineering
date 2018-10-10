/// <summary>
/// @mainpage SDL FSM
/// @author(s) John O'Grady
/// @version 1.0
/// @brief FSM animation using the SDL library
/// </summary>

#include <Game.h>

// main game loop
int main(int argc, char * argv[])
{
	Game game = Game();

	game.run();
	return 0;
}