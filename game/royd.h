#ifndef _ROYD
#define _ROYD

#define MIN_DISTANCE 30

#include "enemy.h"
#include "roydAttackState.h"

class Royd : public Enemy {
public:
	Royd();
	~Royd();

	bool Start();
	void RecieveDamage(int amount);
	void Attack() {
		if (!attacking) {
			after_attack = true;
			attacking = true;
			int attack = 1 + (rand() % (int)(2 - 1 + 1));
			//TODO: decide wich attack do 1 or 2
			if (attack==1)
				ChangeState(new RoydAttackState, "attack_1");
			else
				ChangeState(new RoydAttackState, "attack_2");
		}
	}
};

#endif