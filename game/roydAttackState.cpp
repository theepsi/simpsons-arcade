#include "core.h"
#include "royd.h"
#include "player.h"
#include "enemy.h"
#include "roydWalkingState.h"
#include "roydDamagedState.h"
#include "roydDeadState.h"
#include "roydAttackState.h"

RoydAttackState::RoydAttackState()
{
}

RoydAttackState::~RoydAttackState()
{
}

void RoydAttackState::Update(Character& player)
{
	if (player.collider_attack == nullptr) {
		SDL_Rect coll_rect = { 0,0,0,0 };
		if (player.flipped)
			coll_rect = { player.position.x + player.x_offset - 25, player.position.y + player.y_offset, 25, 25 };
		else
			coll_rect = { player.position.x + player.x_offset + player.collider->rect.w, player.position.y + player.y_offset, 25, 25 };
		player.collider_attack = App->collision->AddCollider(coll_rect, player.position.z, &player, CollisionAgainst::ENEMY_ATTACK_COLISION);
	}

	Enemy* enemy = static_cast<Enemy*>(&player);

	Animation* anim = player.GetCurrentAnimation();

	if (anim->Finished())
	{
		if (player.collider_attack != nullptr) {
			player.collider_attack->to_delete = true;
			player.collider_attack = nullptr;
		}
		enemy->attacking = false;
		player.ChangeState(new RoydWalkingState, "walking");
	}
}
