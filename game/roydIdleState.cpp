#include "core.h"
#include "royd.h"
#include "player.h"
#include "enemy.h"
#include "roydIdleState.h"
#include "roydWalkingState.h"

RoydIdleState::RoydIdleState()
{
}

RoydIdleState::~RoydIdleState()
{
}

void RoydIdleState::Update(Character& player)
{
	Enemy* enemy = static_cast<Enemy*>(&player);
	Player* enemy_objective = enemy->objective;

	if (enemy->position.x > enemy_objective->position.x) {
		enemy->flipped = true;
	}
	else {
		enemy->flipped = false;
	}
	
	if (enemy->position.z > enemy_objective->position.z) {
		enemy->ChangeState(new RoydWalkingState, "walking_up");
	}
	if (enemy->position.z < enemy_objective->position.z) {
		enemy->ChangeState(new RoydWalkingState, "walking_down");
	}
	if (enemy->position.z == enemy_objective->position.z) {
		
		if (enemy->position.x > enemy_objective->position.x + MIN_DISTANCE ||
			enemy->position.x < enemy_objective->position.x - MIN_DISTANCE) {

			enemy->ChangeState(new RoydWalkingState, "walking");
		}
	}
}
