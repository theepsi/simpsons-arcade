#ifndef _MARGE_JUMP_ATTACK
#define _MARGE_JUMP_ATTACK

#include "state.h"

class MargeJumpAttackState : public State {
public:
	MargeJumpAttackState();
	~MargeJumpAttackState();
	void Update(Character& player);
};

#endif
