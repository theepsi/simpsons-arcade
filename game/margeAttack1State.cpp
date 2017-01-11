#include "core.h"
#include "character.h"
#include "marge.h"
#include "margeIdleState.h"
#include "margeWalkingState.h"
#include "margeAttack1State.h"
#include "ModuleInput.h"

MargeAttack1State::MargeAttack1State()
{
	//LOG("new attack");
}

MargeAttack1State::~MargeAttack1State()
{
	//LOG("exit attack");
}

void MargeAttack1State::Update(Character& player)
{
	if (player.collider_attack == nullptr) {
		SDL_Rect coll_rect = { 0,0,0,0 };
		if (player.flipped)
			coll_rect = { player.position.x + player.x_offset - 25, player.position.y + player.y_offset, 25, 25 };
		else
			coll_rect = { player.position.x + player.x_offset + player.collider->rect.w, player.position.y + player.y_offset, 25, 25 };
		player.collider_attack = App->collision->AddCollider(coll_rect, player.position.z, &player, CollisionAgainst::PLAYER_ATTACK_COLISION);
	}
	
	if (App->input->GetKey(SDL_SCANCODE_A) == KEY_DOWN ||
		App->input->GetKey(SDL_SCANCODE_D) == KEY_DOWN ||
		App->input->GetKey(SDL_SCANCODE_S) == KEY_DOWN) {

		if (player.collider_attack != nullptr) {
			player.collider_attack->to_delete = true;
			player.collider_attack = nullptr;
		}
		player.ChangeState(new MargeWalkingState, "walking");

	}
	if (App->input->GetKey(SDL_SCANCODE_W) == KEY_DOWN) {

		if (player.collider_attack != nullptr) {
			player.collider_attack->to_delete = true;
			player.collider_attack = nullptr;
		}
		player.ChangeState(new MargeWalkingState, "walking_up");
	}
	
	Animation* anim = player.GetCurrentAnimation();

	float last_frame = (float)anim->frames.size();
	if (anim->Finished())
	{
		if (player.collider_attack != nullptr) {
			player.collider_attack->to_delete = true;
			player.collider_attack = nullptr;
		}
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
