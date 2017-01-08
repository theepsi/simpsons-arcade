#ifndef _ROYD_WALKING
#define _ROYD_WALKING

#include "state.h"

class RoydWalkingState : public State {
public:
	RoydWalkingState();
	~RoydWalkingState();
	void Update(Character& player);
};

#endif

