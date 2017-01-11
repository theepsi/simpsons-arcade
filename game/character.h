#ifndef _CHARACTER
#define _CHARACTER

#include "gameObject.h"
#include "Animation.h"
#include "state.h"
#include <map>
#include "ModuleFonts.h"

class ModuleFonts;

struct SDL_Texture;
class State;
struct Collider;

class Character : public GameObject {
public:
	Character();
	virtual ~Character();

	float speed = 1.f;
	float jump_speed = 0.f;
	bool Start();
	void PreUpdate();
	void Update();
	void PostUpdate();
	bool CleanUp();
	bool flipped = false;

	int x_offset, y_offset;

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
	
	bool CheckCurrentAnimation(const string& name) {
		if (current_animation.name == name) {
			return true;
		}
		return false;
	}

	void UpdateColliderPosition() {
		if (collider != nullptr) {
			collider->position_z = position.z;
			collider->rect.x = position.x + x_offset;
			collider->rect.y = position.y + y_offset;
		}		
	}

	Collider* collider = nullptr;
	Collider* collider_attack = nullptr;
	ModuleFonts::Font* font = nullptr;

	virtual void RecieveDamage(int amount) = 0;

	bool damaged = false;
	bool recovering = false;
	int life = 2;
	unsigned int hit_fx;

protected:
	map<string, Animation> animations;
	Animation current_animation;
	State* state = nullptr;
	SDL_Texture* texture;
};

#endif
