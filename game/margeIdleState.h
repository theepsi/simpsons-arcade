#ifndef _MARGE_IDLE
#define _MARGE_IDLE

#include "state.h"

class MargeIdleState : public State {
public:
	MargeIdleState();
	~MargeIdleState();
	void Update(Character& player);
};

#endif
