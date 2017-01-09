#ifndef _PLAYER
#define _PLAYER

#include "character.h"

class Player : public Character {
public:
	Player();
	virtual ~Player();
	bool Start() = 0;
	void Update();
	void ApplySceneLimits();
	bool OnEnterCollision(Collider& source, Collider& affected);

private:
	bool debug = false;
};

#endif
