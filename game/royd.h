#ifndef _ROYD
#define _ROYD

#include "enemy.h"

class Royd : public Enemy {
public:
	Royd();
	~Royd();

	bool Start();
};

#endif