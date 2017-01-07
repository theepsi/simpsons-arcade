#include "core.h"
#include "marge.h"
#include "ModuleTextures.h"
#include "margeIdleState.h"

Marge::Marge() {

}

Marge::~Marge() {

}

bool Marge::Start() {

	position.x = 0;
	position.y = 0;
	position.z = 100;
	
	speed = 2.f;
	jump_speed = 5.f;

	texture = App->textures->Load("resources/marge/marge_sprite.png");

	Animation idle;
	idle.frames.push_back({ 0, 0, 100, 100 });
	idle.frames.push_back({ 0, 0, 100, 100 });
	idle.frames.push_back({ 0, 0, 100, 100 });
	idle.frames.push_back({ 0, 0, 100, 100 });
	idle.frames.push_back({ 0, 0, 100, 100 });
	idle.frames.push_back({ 0, 0, 100, 100 });
	idle.frames.push_back({ 0, 0, 100, 100 });
	idle.frames.push_back({ 0, 0, 100, 100 });
	idle.frames.push_back({ 0, 0, 100, 100 });
	idle.frames.push_back({ 0, 0, 100, 100 });
	idle.frames.push_back({ 0, 0, 100, 100 });
	idle.frames.push_back({ 0, 0, 100, 100 });
	idle.frames.push_back({ 0, 0, 100, 100 });
	idle.frames.push_back({ 0, 0, 100, 100 });
	idle.frames.push_back({ 100, 0, 100, 100 });
	idle.frames.push_back({ 200, 0, 100, 100 });
	idle.frames.push_back({ 300, 0, 100, 100 });
	idle.frames.push_back({ 400, 0, 100, 100 });
	idle.frames.push_back({ 500, 0, 100, 100 });
	idle.frames.push_back({ 600, 0, 100, 100 });
	idle.frames.push_back({ 700, 0, 100, 100 });
	idle.speed = 0.17f;

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

	Animation attack_1;
	attack_1.frames.push_back({ 0, 300, 100, 100 });
	attack_1.frames.push_back({ 100, 300, 100, 100 });
	attack_1.frames.push_back({ 200, 300, 100, 100 });
	attack_1.frames.push_back({ 300, 300, 100, 100 });
	attack_1.speed = 0.17f;

	AddAnimation("attack_1", attack_1);

	Animation attack_2;
	attack_2.frames.push_back({ 0, 400, 100, 100 });
	attack_2.frames.push_back({ 100, 400, 100, 100 });
	attack_2.frames.push_back({ 200, 400, 100, 100 });
	attack_2.frames.push_back({ 300, 400, 100, 100 });
	attack_2.frames.push_back({ 400, 400, 100, 100 });
	attack_2.speed = 0.17f;

	AddAnimation("attack_2", attack_2);

	Animation jump;
	jump.frames.push_back({ 0, 500, 100, 100 });
	jump.frames.push_back({ 100, 500, 100, 100 });
	jump.speed = 0.17f;
	jump.loop = false;

	AddAnimation("jump", jump);

	Animation fall;
	fall.frames.push_back({ 0, 600, 100, 100 });
	fall.speed = 0.17f;
	fall.loop = false;

	AddAnimation("fall", fall);


	//TODO: ADD MORE ANIMATIONS

	ChangeState(new MargeIdleState, "idle");

	return true;
}


