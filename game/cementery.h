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
	SDL_Rect* section = new SDL_Rect({ 4, 262, 2304, 256 });
};

#endif
