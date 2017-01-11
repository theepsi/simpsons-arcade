#ifndef _PLAYER
#define _PLAYER

#include "character.h"
#include "UI.h"

class Player : public Character {
public:
	Player();
	virtual ~Player();
	void Update();
	void ApplySceneLimits();
	bool OnEnterCollision(Collider& source, Collider& affected);
	int continues = 0; //debug resu
	bool respawning = false;
	void AttachUI(UI* ui) {
		this->ui = ui;
	};
	UI* ui;

private:
	bool debug = false;
	bool camera_attached = true;
	bool god_mode = false;
};

#endif
