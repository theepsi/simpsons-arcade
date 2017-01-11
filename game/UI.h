#ifndef _UI
#define _UI

#include "gameObject.h"
#include "Animation.h"
#include "state.h"
#include <map>
#include <list>
#include "ModuleFonts.h"

using namespace std;

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

	void GetContinues(int continues) {
		this->continues = continues;
	};

	void ApplyDamageToUI(int amount);

	SDL_Texture* texture;
	Animation base_UI;

	Animation* current_life_counter;

	ModuleFonts::Font* font;

	list<Animation*> life_counter_sprites;

	int continues;

};

#endif

