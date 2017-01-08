#ifndef _MARGE
#define _MARGE

#include "player.h"
#include "margeAttack1State.h"

class Marge : public Player {
public:
	Marge();
	~Marge();

	bool Start();

	int attack_counter = 0;

	void Attack() {
		if (attack_counter < 2) {
			ChangeState(new MargeAttack1State, "attack_1");
			attack_counter += 1;
		}
		else {
			ChangeState(new MargeAttack1State, "attack_2");
			attack_counter = 0;
		}
	}
};

#endif
