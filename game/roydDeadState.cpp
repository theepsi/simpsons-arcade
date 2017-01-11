#include "core.h"
#include "royd.h"
#include "player.h"
#include "enemy.h"
#include "roydDeadState.h"

RoydDeadState::RoydDeadState()
{
}

RoydDeadState::~RoydDeadState()
{
}

void RoydDeadState::Update(Character& player)
{
	Animation* anim = player.GetCurrentAnimation();

	if (anim->Finished())
	{
		player.collider->to_delete = true;
		if (player.collider_attack != nullptr)
			player.collider_attack->to_delete = true;
		player.SetEnabled(false);
	}
}
