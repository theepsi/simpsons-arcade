#ifndef __ModuleCollision_H__
#define __ModuleCollision_H__

#include <list>
#include "Module.h"

// Example: lasers should not collide with lasers but should collider with walls
// enemy shots will collide with other enemies ? and against walls ?

class Notify {
public:
	Notify();
};

enum CollisionAgainst {
	PLAYER_COLLISION,
	ENEMY_COLLISION,
	WALL_COLLISION,
	UNKOWN_COLLISION
};

extern bool collisionMatrix[4][4];

struct Collider
{
	SDL_Rect rect = { 0,0,0,0 };
	bool to_delete = false;
	CollisionAgainst col_against = UNKOWN_COLLISION;
	// TODO 10: Add a way to notify other classes that a collision happened

	Collider(SDL_Rect rectangle) : // expand this call if you need to
		rect(rectangle)
	{}

	void SetPos(int x, int y)
	{
		rect.x = x;
		rect.y = y;
	}

	bool CheckCollision(const SDL_Rect& r) const;
};

class ModuleCollision : public Module
{
public:

	ModuleCollision();
	~ModuleCollision();

	update_status PreUpdate();
	update_status Update();

	bool CleanUp();

	Collider* AddCollider(const SDL_Rect& rect);
	void DebugDraw();

private:

	std::list<Collider*> colliders;
	bool debug = false;
};

#endif // __ModuleCollision_H__