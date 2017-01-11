#include "core.h"
#include "UI.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"

UI::UI()
{
}

UI::~UI()
{
}

bool UI::Start()
{
	texture = App->textures->Load("resources/level/UI_sprite.png");

	Animation UI_blinking;
	UI_blinking.frames.push_back({ 0, 0, 288, 29 });
	UI_blinking.frames.push_back({ 0, 29, 288, 29 });
	UI_blinking.speed = 0.1f;
	UI_blinking.loop = true;

	animation = UI_blinking;

	return true;
}

void UI::PreUpdate()
{
}

void UI::Update()
{
	SDL_Rect* current_frame = &animation.GetCurrentFrame();
	App->renderer->PriorityBlit(texture, 0 - App->renderer->camera.x / SCREEN_SIZE, 0 - App->renderer->camera.y / SCREEN_SIZE, 9999, current_frame, 1.f);
}

void UI::PostUpdate()
{
}

bool UI::CleanUp()
{
	return true;
}
