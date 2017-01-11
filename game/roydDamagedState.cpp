#include "core.h"
#include "royd.h"
#include "player.h"
#include "enemy.h"
#include "roydIdleState.h"
#include "roydDamagedState.h"
#include "roydDeadState.h"

RoydDamagedState::RoydDamagedState()
{
}

RoydDamagedState::~RoydDamagedState()
{
}

void RoydDamagedState::Update(Character& player)
{
	Enemy* enemy = static_cast<Enemy*>(&player);
	enemy->attacking = false;

	Animation* anim = player.GetCurrentAnimation();

	if (anim->Finished())
	{
		if (!player.recovering) {
			if (player.life > 0) {
				player.SetCurrentAnimation("recover");
				player.recovering = true;
			}
			else {
				player.ChangeState(new RoydDeadState, "dead");
			}
			
		}
		else {
			player.damaged = false;
			player.recovering = false;
			player.ChangeState(new RoydIdleState, "idle");
		}
	}
}
