#include "core.h"
#include "royd.h"
#include "ModuleTextures.h"
#include "roydIdleState.h"

Royd::Royd()
{
}

Royd::~Royd()
{
}

bool Royd::Start()
{
	position.x = 50;
	position.y = 0;
	position.z = 102;

	speed = 2.f;

	texture = App->textures->Load("resources/enemy_royd/royd_sprite.png");

	Animation idle;
	idle.frames.push_back({ 0, 0, 100, 100 });
	idle.frames.push_back({ 100, 0, 100, 100 });
	idle.speed = 0.09f;

	AddAnimation("idle", idle);

	Animation walking;
	walking.frames.push_back({ 0, 100, 100, 100 });
	walking.frames.push_back({ 100, 100, 100, 100 });
	walking.frames.push_back({ 200, 100, 100, 100 });
	walking.frames.push_back({ 300, 100, 100, 100 });
	walking.frames.push_back({ 400, 100, 100, 100 });
	walking.frames.push_back({ 500, 100, 100, 100 });
	walking.frames.push_back({ 600, 100, 100, 100 });
	walking.frames.push_back({ 700, 100, 100, 100 });
	walking.speed = 0.17f;

	AddAnimation("walking", walking);

	Animation walking_up;
	walking_up.frames.push_back({ 0, 200, 100, 100 });
	walking_up.frames.push_back({ 100, 200, 100, 100 });
	walking_up.frames.push_back({ 200, 200, 100, 100 });
	walking_up.frames.push_back({ 300, 200, 100, 100 });
	walking_up.frames.push_back({ 400, 200, 100, 100 });
	walking_up.frames.push_back({ 500, 200, 100, 100 });
	walking_up.frames.push_back({ 600, 200, 100, 100 });
	walking_up.frames.push_back({ 700, 200, 100, 100 });
	walking_up.speed = 0.17f;

	AddAnimation("walking_up", walking_up);

	Animation walking_down;
	walking_down.frames.push_back({ 0, 300, 100, 100 });
	walking_down.frames.push_back({ 100, 300, 100, 100 });
	walking_down.frames.push_back({ 200, 300, 100, 100 });
	walking_down.frames.push_back({ 300, 300, 100, 100 });
	walking_down.frames.push_back({ 400, 300, 100, 100 });
	walking_down.frames.push_back({ 500, 300, 100, 100 });
	walking_down.frames.push_back({ 600, 300, 100, 100 });
	walking_down.frames.push_back({ 700, 300, 100, 100 });
	walking_down.speed = 0.17f;

	AddAnimation("walking_down", walking_down);
	

	//TODO: ADD MORE ANIMATIONS
	//TODO: State machine for enemy?
	SetCurrentAnimation("idle");

	ChangeState(new RoydIdleState, "idle");

	return true;
}
