#include "core.h"
#include "player.h"
#include "margeIdleState.h"
#include "margeWalkingState.h"
#include "ModuleInput.h"

void MargeWalkingState::Update(Player & player)
{
	if (App->input->GetKey(SDL_SCANCODE_A) == KEY_IDLE &&
		App->input->GetKey(SDL_SCANCODE_D) == KEY_IDLE &&
		App->input->GetKey(SDL_SCANCODE_S) == KEY_IDLE &&
		App->input->GetKey(SDL_SCANCODE_W) == KEY_IDLE) {

		player.ChangeState(new MargeIdleState, "idle");

	}

	if (App->input->GetKey(SDL_SCANCODE_A) == KEY_REPEAT)
	{
		player.position.x -= player.speed;
	}

	if (App->input->GetKey(SDL_SCANCODE_D) == KEY_REPEAT)
	{
		player.position.x += player.speed;
	}

	if (App->input->GetKey(SDL_SCANCODE_S) == KEY_REPEAT)
	{
		player.position.y += player.speed;
	}

	if (App->input->GetKey(SDL_SCANCODE_W) == KEY_REPEAT)
	{
		player.position.y -= player.speed;
	}
}
