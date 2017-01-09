#include "core.h"
#include "player.h"
#include "ModuleRender.h"
#include "ModuleInput.h"
#include "ModuleFonts.h"
#include "state.h"

#define CAMERA_SCREEN_OFFSET_X 180       //OFFSET for the camera, the scene will move right/down/up when player hits this offset.
#define CAMERA_SCREEN_OFFSET_Y 120  

#define CAMERA_LIMIT_DOWN 16			//SCENARIO_SIZE (256) - CAMERA.H / SCREEN_SIZE === 256 - 240 = 16

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

	//TODO: move camera (on X) only if there are no enemies on screen.

	if (App->input->GetKey(SDL_SCANCODE_F2) == KEY_DOWN)
		debug = !debug;

	if (!debug) {
		if (position.x > (abs(App->renderer->camera.x) / SCREEN_SIZE + App->renderer->camera.w / SCREEN_SIZE) - CAMERA_SCREEN_OFFSET_X) {
			App->renderer->camera.x -= (int)speed * SCREEN_SIZE;
		}

		if (position.z > (abs(App->renderer->camera.y) / SCREEN_SIZE + App->renderer->camera.h / SCREEN_SIZE) - CAMERA_SCREEN_OFFSET_Y &&
			abs(App->renderer->camera.y) / SCREEN_SIZE < CAMERA_LIMIT_DOWN) {
			App->renderer->camera.y -= (int)speed * SCREEN_SIZE;
		}

		if (position.z < -App->renderer->camera.y / SCREEN_SIZE + App->renderer->camera.h / SCREEN_SIZE - CAMERA_SCREEN_OFFSET_Y &&
			abs(App->renderer->camera.y) / SCREEN_SIZE > 0) {
			App->renderer->camera.y += (int)speed * SCREEN_SIZE;
		}
	}
	state->Update(*this);

	//TODO: TEXT TEST
	ModuleFonts::Font* font = App->fonts->Load("resources/fonts/simpsons-font.png", "abcdefghijklmnopqrstuvwxyz0123456789.,'''?!@_#$%&()+-/:", 1);

	ostringstream oss;
	oss << "x: " << position.x << " y: " << position.y << " z: " << position.z;
	string coords = oss.str();
	App->fonts->Blit(0 - App->renderer->camera.x / SCREEN_SIZE, 0 - App->renderer->camera.y / SCREEN_SIZE, font, coords);
	
	RELEASE(font);

}
