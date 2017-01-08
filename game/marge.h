#ifndef _MARGE
#define _MARGE

#include "player.h"
#include "margeAttack1State.h"
#include "margeJumpAttackState.h"

class Marge : public Player {
public:
	Marge();
	~Marge();

	bool Start();

	int attack_counter = 0;

	void Attack(bool jumping) {
		if (attack_counter < 2) {
			if (jumping)
				ChangeState(new MargeJumpAttackState, "jump_attack_1");
			else
				ChangeState(new MargeAttack1State, "attack_1");
			attack_counter += 1;
		}
		else {
			if (jumping)
				ChangeState(new MargeJumpAttackState, "jump_attack_2");
			else
				ChangeState(new MargeAttack1State, "attack_2");
			attack_counter = 0;
		}
	}
};

#endif
