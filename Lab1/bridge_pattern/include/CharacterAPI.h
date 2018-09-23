#ifndef CHARACTERAPI_H
#define CHARACTERAPI_H

class CharacterAPI
{
public:
	virtual void Draw() = 0;
};

#endif // !CHARACTERAPI_H

#ifndef PLAYER_H
#define PLAYER_H

#include "API.h"

class Player : public CharacterAPI
{
	// refinement of the bridge pattern
public:
	Player(DrawAPI* api){ this->api = api; };
	void Draw() { api->Draw(); };
private:
	DrawAPI* api;
};

#endif // !PLAYER_H
