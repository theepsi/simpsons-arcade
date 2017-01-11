#ifndef _MARGE
#define _MARGE

#include "player.h"

class Marge : public Player {
public:
	Marge();
	~Marge();

	bool Start();

	int attack_counter = 0;

	void RecieveDamage(int amount);

	void Attack(bool jumping);
};

#endif
