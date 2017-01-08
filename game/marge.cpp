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
	idle.frames.push_back({ 500, 0, 100, 100 });
	idle.frames.push_back({ 600, 0, 100, 100 });
	idle.frames.push_back({ 600, 0, 100, 100 });
	idle.frames.push_back({ 700, 0, 100, 100 });
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
	attack_2.speed = 0.2f;

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

	Animation jump_attack_1;
	jump_attack_1.frames.push_back({ 0, 700, 100, 100 });
	jump_attack_1.frames.push_back({ 100, 700, 100, 100 });
	jump_attack_1.frames.push_back({ 200, 700, 100, 100 });
	jump_attack_1.frames.push_back({ 300, 700, 100, 100 });
	jump_attack_1.frames.push_back({ 400, 700, 100, 100 });
	jump_attack_1.speed = 0.17f;
	jump_attack_1.loop = false;

	AddAnimation("jump_attack_1", jump_attack_1);

	Animation jump_attack_2;
	jump_attack_2.frames.push_back({ 0, 800, 100, 100 });
	jump_attack_2.frames.push_back({ 100, 800, 100, 100 });
	jump_attack_2.speed = 0.17f;
	jump_attack_2.loop = false;

	AddAnimation("jump_attack_2", jump_attack_2);

	Animation victory;
	victory.frames.push_back({ 0, 900, 100, 100 });
	victory.frames.push_back({ 100, 900, 100, 100 });
	victory.speed = 0.17f;
	victory.loop = true;

	AddAnimation("victory", victory);

	Animation dizzy;
	dizzy.frames.push_back({ 0, 1000, 100, 100 });
	dizzy.frames.push_back({ 100, 1000, 100, 100 });
	dizzy.frames.push_back({ 200, 1000, 100, 100 });
	dizzy.frames.push_back({ 300, 1000, 100, 100 });
	dizzy.speed = 0.17f;
	dizzy.loop = true;

	AddAnimation("dizzy", dizzy);

	Animation resu_arrive;
	resu_arrive.frames.push_back({ 0, 1100, 100, 100 });
	resu_arrive.frames.push_back({ 100, 1100, 100, 100 });
	resu_arrive.speed = 0.17f;
	resu_arrive.loop = true;

	AddAnimation("resu_arrive", resu_arrive);

	Animation resu_fall;
	resu_fall.frames.push_back({ 200, 1100, 100, 100 });
	resu_fall.frames.push_back({ 300, 1100, 100, 100 });
	resu_fall.speed = 0.17f;
	resu_fall.loop = true;

	AddAnimation("resu_fall", resu_fall);

	Animation jump_attack_3;
	jump_attack_3.frames.push_back({ 0, 1200, 100, 100 });
	jump_attack_3.frames.push_back({ 100, 1200, 100, 100 });
	jump_attack_3.frames.push_back({ 200, 1200, 100, 100 });
	jump_attack_3.speed = 0.17f;
	jump_attack_3.loop = false;

	AddAnimation("jump_attack_3", jump_attack_3);

	Animation damage_1;
	damage_1.frames.push_back({ 0, 1300, 100, 100 });
	damage_1.frames.push_back({ 100, 1300, 100, 100 });
	damage_1.speed = 0.17f;
	damage_1.loop = false;

	AddAnimation("damage_1", damage_1);

	//TODO: ADD MORE ANIMATIONS

	ChangeState(new MargeIdleState, "idle");

	return true;
}


