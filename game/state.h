#ifndef _STATE
#define _STATE

class Character;

class State {
public:
	State() {}
	virtual ~State() {}
	virtual void Update(Character& player) {}
};

#endif