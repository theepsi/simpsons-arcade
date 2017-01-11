#include "core.h"
#include "enemy.h"
#include "ModuleRender.h"
#include "ModuleSceneManager.h"
#include "state.h"

Enemy::Enemy()
{
	type = GameObjectType::ENEMY_ENTITY;
}

Enemy::~Enemy()
{
}

void Enemy::Update()
{
	SDL_Rect* current_frame = &current_animation.GetCurrentFrame();

	players_on_screen = App->scene_manager->GetPlayersAvailable();

	objective = GetCloserPlayer();

	App->renderer->PriorityBlit3D(texture, position.x, position.y, position.z, current_frame, 1.f, flipped);

	state->Update(*this);
}

bool Enemy::OnEnterCollision(Collider& source, Collider& affected)
{
	if (affected.col_against == CollisionAgainst::PLAYER_ATTACK_COLISION) {
		//TODO: calculate damage
		RecieveDamage(1);
	}
	if (affected.col_against == CollisionAgainst::PLAYER_COLLISION) {
		if (!damaged)
			Attack();		
	}
	return true;
}


Player * Enemy::GetCloserPlayer()
{
	for (list<GameObject*>::iterator it = players_on_screen.begin(); it != players_on_screen.end(); ++it) {
		//TODO: calculate minor distance to player (when more than one player), pitagoras
	}
	//TODO: this return if for testing
	return (Player*)players_on_screen.front();
}



