#ifndef _UI
#define _UI

#include "gameObject.h"
#include "Animation.h"
#include "state.h"
#include <map>
#include "ModuleFonts.h"

class ModuleFonts;

struct SDL_Texture;
class State;
struct Collider;

class UI : public GameObject {
public:
	UI();
	~UI();
	bool Start();

	void PreUpdate();

	void Update();

	void PostUpdate();

	bool CleanUp();

	//No need to implement collisions on UI
	bool OnEnterCollision(Collider& source, Collider& affected) { return false; };

	SDL_Texture* texture;
	Animation animation;

};

#endif

