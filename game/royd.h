#ifndef _ROYD
#define _ROYD

#define MIN_DISTANCE 30

#include "enemy.h"

class Royd : public Enemy {
public:
	Royd();
	~Royd();

	bool Start();
};

#endif