#ifndef _MARGE_DEAD
#define _MARGE_DEAD

#include "state.h"

class MargeDeadState : public State {
public:
	MargeDeadState();
	~MargeDeadState();
	void Update(Character& player);
};

#endif
