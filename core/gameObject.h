#ifndef _GAME_OBJECT
#define _GAME_OBJECT

#include "Point.h"

class GameObject {
public:
	GameObject() {}
	virtual ~GameObject() {}

	virtual bool Start() {
		return true;
	}

	virtual void PreUpdate() = 0;

	virtual void Update() = 0;

	virtual void PostUpdate() = 0;

	bool IsEnabled()
	{
		return enabled;
	}

	iPoint position;
private:
	//GameObject true by default
	bool enabled = true;
};

#endif
