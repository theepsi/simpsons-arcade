#include "core.h"
#include "player.h"
#include "ModuleRender.h"
#include "ModuleInput.h"
#include "ModuleFonts.h"
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

	//TODO: TEXT TEST, ITS JUST A SAMPLE
	ModuleFonts::Font* font = App->fonts->Load("resources/fonts/simpsons-font.png", "abcdefghijklmnopqrstuvwxyz0123456789.,'''?!@_#$%&()+-/:", 1);

	App->fonts->Blit(100, 50, font, "hola, me llamo marge.");
	App->fonts->Blit(125, 60, font, "tantrum!!!!");

	state->Update(*this);

}

void Player::PostUpdate() {

}
