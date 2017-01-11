#ifndef _ROYD_ATTACK
#define _ROYD_ATTACK

#include "state.h"

class RoydAttackState : public State {
public:
	RoydAttackState();
	~RoydAttackState();
	void Update(Character& player);
};

#endif

