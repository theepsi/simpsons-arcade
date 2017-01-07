#ifndef _CHARACTER
#define _CHARACTER

#include "gameObject.h"
#include "Animation.h"
#include "state.h"
#include <map>

struct SDL_Texture;
class State;

class Character : public GameObject {
public:
	Character();
	virtual ~Character();

	float speed = 1.f;
	float jump_speed = 0.f;
	bool Start() = 0;
	void PreUpdate();
	void Update();
	void PostUpdate();
	void CleanUp();
	bool flipped = false;

	Animation* GetCurrentAnimation() {
		return &current_animation;
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
		RELEASE(state);
		SetCurrentAnimation(anim);
		state = next_state;
	}

protected:
	map<string, Animation> animations;
	Animation current_animation;
	State* state = nullptr;
	SDL_Texture* texture;
};

#endif
