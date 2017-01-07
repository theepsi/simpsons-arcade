#include "core.h"
#include "enemy.h"
#include "ModuleRender.h"
#include "ModuleFonts.h"
#include "state.h"

#include <sstream>
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

	App->renderer->PriorityBlit3D(texture, position.x, position.y, position.z, current_frame, 1.f, flipped);

	state->Update(*this);
}
