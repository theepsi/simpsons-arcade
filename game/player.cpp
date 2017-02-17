#include "core.h"
#include "player.h"
#include "ModuleRender.h"
#include "ModuleInput.h"
#include "ModuleFonts.h"
#include "ModuleSceneManager.h"
#include "ModuleCollision.h"
#include "Scene.h"
#include "UI.h"
#include "state.h"

#define CAMERA_SCREEN_OFFSET_X 180       //OFFSET for the camera, the scene will move right/down/up when player hits this offset.
#define CAMERA_SCREEN_OFFSET_Y 120  

#define CAMERA_LIMIT_DOWN 8

#define X_END_DEMO 1740

#include <sstream>


Player::Player()
{
	type = GameObjectType::PLAYER_ENTITY;
	life = 4;
	continues = 4;
	respawning = 0;
}

Player::~Player()
{
}

void Player::Update() {

	if (position.x >= X_END_DEMO) {
		App->fonts->Blit((0 - App->renderer->camera.x / SCREEN_SIZE), (0 - App->renderer->camera.y + App->renderer->camera.h / 2) / SCREEN_SIZE, font, "you beat the demo");
		App->fonts->Blit((0 - App->renderer->camera.x / SCREEN_SIZE), (0 - App->renderer->camera.y + App->renderer->camera.h / 2) / SCREEN_SIZE + 20, font, "press R to reload the game");
	}
	if (life == 0 && continues == 0) {
		App->fonts->Blit((0 - App->renderer->camera.x / SCREEN_SIZE), (0 - App->renderer->camera.y + App->renderer->camera.h / 2) / SCREEN_SIZE, font, "you died");
		App->fonts->Blit((0 - App->renderer->camera.x / SCREEN_SIZE), (0 - App->renderer->camera.y + App->renderer->camera.h / 2) / SCREEN_SIZE + 20, font, "press R to reload the game");
	}
	ui->ApplyDamageToUI(life);
	ui->GetContinues(continues);
	ApplySceneLimits();

	SDL_Rect* current_frame = &current_animation.GetCurrentFrame();

	if (respawning <= 0)
		respawning = 0;
	if (respawning != 0) {
		respawning -= 1;
		if (respawning % 2 == 0) {
			App->renderer->PriorityBlit3D(texture, position.x, position.y, position.z, current_frame, 1.f, flipped);
		}
	}
	else {
		App->renderer->PriorityBlit3D(texture, position.x, position.y, position.z, current_frame, 1.f, flipped);
	}


	//TODO: Allow Camera to move if no enemies.

	if (App->input->GetKey(SDL_SCANCODE_F2) == KEY_DOWN)
		camera_attached = !camera_attached;
	if (App->input->GetKey(SDL_SCANCODE_F1) == KEY_DOWN)
		debug = !debug;
	if (App->input->GetKey(SDL_SCANCODE_F3) == KEY_DOWN)
		god_mode = !god_mode;

	if (camera_attached) {
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

	if (debug) {
		//DEBUG POSITION
		ostringstream oss;
		oss << "x: " << position.x << " y: " << position.y << " z: " << position.z;
		string coords = oss.str();
		App->fonts->Blit(0 - App->renderer->camera.x / SCREEN_SIZE, (0 - App->renderer->camera.y + App->renderer->camera.h - 35) / SCREEN_SIZE, font, coords);
	}
	if (god_mode) {
		//GOD MODE ON
		App->fonts->Blit((0 - App->renderer->camera.x + App->renderer->camera.w - 300) / SCREEN_SIZE, (0 - App->renderer->camera.y + App->renderer->camera.h - 35) / SCREEN_SIZE, font, "god mode: on");
	}
}

void Player::ApplySceneLimits()
{
	Scene* scene = App->scene_manager->current_scene;
	//Apply camera position.x to camera, so the player can not go back.
	if (position.x < scene->x_min + abs(App->renderer->camera.x) / SCREEN_SIZE)
		position.x = scene->x_min + abs(App->renderer->camera.x) / SCREEN_SIZE;
	else if (position.x > scene->x_max)
		position.x = scene->x_max;
	if (position.z < scene->z_min)
		position.z = scene->z_min;
	else if (position.z > scene->z_max)
		position.z = scene->z_max;
	if (position.x > ((abs(App->renderer->camera.x) + App->renderer->camera.w - CAMERA_SCREEN_OFFSET_X) / SCREEN_SIZE)) {
		position.x = (abs(App->renderer->camera.x) + App->renderer->camera.w - CAMERA_SCREEN_OFFSET_X) / SCREEN_SIZE;
	}
}

bool Player::OnEnterCollision(Collider& source, Collider& affected)
{
	if (affected.col_against == CollisionAgainst::ENEMY_ATTACK_COLISION) {
		if(respawning==0 && !god_mode)
			RecieveDamage(1);
	}
	return true;
}
