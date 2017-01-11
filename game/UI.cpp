#include "core.h"
#include "UI.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"

#include <sstream>

UI::UI()
{
}

UI::~UI()
{
}

bool UI::Start()
{
	font = App->fonts->Load("resources/fonts/simpsons-font.png", "abcdefghijklmnopqrstuvwxyz0123456789.,'''?!@_#$%&()+-/:", 2);

	texture = App->textures->Load("resources/level/UI_sprite.png");

	Animation UI_blinking;
	UI_blinking.frames.push_back({ 0, 0, 288, 28 });
	UI_blinking.frames.push_back({ 0, 28, 288, 28 });
	UI_blinking.speed = 0.1f;
	UI_blinking.loop = true;

	base_UI = UI_blinking;

	Animation* full_life = new Animation();

	full_life->name = "full_life";
	full_life->frames.push_back({ 0, 56, 288, 28 });
	full_life->speed = 0.1f;
	full_life->loop = true;

	Animation* quarter_full_life = new Animation();

	quarter_full_life->name = "quarter_full_life";
	quarter_full_life->frames.push_back({ 0, 84, 288, 28 });
	quarter_full_life->speed = 0.1f;
	quarter_full_life->loop = true;

	Animation* half_life = new Animation();

	half_life->name = "half_life";
	half_life->frames.push_back({ 0, 112, 288, 28 });
	half_life->speed = 0.1f;
	half_life->loop = true;

	Animation* quarter_life = new Animation();

	quarter_life->name = "quarter_life";
	quarter_life->frames.push_back({ 0, 140, 288, 28 });
	quarter_life->speed = 0.1f;
	quarter_life->loop = true;

	Animation* no_life = new Animation();

	no_life->name = "no_life";
	no_life->frames.push_back({ 0, 168, 288, 28 });
	no_life->speed = 0.1f;
	no_life->loop = true;

	current_life_counter = full_life;

	life_counter_sprites.push_back(full_life);
	life_counter_sprites.push_back(quarter_full_life);
	life_counter_sprites.push_back(half_life);
	life_counter_sprites.push_back(quarter_life);
	life_counter_sprites.push_back(no_life);

	return true;
}

void UI::PreUpdate()
{
}

void UI::Update()
{
	SDL_Rect* current_frame = &base_UI.GetCurrentFrame();
	App->renderer->PriorityBlit(texture, 0 - App->renderer->camera.x / SCREEN_SIZE, 0 - App->renderer->camera.y / SCREEN_SIZE, 9999, current_frame, 1.f);
	SDL_Rect* current_frame_life_counter = &current_life_counter->GetCurrentFrame();
	App->renderer->PriorityBlit(texture, 0 - App->renderer->camera.x / SCREEN_SIZE, 0 - App->renderer->camera.y / SCREEN_SIZE, 9999, current_frame_life_counter, 1.f);

	ostringstream oss;
	oss << continues;
	string coords = oss.str();
	App->fonts->Blit((0 - App->renderer->camera.x / SCREEN_SIZE) + 60, (0 - App->renderer->camera.y / SCREEN_SIZE) + 13, font, coords);
	
}

void UI::PostUpdate()
{
}

bool UI::CleanUp()
{
	for (list<Animation*>::iterator it = life_counter_sprites.begin(); it != life_counter_sprites.end(); ++it) {
		RELEASE(*it);
	}
	RELEASE(font);
	return true;
}

void UI::ApplyDamageToUI(int amount)
{
	string search = "";
	switch (amount)
	{
	case 0:
		search = "no_life";
		break;
	case 1:
		search = "quarter_life";
		break;
	case 2:
		search = "half_life";
		break;
	case 3:
		search = "quarter_full_life";
		break;
	case 4:
		search = "full_life";
		break;
	default:
		break;
	}

	for (list<Animation*>::iterator it = life_counter_sprites.begin(); it != life_counter_sprites.end(); ++it) {
		if ((*it)->name == search) {
			current_life_counter = (*it);
		}
	}
	
}
