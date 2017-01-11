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
	texture = App->textures->Load("resources/level/level_cementery_sheet.png");
	App->audio->PlayMusic("resources/audio/cementery.wav", 2.5f);
	return true;
}

void Cementery::PreUpdate()
{
}

void Cementery::Update()
{
	App->renderer->PriorityBlit(texture, 0, 0, -1, section);
}

void Cementery::PostUpdate()
{
}

bool Cementery::CleanUp()
{
	RELEASE(section);
	return true;
}
