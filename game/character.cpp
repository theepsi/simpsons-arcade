#include "core.h"
#include "character.h"
#include "ModuleRender.h"
#include "ModuleInput.h"
#include "ModuleFonts.h"
#include "state.h"

#include <sstream>

Character::Character() {

}

Character::~Character() {

}

void Character::PreUpdate() {

}

void Character::Update() {

	SDL_Rect* current_frame = &current_animation.GetCurrentFrame();

	App->renderer->PriorityBlit3D(texture, position.x, position.y, position.z, current_frame, 1.f, flipped);

	state->Update(*this);

}

void Character::PostUpdate() {

}

bool Character::CleanUp()
{
	RELEASE(state);
	return true;
}
