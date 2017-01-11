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
	void Update();
	bool OnEnterCollision(Collider& source, Collider& affected);
	Player* objective = nullptr;

	Player* GetCloserPlayer();

	virtual void Attack() = 0;

	bool attacking = false;

	bool after_attack = false;

	int random_moves_counter = 0;
	int random_moves = 50;

protected:
	list<GameObject*> players_on_screen;

};

#endif
