#include "core.h"
#include "player.h"
#include "ModuleRender.h"
#include "ModuleInput.h"
#include "state.h"

Player::Player() {

}

Player::~Player() {

}

void Player::PreUpdate() {

}

void Player::Update() {

	SDL_Rect* current_frame = &current_animation.GetCurrentFrame();

	App->renderer->MyBlit(texture, position.x, position.y, current_frame, 1.f, flipped);

	state->Update(*this);

}

void Player::PostUpdate() {

}
