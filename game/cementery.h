#ifndef _CEMENTERY
#define _CEMENTERY

#include "gameObject.h"
#include "Animation.h"

class Cementery : public GameObject {
public:
	Cementery();
	~Cementery();
	bool Start();

	void PreUpdate();

	void Update();

	void PostUpdate();

	SDL_Texture* texture;
	Animation animations;
};

#endif
