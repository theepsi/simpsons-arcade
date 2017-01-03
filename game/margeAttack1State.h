#ifndef _MARGE_ATTACK_1
#define _MARGE_ATTACK_1

#include "state.h"

class MargeAttack1State : public State {
public:
	MargeAttack1State();
	~MargeAttack1State();
	void Update(Player& player);
};

#endif
