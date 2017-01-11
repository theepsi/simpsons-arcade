#ifndef _ROYD_DAMAGED
#define _ROYD_DAMAGED

#include "state.h"

class RoydDamagedState : public State {
public:
	RoydDamagedState();
	~RoydDamagedState();
	void Update(Character& player);
};

#endif

