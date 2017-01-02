#ifndef _MARGE_WALKING
#define _MARGE_WALKING

#include "state.h"

class MargeWalkingState : public State {
public:
	MargeWalkingState() {}
	void Update(Player& player);
};

#endif
