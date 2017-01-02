#ifndef _STATE
#define _STATE

class Player;

class State {
public:
	State() {}
	virtual ~State() {}
	virtual void Update(Player& player) {}
};

#endif