#ifndef _PLAYER
#define _PLAYER

#include "gameObject.h"
#include "Animation.h"
#include <map>

struct SDL_Texture;
class State;

class Player : public GameObject {
public:
	Player();
	virtual ~Player();
	
	float speed = 1.f;
	bool Start() = 0;
	void PreUpdate();
	void Update();
	void PostUpdate();
	bool flipped = false;
	
	Animation GetCurrentAnimation() {
		return current_animation;
	}

	void SetCurrentAnimation(const string& name) {
		auto it = animations.find(name);
		if (it != animations.end())
			current_animation = it->second;
	}

	void AddAnimation(const string& name, const Animation& anim) {
		animations[name] = anim;
	}

	void ChangeState(State* next_state, const string& anim) {
		//RELEASE(state);
		SetCurrentAnimation(anim);
		state = next_state;
	}

private:
	map<string, Animation> animations;
	Animation current_animation;
	State* state;

protected:
	SDL_Texture* texture;

	
};

#endif
