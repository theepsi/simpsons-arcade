#include "core.h"
#include "player.h"
#include "margeIdleState.h"
#include "margeWalkingState.h"
#include "margeAttack1State.h"
#include "margeJumpState.h"
#include "ModuleInput.h"


MargeJumpState::MargeJumpState()
{
	going_up = true;
}

MargeJumpState::~MargeJumpState()
{
}

void MargeJumpState::Update(Character& player)
{
	if (App->input->GetKey(SDL_SCANCODE_W) == KEY_REPEAT)
	{
		player.position.z -= (int)player.speed;
	}

	if (App->input->GetKey(SDL_SCANCODE_A) == KEY_REPEAT)
	{
		player.flipped = true;
		player.position.x -= (int)player.speed;
	}

	if (App->input->GetKey(SDL_SCANCODE_D) == KEY_REPEAT)
	{
		player.flipped = false;
		player.position.x += (int)player.speed;
	}

	if (App->input->GetKey(SDL_SCANCODE_S) == KEY_REPEAT)
	{
		player.position.z += (int)player.speed;
	}

	if (going_up) {
		player.position.y -= (int)player.jump_speed;
		if (player.position.y < -100) {
			going_up = false;
		}
	}
	else {
		if (player.position.y >= 0) {
			player.position.y = 0;
			player.ChangeState(new MargeIdleState, "idle");
		}
		else {
			player.SetCurrentAnimation("fall");
			player.position.y += 4;
		}	
	}
	

}
