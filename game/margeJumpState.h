#ifndef _MARGE_JUMP
#define _MARGE_JUMP

#include "state.h"

class MargeJumpState : public State {
public:
	MargeJumpState();
	~MargeJumpState();
	void Update(Player& player);

	bool going_up;
};

#endif
