#include "core.h"
#include "player.h"
#include "margeIdleState.h"
#include "margeWalkingState.h"
#include "ModuleInput.h"

void MargeIdleState::Update(Player& player)
{
	if (App->input->GetKey(SDL_SCANCODE_A) == KEY_DOWN ||
		App->input->GetKey(SDL_SCANCODE_D) == KEY_DOWN ||
		App->input->GetKey(SDL_SCANCODE_S) == KEY_DOWN ||
		App->input->GetKey(SDL_SCANCODE_W) == KEY_DOWN) {
		
		player.ChangeState(new MargeWalkingState, "walking");

	}
}
