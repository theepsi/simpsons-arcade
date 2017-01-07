#ifndef _ENEMY
#define _ENEMY

#include "character.h"

class Enemy : public Character {
public:
	Enemy();
	virtual ~Enemy();
	float speed = 1.f;
	float jump_speed = 5.f;
	bool Start() = 0;
	void Update();
};

#endif
