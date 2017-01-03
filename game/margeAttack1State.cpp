#include "core.h"
#include "player.h"
#include "margeIdleState.h"
#include "margeWalkingState.h"
#include "margeAttack1State.h"
#include "ModuleInput.h"

MargeAttack1State::MargeAttack1State()
{
}

MargeAttack1State::~MargeAttack1State()
{
}

void MargeAttack1State::Update(Player& player)
{
	if (App->input->GetKey(SDL_SCANCODE_A) == KEY_DOWN ||
		App->input->GetKey(SDL_SCANCODE_D) == KEY_DOWN ||
		App->input->GetKey(SDL_SCANCODE_S) == KEY_DOWN) {

		player.ChangeState(new MargeWalkingState, "walking");

	}
	if (App->input->GetKey(SDL_SCANCODE_W) == KEY_DOWN) {
		player.ChangeState(new MargeWalkingState, "walking_up");
	}
	
	Animation* anim = player.GetCurrentAnimation();

	float last_frame = (float)anim->frames.size();
	if (anim->Finished())
	{

		if (App->input->GetKey(SDL_SCANCODE_A) == KEY_REPEAT ||
			App->input->GetKey(SDL_SCANCODE_D) == KEY_REPEAT ||
			App->input->GetKey(SDL_SCANCODE_S) == KEY_REPEAT) {

			player.ChangeState(new MargeWalkingState, "walking");

		}
		else if (App->input->GetKey(SDL_SCANCODE_W) == KEY_REPEAT) {
			player.ChangeState(new MargeWalkingState, "walking_up");
		}
		else {
			player.ChangeState(new MargeIdleState, "idle");
		}
	}
	
}
