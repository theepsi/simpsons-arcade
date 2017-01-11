#include "core.h"
#include "royd.h"
#include "ModuleTextures.h"
#include "roydIdleState.h"
#include "roydDamagedState.h"
#include "roydAttackState.h"
#include "ModuleAudio.h"

Royd::Royd()
{
}

Royd::~Royd()
{
}

bool Royd::Start()
{
	/*position.x = 50;
	position.y = 0;
	position.z = 102;*/

	Enemy::Start();

	speed = 1.f;

	texture = App->textures->Load("resources/enemy_royd/royd_sprite.png");

	Animation idle;
	idle.name = "idle";
	idle.frames.push_back({ 0, 0, 100, 100 });
	idle.frames.push_back({ 100, 0, 100, 100 });
	idle.speed = 0.09f;

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

	Animation walking_down;
	walking_down.name = "walking_down";
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

	Animation attack_1;
	attack_1.name = "attack_1";
	attack_1.frames.push_back({ 0, 400, 100, 100 });
	attack_1.frames.push_back({ 100, 400, 100, 100 });
	attack_1.frames.push_back({ 200, 400, 100, 100 });
	attack_1.frames.push_back({ 300, 400, 100, 100 });
	attack_1.frames.push_back({ 400, 400, 100, 100 });
	attack_1.frames.push_back({ 500, 400, 100, 100 });
	attack_1.frames.push_back({ 600, 400, 100, 100 });
	attack_1.speed = 0.17f;

	AddAnimation("attack_1", attack_1);

	Animation attack_2;
	attack_2.name = "attack_2";
	attack_2.frames.push_back({ 0, 500, 100, 100 });
	attack_2.frames.push_back({ 100, 500, 100, 100 });
	attack_2.frames.push_back({ 200, 500, 100, 100 });
	attack_2.frames.push_back({ 300, 500, 100, 100 });
	attack_2.speed = 0.17f;
	attack_2.loop = false;

	AddAnimation("attack_2", attack_2);

	Animation damaged;
	damaged.name = "damaged";
	damaged.frames.push_back({ 0, 600, 100, 100 });
	damaged.frames.push_back({ 100, 600, 100, 100 });
	damaged.frames.push_back({ 200, 600, 100, 100 });
	damaged.frames.push_back({ 300, 600, 100, 100 });
	damaged.frames.push_back({ 400, 600, 100, 100 });
	damaged.frames.push_back({ 500, 600, 100, 100 });
	damaged.frames.push_back({ 600, 600, 100, 100 });
	damaged.speed = 0.17f;
	damaged.loop = false;

	AddAnimation("damaged", damaged);

	Animation recover;
	recover.name = "recover";
	recover.frames.push_back({ 0, 700, 100, 100 });
	recover.frames.push_back({ 100, 700, 100, 100 });
	recover.frames.push_back({ 0, 700, 100, 100 });
	recover.frames.push_back({ 100, 700, 100, 100 });
	recover.frames.push_back({ 200, 700, 100, 100 });
	recover.frames.push_back({ 300, 700, 100, 100 });
	recover.frames.push_back({ 200, 700, 100, 100 });
	recover.frames.push_back({ 300, 700, 100, 100 });
	recover.frames.push_back({ 400, 700, 100, 100 });
	recover.speed = 0.17f;
	recover.loop = false;

	AddAnimation("recover", recover);

	Animation dead;
	dead.name = "dead";
	dead.frames.push_back({ 0, 800, 100, 100 });
	dead.frames.push_back({ 100, 800, 100, 100 });
	dead.frames.push_back({ 200, 800, 100, 100 });
	dead.frames.push_back({ 0, 800, 0, 100 });
	dead.frames.push_back({ 300, 800, 100, 100 });
	dead.frames.push_back({ 0, 800, 0, 100 });
	dead.frames.push_back({ 300, 800, 100, 100 });
	dead.frames.push_back({ 0, 800, 0, 100 });
	dead.speed = 0.17f;
	dead.loop = false;

	AddAnimation("dead", dead);
	
	SDL_Rect coll_rect = { position.x, position.y, 30, 60 };
	x_offset = 35;
	y_offset = 40;
	collider = App->collision->AddCollider(coll_rect, position.z, this, CollisionAgainst::ENEMY_COLLISION);
	SetCurrentAnimation("idle");

	ChangeState(new RoydIdleState, "idle");

	return true;
}

void Royd::RecieveDamage(int amount)
{
	if (!damaged) {
		life -= amount;
		damaged = true;
		//random move after receive damage
		after_attack = true;
		if (life <= 0){
			life = 0;
		}
		App->audio->PlayFx(hit_fx);
		ChangeState(new RoydDamagedState, "damaged");
	}
}

void Royd::Attack()
{
	if (!attacking) {
		//random move after receive damage
		after_attack = true;
		attacking = true;
		int attack = 1 + (rand() % (int)(2 - 1 + 1));
		if (attack == 1)
			ChangeState(new RoydAttackState, "attack_1");
		else
			ChangeState(new RoydAttackState, "attack_2");
	}
}
