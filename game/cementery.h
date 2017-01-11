#ifndef _CEMENTERY
#define _CEMENTERY

#include "gameObject.h"
#include "Animation.h"
#include <list>

using namespace std;

struct SDL_Texture;
struct SDL_Rect;

class Cementery : public GameObject {
public:
	Cementery();
	~Cementery();
	bool Start();

	void PreUpdate();

	void Update();

	void PostUpdate();

	bool CleanUp();

	//TODO: no need to implement collisions on Cementery for now
	bool OnEnterCollision(Collider& source, Collider& affected) { return false; };

	SDL_Texture* texture;
	list<Animation*> background_animations;
	list<Animation*> foreground_animations;
	SDL_Rect* section = new SDL_Rect({ 0, 0, 2304, 252 });
};

#endif
