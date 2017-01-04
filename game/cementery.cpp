#include "core.h"
#include "cementery.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"

Cementery::Cementery()
{
	
}

Cementery::~Cementery()
{
}

bool Cementery::Start()
{
	texture = App->textures->Load("resources/level/level_cementery_sheet.png");
	return true;
}

void Cementery::PreUpdate()
{
}

void Cementery::Update()
{
	//TODO: Change this when player moves...
	SDL_Rect section = {4, 262, 2304, 256};

	App->renderer->Blit(texture, 0, 0, &section);
}

void Cementery::PostUpdate()
{
}
