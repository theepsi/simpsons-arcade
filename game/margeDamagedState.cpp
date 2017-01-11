#include "core.h"
#include "royd.h"
#include "player.h"
#include "margeDamagedState.h"
#include "margeDeadState.h"
#include "margeIdleState.h"

MargeDamagedState::MargeDamagedState()
{
}

MargeDamagedState::~MargeDamagedState()
{
}

void MargeDamagedState::Update(Character& player)
{
	if (player.position.y <= 0) {
		player.position.y += 4;
		if (player.position.y >= 0) {
			player.position.y = 0;
		}
	}
	Animation* anim = player.GetCurrentAnimation();

	if (anim->Finished())
	{
		if (!player.recovering) {
			if (player.life > 0) {
				player.SetCurrentAnimation("recover");
				player.recovering = true;
			}
			else {
				if (static_cast<Player*>(&player)->continues == 0) {
					player.ChangeState(new MargeDeadState, "dead");
				}
				else {
					static_cast<Player*>(&player)->continues -= 1;
					player.ChangeState(new MargeDeadState, "dizzy");
				}
			}

		}
		else {
			player.damaged = false;
			player.recovering = false;
			player.ChangeState(new MargeIdleState, "idle");
		}
	}
}
