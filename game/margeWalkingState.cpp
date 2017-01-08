#include "core.h"
#include "player.h"
#include "margeIdleState.h"
#include "margeWalkingState.h"
#include "margeAttack1State.h"
#include "ModuleInput.h"
#include "margeJumpState.h"

MargeWalkingState::MargeWalkingState()
{
}

MargeWalkingState::~MargeWalkingState()
{
}

void MargeWalkingState::Update(Character& player)
{
	if (App->input->GetKey(SDL_SCANCODE_A) == KEY_IDLE &&
		App->input->GetKey(SDL_SCANCODE_D) == KEY_IDLE &&
		App->input->GetKey(SDL_SCANCODE_S) == KEY_IDLE &&
		App->input->GetKey(SDL_SCANCODE_W) == KEY_IDLE) {

		player.ChangeState(new MargeIdleState, "idle");

	}

	if (App->input->GetKey(SDL_SCANCODE_K) == KEY_DOWN) {
		player.ChangeState(new MargeAttack1State, "attack_1");
	}

	if (App->input->GetKey(SDL_SCANCODE_J) == KEY_DOWN) {
		player.ChangeState(new MargeJumpState, "jump");
	}

	if (App->input->GetKey(SDL_SCANCODE_W) == KEY_DOWN) {
		player.SetCurrentAnimation("walking_up");
	}

	if (App->input->GetKey(SDL_SCANCODE_W) == KEY_UP) {
		player.SetCurrentAnimation("walking");
	}

	if (App->input->GetKey(SDL_SCANCODE_W) == KEY_REPEAT)
	{
		if (App->input->GetKey(SDL_SCANCODE_S) == KEY_REPEAT)
			player.ChangeState(new MargeIdleState, "idle");
		else
			player.position.z -= (int)player.speed;
	}
	else if (App->input->GetKey(SDL_SCANCODE_S) == KEY_REPEAT)
	{
		player.position.z += (int)player.speed;
	}

	if (App->input->GetKey(SDL_SCANCODE_D) == KEY_REPEAT)
	{
		if (App->input->GetKey(SDL_SCANCODE_A) == KEY_REPEAT)
			player.ChangeState(new MargeIdleState, "idle");
		else {
			player.flipped = false;
			player.position.x += (int)player.speed;
		}
	}
	else if(App->input->GetKey(SDL_SCANCODE_A) == KEY_REPEAT)
	{
		player.flipped = true;
		player.position.x -= (int)player.speed;
	}

	
	
}
