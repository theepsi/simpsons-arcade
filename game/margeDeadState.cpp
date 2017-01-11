#include "core.h"
#include "marge.h"
#include "player.h"
#include "margeDeadState.h"
#include "ModuleRender.h"
#include "margeIdleState.h"

MargeDeadState::MargeDeadState()
{
}

MargeDeadState::~MargeDeadState()
{
}

void MargeDeadState::Update(Character & player)
{
	Animation* anim = player.GetCurrentAnimation();

	Player* marge = static_cast<Player*>(&player);
	if (anim->name == "resu_arrive") {
		player.position.x += 2;
		if (player.position.x > abs(App->renderer->camera.x) / SCREEN_SIZE + 50) {
			player.SetCurrentAnimation("resu_fall");
		}
	}
	else if (anim->name == "resu_fall") {
		player.position.y += 2;
		if (player.position.y >= 0) {
			player.position.y = 0;
			marge->respawning = 150;
			player.life = 4;
			player.damaged = false;
			player.ChangeState(new MargeIdleState, "idle");
		}
	}
	else {
		if (anim->Finished() && anim->name != "dead")
		{
			if (player.CheckCurrentAnimation("dead")) {
				player.collider->to_delete = true;
				if (player.collider_attack != nullptr)
					player.collider_attack->to_delete = true;
			}
			else {
				player.flipped = false;
				player.SetCurrentAnimation("resu_arrive");
				player.position.x = abs(App->renderer->camera.x) / SCREEN_SIZE - 100;
				player.position.y = -80;
				player.position.z = 110;
			}

			//TODO:GAME OVER?
		}
	}
}
