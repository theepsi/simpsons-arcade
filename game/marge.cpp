#include "core.h"
#include "marge.h"
#include "ModuleTextures.h"
#include "margeIdleState.h"

Marge::Marge() {

}

Marge::~Marge() {

}

bool Marge::Start() {

	speed = 2.f;

	texture = App->textures->Load("resources/marge/marge2.png");

	Animation idle;
	idle.frames.push_back({ 0, 0, 45, 77 });
	idle.frames.push_back({ 0, 0, 45, 77 });
	idle.frames.push_back({ 0, 0, 45, 77 });
	idle.frames.push_back({ 0, 0, 45, 77 });
	idle.frames.push_back({ 0, 0, 45, 77 });
	idle.frames.push_back({ 0, 0, 45, 77 });
	idle.frames.push_back({ 0, 0, 45, 77 });
	idle.frames.push_back({ 0, 0, 45, 77 });
	idle.frames.push_back({ 0, 0, 45, 77 });
	idle.frames.push_back({ 0, 0, 45, 77 });
	idle.frames.push_back({ 0, 0, 45, 77 });
	idle.frames.push_back({ 0, 0, 45, 77 });
	idle.frames.push_back({ 0, 0, 45, 77 });
	idle.frames.push_back({ 0, 0, 45, 77 });
	idle.frames.push_back({ 45, 0, 45, 77 });
	idle.frames.push_back({ 90, 0, 45, 77 });
	idle.frames.push_back({ 135, 0, 45, 77 });
	idle.frames.push_back({ 180, 0, 45, 77 });
	idle.frames.push_back({ 225, 0, 45, 77 });
	idle.frames.push_back({ 270, 0, 45, 77 });
	idle.frames.push_back({ 315, 0, 45, 77 });
	idle.speed = 0.17f;

	AddAnimation("idle", idle);
	
	Animation walking;
	walking.frames.push_back({ 0, 77, 45, 77 });
	walking.frames.push_back({ 45, 77, 45, 77 });
	walking.frames.push_back({ 90, 77, 45, 77 });
	walking.frames.push_back({ 135, 77, 45, 77 });
	walking.frames.push_back({ 180, 77, 45, 77 });
	walking.frames.push_back({ 225, 77, 45, 77 });
	walking.frames.push_back({ 270, 77, 45, 77 });
	walking.frames.push_back({ 315, 77, 45, 77 });
	walking.speed = 0.17f;

	AddAnimation("walking", walking);

	Animation walking_up;
	walking_up.frames.push_back({ 0, 154, 45, 77 });
	walking_up.frames.push_back({ 45, 154, 45, 77 });
	walking_up.frames.push_back({ 90, 154, 45, 77 });
	walking_up.frames.push_back({ 135, 154, 45, 77 });
	walking_up.frames.push_back({ 180, 154, 45, 77 });
	walking_up.frames.push_back({ 225, 154, 45, 77 });
	walking_up.frames.push_back({ 270, 154, 45, 77 });
	walking_up.frames.push_back({ 315, 154, 45, 77 });
	walking_up.speed = 0.17f;

	AddAnimation("walking_up", walking_up);

	//TODO: ADD MORE ANIMATIONS

	ChangeState(new MargeIdleState, "idle");

	return true;
}


