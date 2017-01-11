#include "core.h"
#include "character.h"
#include "marge.h"
#include "margeIdleState.h"
#include "margeJumpAttackState.h"

MargeJumpAttackState::MargeJumpAttackState()
{
}

MargeJumpAttackState::~MargeJumpAttackState()
{
}

void MargeJumpAttackState::Update(Character& player)
{
	if (player.collider_attack == nullptr) {
		SDL_Rect coll_rect = { 0,0,0,0 };
		if (player.flipped)
			coll_rect = { player.position.x + player.x_offset - 25, player.position.y + player.y_offset + 30, 25, 25 };
		else
			coll_rect = { player.position.x + player.x_offset + player.collider->rect.w, player.position.y + player.y_offset + 30, 25, 25 };
		player.collider_attack = App->collision->AddCollider(coll_rect, player.position.z, &player, CollisionAgainst::PLAYER_ATTACK_COLISION);
	}
	if (player.position.y >= 0) {
		player.position.y = 0;
		if (player.collider_attack != nullptr) {
			player.collider_attack->to_delete = true;
			player.collider_attack = nullptr;
		}
		player.ChangeState(new MargeIdleState, "idle");
	}
	else {
		if (player.flipped)
			player.position.x -= 5;
		else
			player.position.x += 5;
		player.position.y += 5;
		if (player.collider_attack != nullptr) {
			player.collider_attack->position_z = player.position.z;
			player.collider_attack->rect.x = player.position.x + player.x_offset;
			player.collider_attack->rect.y = player.position.y + player.y_offset + 30;
		}
	}
}
