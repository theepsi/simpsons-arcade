#include "Globals.h"
#include "core.h"
#include "ModuleFonts.h"

ModuleFonts::ModuleFonts()
{
}

ModuleFonts::~ModuleFonts()
{
}

bool ModuleFonts::Init()
{
	return true;
}

update_status ModuleFonts::PreUpdate()
{
	return UPDATE_CONTINUE;
}

update_status ModuleFonts::Update()
{
	return UPDATE_CONTINUE;
}

update_status ModuleFonts::PostUpdate()
{
	return UPDATE_CONTINUE;
}

bool ModuleFonts::CleanUp()
{
	return true;
}

bool ModuleFonts::Blit(int x, int y, Font* font, const string& text)
{
	bool ret = true;
	/*SDL_Rect rect;
	rect.x = (int)x * SCREEN_SIZE;
	rect.y = (int)y * SCREEN_SIZE;

	if (section != NULL)
	{
		rect.w = section->w;
		rect.h = section->h;
	}
	else
	{
		SDL_QueryTexture(font->texture, NULL, NULL, &rect.w, &rect.h);
	}

	rect.w *= SCREEN_SIZE;
	rect.h *= SCREEN_SIZE;

	if (SDL_RenderCopy(renderer, font->texture, section, &rect) != 0)
	{
		LOG("Cannot blit to screen. SDL_RenderCopy error: %s", SDL_GetError());
		ret = false;
	}*/

	return ret;
}

ModuleFonts::Font* ModuleFonts::Load(const char* path, const string& mask, int id)
{
	return nullptr;
}


