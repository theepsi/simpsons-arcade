#include "core.h"
#include "cementery.h"
#include "ModuleTextures.h"
#include "ModuleAudio.h"
#include "ModuleRender.h"

Cementery::Cementery()
{
	type = GameObjectType::SCENARY_ENTITY;
}

Cementery::~Cementery()
{
}

bool Cementery::Start()
{
	texture = App->textures->Load("resources/level/cementery.png");
	App->audio->PlayMusic("resources/audio/cementery.wav", 2.5f);

	Animation* trees_background = new Animation();
	trees_background->frames.push_back({ 0, 256, 2304, 256 });
	trees_background->loop = true;
	trees_background->speed = .1f;

	Animation* trees_foreground = new Animation();
	trees_foreground->frames.push_back({ 0, 512, 2304, 256 });
	trees_foreground->loop = true;
	trees_foreground->speed = .1f;

	background_animations.push_back(trees_background);
	foreground_animations.push_back(trees_foreground);

	return true;
}

void Cementery::PreUpdate()
{
}

void Cementery::Update()
{
	App->renderer->PriorityBlit(texture, 0, 0, -1, section);
	for (list<Animation*>::iterator it = background_animations.begin(); it != background_animations.end(); ++it) {
		SDL_Rect* current_frame = &(*it)->GetCurrentFrame();
		App->renderer->PriorityBlit(texture, 0, 0, -1, current_frame, 1.f);
	}
	for (list<Animation*>::iterator it = foreground_animations.begin(); it != foreground_animations.end(); ++it) {
		SDL_Rect* current_frame = &(*it)->GetCurrentFrame();
		App->renderer->PriorityBlit(texture, 0, 0, 500, current_frame, 1.f);
	}
}

void Cementery::PostUpdate()
{
}

bool Cementery::CleanUp()
{
	for (list<Animation*>::iterator it = background_animations.begin(); it != background_animations.end(); ++it) {
		RELEASE(*it);
	}
	for (list<Animation*>::iterator it = foreground_animations.begin(); it != foreground_animations.end(); ++it) {
		RELEASE(*it);
	}
	RELEASE(section);
	return true;
}
