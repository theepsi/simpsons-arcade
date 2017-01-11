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

	float last_frame = (float)anim->frames.size();
	if (anim->Finished())
	{
		//TODO:clean attack collider¿?
		player.collider->to_delete = true;
		player.SetEnabled(false);
	}
}
