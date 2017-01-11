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
	bool OnEnterCollision(Collider& source, Collider& affected);
	Player* objective = nullptr;

	Player* GetCloserPlayer();

	virtual void Attack() = 0;

	bool attacking = false;

protected:
	list<GameObject*> players_on_screen;

};

#endif
