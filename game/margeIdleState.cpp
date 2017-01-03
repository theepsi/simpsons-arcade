#include "core.h"
#include "player.h"
#include "margeIdleState.h"
#include "margeWalkingState.h"
#include "margeAttack1State.h"
#include "ModuleInput.h"

MargeIdleState::MargeIdleState()
{
}

MargeIdleState::~MargeIdleState()
{
}

void MargeIdleState::Update(Player& player)
{
	if (App->input->GetKey(SDL_SCANCODE_A) == KEY_REPEAT ||
		App->input->GetKey(SDL_SCANCODE_S) == KEY_REPEAT ||
		App->input->GetKey(SDL_SCANCODE_D) == KEY_REPEAT) {
		
		player.ChangeState(new MargeWalkingState, "walking");

	}
	if (App->input->GetKey(SDL_SCANCODE_W) == KEY_REPEAT) {
		player.ChangeState(new MargeWalkingState, "walking_up");
	}

	if (App->input->GetKey(SDL_SCANCODE_K) == KEY_DOWN) {
		player.ChangeState(new MargeAttack1State, "attack_1");
	}
}
