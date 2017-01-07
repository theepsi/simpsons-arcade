#ifndef _ROYD_IDLE
#define _ROYD_IDLE

#include "state.h"

class RoydIdleState : public State {
public:
	RoydIdleState();
	~RoydIdleState();
	void Update(Character& player);
};

#endif
