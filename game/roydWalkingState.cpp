#include "core.h"
#include "royd.h"
#include "player.h"
#include "enemy.h"
#include "roydIdleState.h"
#include "roydWalkingState.h"

using namespace std;

RoydWalkingState::RoydWalkingState()
{
}

RoydWalkingState::~RoydWalkingState()
{
}

void RoydWalkingState::Update(Character& player)
{
	Enemy* enemy = static_cast<Enemy*>(&player);
	Player* enemy_objective = enemy->objective;

	enemy->attacking = false;

	if (!enemy->after_attack) {
		if (enemy->position.x < enemy_objective->position.x + MIN_DISTANCE &&
			enemy->position.x > enemy_objective->position.x - MIN_DISTANCE) {
			if (enemy->flipped)
				enemy->position.x -= (int)enemy->speed;
			else
				enemy->position.x += (int)enemy->speed;
		}
		else {
			if (enemy->position.x >= enemy_objective->position.x) {
				if (enemy->position.x == enemy_objective->position.x + MIN_DISTANCE) {
					if (enemy->position.z == enemy_objective->position.z)
						enemy->ChangeState(new RoydIdleState, "idle");
				}
				else {
					enemy->flipped = true;
					enemy->position.x -= (int)enemy->speed;
				}
			}
			else if (enemy->position.x <= enemy_objective->position.x) {
				if (enemy->position.x == enemy_objective->position.x - MIN_DISTANCE) {
					if (enemy->position.z == enemy_objective->position.z)
						enemy->ChangeState(new RoydIdleState, "idle");
				}
				else {
					enemy->flipped = false;
					enemy->position.x += (int)enemy->speed;
				}
			}
		}

		if (enemy->position.z > enemy_objective->position.z) {
			if (enemy->CheckCurrentAnimation("walking") || enemy->CheckCurrentAnimation("walking_down"))
				enemy->SetCurrentAnimation("walking_up");
			enemy->position.z -= (int)enemy->speed;
		}
		if (enemy->position.z < enemy_objective->position.z) {
			if (enemy->CheckCurrentAnimation("walking_up") || enemy->CheckCurrentAnimation("walking"))
				enemy->SetCurrentAnimation("walking_down");
			enemy->position.z += (int)enemy->speed;
		}
		if (enemy->position.z == enemy_objective->position.z) {
			if (enemy->CheckCurrentAnimation("walking_up") || enemy->CheckCurrentAnimation("walking_down"))
				enemy->SetCurrentAnimation("walking");
		}
	}
	else {
		if (enemy->random_moves_counter <= enemy->random_moves) {
			//Do random movements
			if (enemy->position.x > enemy_objective->position.x) {
				enemy->flipped = false;
				enemy->position.x += (int)enemy->speed;
			}
			else if (enemy->position.x < enemy_objective->position.x) {
				enemy->flipped = true;
				enemy->position.x -= (int)enemy->speed;
			}
			
			++enemy->random_moves_counter;
		}
		else {
			enemy->random_moves_counter = 0;
			enemy->after_attack = false;
		}
	}
}
