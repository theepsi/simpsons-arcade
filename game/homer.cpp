#include "core.h"
#include "homer.h"
#include "ModuleTextures.h"

Homer::Homer() {

}

Homer::~Homer() {

}

bool Homer::Start() {

	texture = App->textures->Load("resources/homer_sheet.png");
	
	Animation idle;
	idle.frames.push_back({ 0, 5, 34, 64 });
	idle.frames.push_back({ 0, 5, 34, 64 });
	idle.frames.push_back({ 0, 5, 34, 64 });
	idle.frames.push_back({ 0, 5, 34, 64 });
	idle.frames.push_back({ 0, 5, 34, 64 });
	idle.frames.push_back({ 42, 6, 34, 64 });
	idle.frames.push_back({ 88, 6, 34, 64 });
	idle.frames.push_back({ 139, 6, 34, 64 });
	idle.speed = 0.1f;

	AddAnimation("idle", idle);

	//SetCurrentAnimation("idle");

	return true;
}


