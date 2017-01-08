#include "core.h"
#include "character.h"
#include "marge.h"
#include "margeIdleState.h"
#include "margeWalkingState.h"
#include "margeAttack1State.h"
#include "margeJumpState.h"
#include "margeJumpAttackState.h"
#include "ModuleInput.h"

MargeIdleState::MargeIdleState()
{
}

MargeIdleState::~MargeIdleState()
{
}

void MargeIdleState::Update(Character& player)
{
	if (!(App->input->GetKey(SDL_SCANCODE_A) == KEY_REPEAT &&
			App->input->GetKey(SDL_SCANCODE_D) == KEY_REPEAT) && 
		!(App->input->GetKey(SDL_SCANCODE_S) == KEY_REPEAT &&
			App->input->GetKey(SDL_SCANCODE_W) == KEY_REPEAT)) {

		if (App->input->GetKey(SDL_SCANCODE_A) == KEY_REPEAT ||
			App->input->GetKey(SDL_SCANCODE_S) == KEY_REPEAT ||
			App->input->GetKey(SDL_SCANCODE_D) == KEY_REPEAT) {
			player.ChangeState(new MargeWalkingState, "walking");

		}
		if (App->input->GetKey(SDL_SCANCODE_W) == KEY_REPEAT) {
			player.ChangeState(new MargeWalkingState, "walking_up");
		}

		if (App->input->GetKey(SDL_SCANCODE_K) == KEY_DOWN) {
			static_cast<Marge*>(&player)->Attack(false);
		}

		if (App->input->GetKey(SDL_SCANCODE_J) == KEY_DOWN) {
			player.ChangeState(new MargeJumpState, "jump");
		}
	}
	
}
