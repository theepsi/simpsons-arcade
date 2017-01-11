#include "core.h"
#include "marge.h"
#include "player.h"
#include "margeDeadState.h"

MargeDeadState::MargeDeadState()
{
}

MargeDeadState::~MargeDeadState()
{
}

void MargeDeadState::Update(Character & player)
{
	Animation* anim = player.GetCurrentAnimation();

	if (anim->Finished())
	{
		if (static_cast<Player*>(&player)->continues == 0) {
			player.collider->to_delete = true;
			if (player.collider_attack != nullptr)
				player.collider_attack->to_delete = true;
		}
		else {
			LOG("Resu");
			//TODO: Super Marge stuff
		}
		////player.SetEnabled(false);

		//GAME OVER?

	}
}
