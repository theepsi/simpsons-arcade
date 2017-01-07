#ifndef _ENEMY
#define _ENEMY

#include "character.h"
#include <list>

class Player;

using namespace std;

class Enemy : public Character {
public:
	Enemy();
	virtual ~Enemy();
	float speed = 1.f;
	float jump_speed = 5.f;
	bool Start() = 0;
	void Update();
	Player* objective;

protected:
	list<Player*> players_on_screen;

};

#endif
