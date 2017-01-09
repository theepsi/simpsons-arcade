#include "Globals.h"
#include "core.h"
#include "ModuleRender.h"
#include "ModuleWindow.h"
#include "ModuleInput.h"
#include "SDL/include/SDL.h"

#define OFFSET_ANGLE 0.349066  //aprox. 20 degree

ModuleRender::ModuleRender()
{
	camera.x = camera.y = 0;
	camera.w = SCREEN_WIDTH * SCREEN_SIZE;
	camera.h = SCREEN_HEIGHT * SCREEN_SIZE;
}

// Destructor
ModuleRender::~ModuleRender()
{}

// Called before render is available
bool ModuleRender::Init()
{
	LOG("Creating Renderer context");
	bool ret = true;
	Uint32 flags = 0;

	if(VSYNC == true)
	{
		flags |= SDL_RENDERER_PRESENTVSYNC;
	}

	renderer = SDL_CreateRenderer(App->window->window, -1, flags);
	
	if(renderer == nullptr)
	{
		LOG("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
		ret = false;
	}

	return ret;
}

update_status ModuleRender::PreUpdate()
{
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
	SDL_RenderClear(renderer);
	return UPDATE_CONTINUE;
}

// Called every draw update
update_status ModuleRender::Update()
{
	// debug camera
	if (App->input->GetKey(SDL_SCANCODE_F2) == KEY_DOWN)
		debug = !debug;


	if (debug) {
		int speed = 4;

		if (App->input->GetKey(SDL_SCANCODE_UP) == KEY_REPEAT)
			App->renderer->camera.y += speed;

		if (App->input->GetKey(SDL_SCANCODE_DOWN) == KEY_REPEAT)
			App->renderer->camera.y -= speed;

		if (App->input->GetKey(SDL_SCANCODE_LEFT) == KEY_REPEAT)
			App->renderer->camera.x += speed;

		if (App->input->GetKey(SDL_SCANCODE_RIGHT) == KEY_REPEAT)
			App->renderer->camera.x -= speed;
	}


	while (!priority_queue_renderer.empty())
	{
		RenderGameObject* gameObject = priority_queue_renderer.top();
		if (gameObject->flipped) {
			SDL_RendererFlip flip = SDL_FLIP_HORIZONTAL;

			if (SDL_RenderCopyEx(renderer, gameObject->texture, gameObject->section, gameObject->rect, NULL, NULL, flip) != 0)
			{
				LOG("Cannot blit to screen. SDL_RenderCopy error: %s", SDL_GetError());
				return UPDATE_ERROR;
			}

		}
		else {
			if (SDL_RenderCopy(renderer, gameObject->texture, gameObject->section, gameObject->rect) != 0)
			{
				LOG("Cannot blit to screen. SDL_RenderCopy error: %s", SDL_GetError());
				return UPDATE_ERROR;
			}
		}
		RELEASE(gameObject->rect);
		RELEASE(gameObject);
		priority_queue_renderer.pop();
	}

	return UPDATE_CONTINUE;
}

update_status ModuleRender::PostUpdate()
{
	SDL_RenderPresent(renderer);
	return UPDATE_CONTINUE;
}

// Called before quitting
bool ModuleRender::CleanUp()
{
	LOG("Destroying RenderGameObjects");
	while (!priority_queue_renderer.empty())
	{
		RenderGameObject* gameObject = priority_queue_renderer.top();
		RELEASE(gameObject->rect);
		RELEASE(gameObject);
		priority_queue_renderer.pop();
	}
	LOG("Destroying renderer");

	//Destroy window
	if(renderer != nullptr)
	{
		SDL_DestroyRenderer(renderer);
	}

	return true;
}

// Blit to screen
bool ModuleRender::Blit(SDL_Texture* texture, int x, int y, SDL_Rect* section, float speed)
{
	bool ret = true;
	SDL_Rect rect;
	rect.x = (int)(camera.x * speed) + x * SCREEN_SIZE;
	rect.y = (int)(camera.y * speed) + y * SCREEN_SIZE;

	if(section != NULL)
	{
		rect.w = section->w;
		rect.h = section->h;
	}
	else
	{
		SDL_QueryTexture(texture, NULL, NULL, &rect.w, &rect.h);
	}

	rect.w *= SCREEN_SIZE;
	rect.h *= SCREEN_SIZE;

	if(SDL_RenderCopy(renderer, texture, section, &rect) != 0)
	{
		LOG("Cannot blit to screen. SDL_RenderCopy error: %s", SDL_GetError());
		ret = false;
	}

	return ret;
}

void ModuleRender::PriorityBlit(SDL_Texture * texture, int x, int y, int priority, SDL_Rect * section, float speed, bool flipped)
{
	bool ret = true;
	SDL_Rect* rect = new SDL_Rect;

	rect->x = (int)(camera.x * speed) + x * SCREEN_SIZE;
	rect->y = (int)(camera.y * speed) + y * SCREEN_SIZE;

	if (section != NULL)
	{
		rect->w = section->w;
		rect->h = section->h;
	}
	else
	{
		SDL_QueryTexture(texture, NULL, NULL, &rect->w, &rect->h);
	}

	rect->w *= SCREEN_SIZE;
	rect->h *= SCREEN_SIZE;


	RenderGameObject* rgo = new RenderGameObject();
	rgo->texture = texture;
	rgo->section = section;
	rgo->rect = rect;
	rgo->priority = priority;
	rgo->flipped = flipped;

	priority_queue_renderer.emplace(rgo);
}

void ModuleRender::PriorityBlit3D(SDL_Texture* texture, int x, int y, int z, SDL_Rect* section, float speed, bool flipped)
{
	bool ret = true;
	SDL_Rect* rect = new SDL_Rect;

	rect->x = (int)(camera.x * speed) + x * SCREEN_SIZE;
	y += z * (int)round(cos(OFFSET_ANGLE));
	rect->y = (int)(camera.y * speed) + y * SCREEN_SIZE;

	if (section != NULL)
	{
		rect->w = section->w;
		rect->h = section->h;
	}
	else
	{
		SDL_QueryTexture(texture, NULL, NULL, &rect->w, &rect->h);
	}

	rect->w *= SCREEN_SIZE;
	rect->h *= SCREEN_SIZE;


	RenderGameObject* rgo = new RenderGameObject();
	rgo->texture = texture;
	rgo->section = section;
	rgo->rect = rect;
	rgo->priority = z;
	rgo->flipped = flipped;
	
	priority_queue_renderer.emplace(rgo);
}

bool ModuleRender::Blit3D(SDL_Texture* texture, int x, int y, int z, SDL_Rect* section, float speed)
{
	bool ret = true;
	SDL_Rect rect;
	rect.x = (int)(camera.x * speed) + x * SCREEN_SIZE;
	y += z * (int)round(cos(OFFSET_ANGLE));
	rect.y = (int)(camera.y * speed) + y * SCREEN_SIZE;

	if (section != NULL)
	{
		rect.w = section->w;
		rect.h = section->h;
	}
	else
	{
		SDL_QueryTexture(texture, NULL, NULL, &rect.w, &rect.h);
	}

	rect.w *= SCREEN_SIZE;
	rect.h *= SCREEN_SIZE;

	if (SDL_RenderCopy(renderer, texture, section, &rect) != 0)
	{
		LOG("Cannot blit to screen. SDL_RenderCopy error: %s", SDL_GetError());
		ret = false;
	}

	return ret;
}

bool ModuleRender::MyBlit(SDL_Texture* texture, int x, int y, int z, SDL_Rect* section, float speed, bool flipped)
{
	bool ret = true;
	SDL_Rect rect;

	rect.x = (int)(camera.x * speed) + x * SCREEN_SIZE;
	y += z * (int)round(cos(OFFSET_ANGLE));
	rect.y = (int)(camera.y * speed) + y * SCREEN_SIZE;

	if (section != NULL)
	{
		rect.w = section->w;
		rect.h = section->h;
	}
	else
	{
		SDL_QueryTexture(texture, NULL, NULL, &rect.w, &rect.h);
	}

	rect.w *= SCREEN_SIZE;
	rect.h *= SCREEN_SIZE;

	if (flipped) {
		SDL_RendererFlip flip = SDL_FLIP_HORIZONTAL;

		if (SDL_RenderCopyEx(renderer, texture, section, &rect, NULL, NULL, flip) != 0)
		{
			LOG("Cannot blit to screen. SDL_RenderCopy error: %s", SDL_GetError());
			ret = false;
		}

	}
	else {
		if (SDL_RenderCopy(renderer, texture, section, &rect) != 0)
		{
			LOG("Cannot blit to screen. SDL_RenderCopy error: %s", SDL_GetError());
			ret = false;
		}
	}

	return ret;
}

bool ModuleRender::DrawQuad(const SDL_Rect& rect, Uint8 r, Uint8 g, Uint8 b, Uint8 a, bool use_camera)
{
	bool ret = true;

	SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
	SDL_SetRenderDrawColor(renderer, r, g, b, a);

	SDL_Rect rec(rect);
	if (use_camera)
	{
		rec.x = (int)(camera.x + rect.x * SCREEN_SIZE);
		rec.y = (int)(camera.y + rect.y * SCREEN_SIZE);
		rec.w *= SCREEN_SIZE;
		rec.h *= SCREEN_SIZE;
	}

	if (SDL_RenderFillRect(renderer, &rec) != 0)
	{
		LOG("Cannot draw quad to screen. SDL_RenderFillRect error: %s", SDL_GetError());
		ret = false;
	}

	return ret;
}

bool ModuleRender::DrawQuad3D(const SDL_Rect& rect, int z, Uint8 r, Uint8 g, Uint8 b, Uint8 a, bool use_camera)
{
	bool ret = true;

	int y = rect.y;

	SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
	SDL_SetRenderDrawColor(renderer, r, g, b, a);

	SDL_Rect rec(rect);
	if (use_camera)
	{
		rec.x = (int)(camera.x + rect.x * SCREEN_SIZE);
		y += z * (int)round(cos(OFFSET_ANGLE));
		rec.y = (int)(camera.y + y * SCREEN_SIZE);
		rec.w *= SCREEN_SIZE;
		rec.h *= SCREEN_SIZE;
	}

	if (SDL_RenderFillRect(renderer, &rec) != 0)
	{
		LOG("Cannot draw quad to screen. SDL_RenderFillRect error: %s", SDL_GetError());
		ret = false;
	}

	return ret;
}
