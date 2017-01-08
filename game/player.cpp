#include "core.h"
#include "player.h"
#include "ModuleRender.h"
#include "ModuleInput.h"
#include "ModuleFonts.h"
#include "state.h"

#define CAMERA_SCREEN_OFFSET 180 //OFFSET for the camera, the scene will move right when player thits this offset.

#include <sstream>


Player::Player()
{
	type = GameObjectType::PLAYER_ENTITY;
}

Player::~Player()
{
}

void Player::Update() {

	SDL_Rect* current_frame = &current_animation.GetCurrentFrame();

	App->renderer->PriorityBlit3D(texture, position.x, position.y, position.z, current_frame, 1.f, flipped);

	//TODO: move camera only if there are no enemies on screen.

	if (position.x > (abs(App->renderer->camera.x) / SCREEN_SIZE + App->renderer->camera.w / SCREEN_SIZE) - CAMERA_SCREEN_OFFSET) {
		App->renderer->camera.x -= (int)speed*3;
	}

	state->Update(*this);

	//TODO: TEXT TEST
	ModuleFonts::Font* font = App->fonts->Load("resources/fonts/simpsons-font.png", "abcdefghijklmnopqrstuvwxyz0123456789.,'''?!@_#$%&()+-/:", 1);

	ostringstream oss;
	oss << "x: " << position.x << " y: " << position.y << " z: " << position.z;
	string coords = oss.str();
	App->fonts->Blit(100 + position.x, 50, font, coords);
	
	RELEASE(font);

}
