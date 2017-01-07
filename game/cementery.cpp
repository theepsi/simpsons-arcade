#include "core.h"
#include "cementery.h"
#include "ModuleTextures.h"
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
	texture = App->textures->Load("resources/level/level_cementery_sheet.png");
	return true;
}

void Cementery::PreUpdate()
{
}

void Cementery::Update()
{
	//TODO: Change this when player moves...
	App->renderer->PriorityBlit(texture, 0, 0, section);
}

void Cementery::PostUpdate()
{
}

bool Cementery::CleanUp()
{
	RELEASE(section);
	return true;
}
