#include "core.h"
#include "marge.h"
#include "ModuleTextures.h"
#include "margeDamagedState.h"
#include "margeIdleState.h"
#include "ModuleAudio.h"
#include "margeAttack1State.h"
#include "margeJumpAttackState.h"

Marge::Marge() {

}

Marge::~Marge() {

}

bool Marge::Start() {
	Player::Start();
	position.x = 0;
	position.y = 0;
	position.z = 100;
	
	speed = 2.f;
	jump_speed = 5.f;

	texture = App->textures->Load("resources/marge/marge_sprite.png");

	Animation idle;
	idle.name = "idle";
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
	walking.name = "walking";
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
	walking_up.name = "walking_up";
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
	attack_1.name = "attack_1";
	attack_1.frames.push_back({ 0, 300, 100, 100 });
	attack_1.frames.push_back({ 100, 300, 100, 100 });
	attack_1.frames.push_back({ 200, 300, 100, 100 });
	attack_1.frames.push_back({ 300, 300, 100, 100 });
	attack_1.speed = 0.17f;

	AddAnimation("attack_1", attack_1);

	Animation attack_2;
	attack_2.name = "attack_2";
	attack_2.frames.push_back({ 0, 400, 100, 100 });
	attack_2.frames.push_back({ 100, 400, 100, 100 });
	attack_2.frames.push_back({ 200, 400, 100, 100 });
	attack_2.frames.push_back({ 300, 400, 100, 100 });
	attack_2.frames.push_back({ 400, 400, 100, 100 });
	attack_2.speed = 0.2f;

	AddAnimation("attack_2", attack_2);

	Animation jump;
	jump.name = "jump";
	jump.frames.push_back({ 0, 500, 100, 100 });
	jump.frames.push_back({ 100, 500, 100, 100 });
	jump.speed = 0.17f;
	jump.loop = false;

	AddAnimation("jump", jump);

	Animation fall;
	fall.name = "fall";
	fall.frames.push_back({ 0, 600, 100, 100 });
	fall.speed = 0.17f;
	fall.loop = false;

	AddAnimation("fall", fall);

	Animation jump_attack_1;
	jump_attack_1.name = "jump_attack_1";
	jump_attack_1.frames.push_back({ 0, 700, 100, 100 });
	jump_attack_1.frames.push_back({ 100, 700, 100, 100 });
	jump_attack_1.frames.push_back({ 200, 700, 100, 100 });
	jump_attack_1.frames.push_back({ 300, 700, 100, 100 });
	jump_attack_1.frames.push_back({ 400, 700, 100, 100 });
	jump_attack_1.speed = 0.17f;
	jump_attack_1.loop = false;

	AddAnimation("jump_attack_1", jump_attack_1);

	Animation jump_attack_2;
	jump_attack_2.name = "jump_attack_2";
	jump_attack_2.frames.push_back({ 0, 800, 100, 100 });
	jump_attack_2.frames.push_back({ 100, 800, 100, 100 });
	jump_attack_2.speed = 0.17f;
	jump_attack_2.loop = false;

	AddAnimation("jump_attack_2", jump_attack_2);

	Animation victory;
	victory.name = "victory";
	victory.frames.push_back({ 0, 900, 100, 100 });
	victory.frames.push_back({ 100, 900, 100, 100 });
	victory.speed = 0.17f;
	victory.loop = true;

	AddAnimation("victory", victory);

	Animation dizzy;
	dizzy.name = "dizzy";
	dizzy.frames.push_back({ 0, 1000, 100, 100 });
	dizzy.frames.push_back({ 0, 1000, 0, 100 });
	dizzy.frames.push_back({ 100, 1000, 100, 100 });
	dizzy.frames.push_back({ 0, 1000, 0, 100 });
	dizzy.frames.push_back({ 200, 1000, 100, 100 });
	dizzy.frames.push_back({ 0, 1000, 0, 100 });
	dizzy.frames.push_back({ 300, 1000, 100, 100 });
	dizzy.speed = 0.17f;
	dizzy.loop = true;

	AddAnimation("dizzy", dizzy);

	Animation resu_arrive;
	resu_arrive.name = "resu_arrive";
	resu_arrive.frames.push_back({ 0, 1100, 100, 100 });
	resu_arrive.frames.push_back({ 100, 1100, 100, 100 });
	resu_arrive.speed = 0.17f;
	resu_arrive.loop = true;

	AddAnimation("resu_arrive", resu_arrive);

	Animation resu_fall;
	resu_fall.name = "resu_fall";
	resu_fall.frames.push_back({ 200, 1100, 100, 100 });
	resu_fall.frames.push_back({ 300, 1100, 100, 100 });
	resu_fall.speed = 0.17f;
	resu_fall.loop = true;

	AddAnimation("resu_fall", resu_fall);

	Animation jump_attack_3;
	jump_attack_3.name = "jump_attack_3";
	jump_attack_3.frames.push_back({ 0, 1200, 100, 100 });
	jump_attack_3.frames.push_back({ 100, 1200, 100, 100 });
	jump_attack_3.frames.push_back({ 200, 1200, 100, 100 });
	jump_attack_3.speed = 0.17f;
	jump_attack_3.loop = false;

	AddAnimation("jump_attack_3", jump_attack_3);

	Animation damage_1;
	damage_1.name = "damage_1";
	damage_1.frames.push_back({ 0, 1300, 100, 100 });
	damage_1.frames.push_back({ 100, 1300, 100, 100 });
	damage_1.speed = 0.17f;
	damage_1.loop = false;

	AddAnimation("damage_1", damage_1);


	Animation damage_2;
	damage_2.name = "damage_2";
	damage_2.frames.push_back({ 0, 1400, 100, 100 });
	damage_2.frames.push_back({ 100, 1400, 100, 100 });
	damage_2.frames.push_back({ 200, 1400, 100, 100 });
	damage_2.frames.push_back({ 300, 1400, 100, 100 });
	damage_2.speed = 0.17f;
	damage_2.loop = false;

	AddAnimation("damage_2", damage_2);

	Animation recover;
	recover.name = "recover";
	recover.frames.push_back({ 0, 1500, 100, 100 });
	recover.frames.push_back({ 100, 1500, 100, 100 });
	recover.frames.push_back({ 200, 1500, 100, 100 });
	recover.frames.push_back({ 300, 1500, 100, 100 });
	recover.speed = 0.17f;
	recover.loop = false;

	AddAnimation("recover", recover);

	Animation dead;
	dead.name = "dead";
	dead.frames.push_back({ 0, 1600, 100, 100 });
	dead.frames.push_back({ 100, 1600, 100, 100 });
	dead.speed = 0.1f;
	dead.loop = true;

	AddAnimation("dead", dead);

	SDL_Rect coll_rect = { position.x, position.y, 30, 60 };
	x_offset = 35;
	y_offset = 40;
	collider = App->collision->AddCollider(coll_rect, position.z, this, CollisionAgainst::PLAYER_COLLISION);

	ChangeState(new MargeIdleState, "idle");

	return true;
}

void Marge::RecieveDamage(int amount)
{
	if (!damaged) {
		life -= amount;
		damaged = true;
		if (life <= 0) {
			life = 0;
		}
		App->audio->PlayFx(hit_fx);
		ChangeState(new MargeDamagedState, "damage_2");
	}
}

void Marge::Attack(bool jumping) {
	if (attack_counter < 2) {
		if (jumping)
			ChangeState(new MargeJumpAttackState, "jump_attack_1");
		else
			ChangeState(new MargeAttack1State, "attack_1");
		attack_counter += 1;
	}
	else {
		if (jumping)
			ChangeState(new MargeJumpAttackState, "jump_attack_2");
		else
			ChangeState(new MargeAttack1State, "attack_2");
		attack_counter = 0;
	}
}


