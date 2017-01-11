#include "core.h"
#include "character.h"
#include "ModuleRender.h"
#include "ModuleInput.h"
#include "ModuleFonts.h"
#include "Moduleaudio.h"
#include "state.h"

#include <sstream>

Character::Character() {

}

Character::~Character() {

}

bool Character::Start()
{
	hit_fx = App->audio->LoadFx("resources/audio/SFX/hit.wav");
	font = App->fonts->Load("resources/fonts/simpsons-font.png", "abcdefghijklmnopqrstuvwxyz0123456789.,'''?!@_#$%&()+-/:", 1);
	return true;
}

void Character::PreUpdate() {

}

void Character::Update() {

	SDL_Rect* current_frame = &current_animation.GetCurrentFrame();

	App->renderer->PriorityBlit3D(texture, position.x, position.y, position.z, current_frame, 1.f, flipped);

	state->Update(*this);

}

void Character::PostUpdate() {
	UpdateColliderPosition();
}

bool Character::CleanUp()
{
	RELEASE(font);
	RELEASE(state);
	return true;
}
