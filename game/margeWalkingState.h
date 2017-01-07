#ifndef _MARGE_WALKING
#define _MARGE_WALKING

#include "state.h"

class MargeWalkingState : public State {
public:
	MargeWalkingState();
	~MargeWalkingState();
	void Update(Character& player);
};

#endif
