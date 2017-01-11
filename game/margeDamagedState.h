#ifndef _MARGE_DAMAGED
#define _MARGE_DAMAGED

#include "state.h"

class MargeDamagedState : public State {
public:
	MargeDamagedState();
	~MargeDamagedState();
	void Update(Character& player);
};

#endif
