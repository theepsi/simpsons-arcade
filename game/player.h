#ifndef _PLAYER
#define _PLAYER

#include "character.h"

class Player : public Character {
public:
	Player();
	virtual ~Player();
	bool Start() = 0;
	void Update();
};

#endif
