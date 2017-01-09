#ifndef __MODULERENDER_H__
#define __MODULERENDER_H__

#include "Module.h"
#include "Globals.h"
#include <queue>

struct SDL_Texture;
struct SDL_Renderer;
struct SDL_Rect;

using namespace std;

struct RenderGameObject {
	SDL_Texture* texture;
	SDL_Rect* section;
	SDL_Rect* rect;
	int priority;
	bool flipped;
};

struct OrderByZ {
	bool operator()(const RenderGameObject* lhs, const RenderGameObject* rhs) {
		return lhs->priority > rhs->priority;
	}
};

class ModuleRender : public Module
{
public:
	ModuleRender();
	~ModuleRender();

	bool Init();
	update_status PreUpdate();
	update_status Update();
	update_status PostUpdate();
	bool CleanUp();

	bool Blit(SDL_Texture* texture, int x, int y, SDL_Rect* section, float speed = 1.0f);
	void PriorityBlit(SDL_Texture* texture, int x, int y, int priority, SDL_Rect* section, float speed = 1.0f, bool flipped=false);
	void PriorityBlit3D(SDL_Texture* texture, int x, int y, int z, SDL_Rect* section, float speed, bool flipped);
	bool Blit3D(SDL_Texture* texture, int x, int y, int z, SDL_Rect* section, float speed = 1.0f);
	bool MyBlit(SDL_Texture* texture, int x, int y, int z, SDL_Rect* section, float speed = 1.0f, bool flipped=false);
	bool DrawQuad(const SDL_Rect& rect, Uint8 r, Uint8 g, Uint8 b, Uint8 a, bool use_camera = true);
	bool DrawQuad3D(const SDL_Rect& rect, int z, Uint8 r, Uint8 g, Uint8 b, Uint8 a, bool use_camera = true);

public:
	SDL_Renderer* renderer = nullptr;
	SDL_Rect camera;
	bool debug = false;

private:
	priority_queue<RenderGameObject*, std::vector<RenderGameObject*>, OrderByZ> priority_queue_renderer;

};

#endif // __MODULERENDER_H__