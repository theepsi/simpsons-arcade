#ifndef _ROYD_DEAD
#define _ROYD_DEAD

#include "state.h"

class RoydDeadState : public State {
public:
	RoydDeadState();
	~RoydDeadState();
	void Update(Character& player);
};

#endif
