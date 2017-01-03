#include "Globals.h"
#include "core.h"
#include "ModuleFonts.h"
#include "ModuleRender.h"
#include "SDL/include/SDL.h"

#include "SDL_image/include/SDL_image.h"
#pragma comment( lib, "SDL_image/libx86/SDL2_image.lib" )

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
	SDL_Rect section = {0, 0, 0, 0};

	for (string::const_iterator it = text.begin(); it != text.end(); ++it) {
		if (*it == (const char)32) {
			x += 8;
		}
		else {
			int index = SearchInMask(font->mask, *it);
			SDL_Rect section = { 8*index, 0, 8, 9 };
			App->renderer->Blit(font->texture, x, y, &section);
			x += 8;
		}	
	}


	return ret;
}

ModuleFonts::Font* ModuleFonts::Load(const char* path, const string& mask, int id)
{
	SDL_Texture* texture = nullptr;
	SDL_Surface* surface = IMG_Load(path);

	Font* font = new Font();

	if (surface == nullptr)
	{
		LOG("Could not load surface with path: %s. IMG_Load: %s", path, IMG_GetError());
	}
	else
	{
		texture = SDL_CreateTextureFromSurface(App->renderer->renderer, surface);

		if (texture == nullptr)
		{
			LOG("Unable to create texture from surface! SDL Error: %s\n", SDL_GetError());
		}
		else
		{
			
			font->texture = texture;
			font->mask = mask;
			fonts[id] = font;
		}

		SDL_FreeSurface(surface);
	}

	return font;
}


