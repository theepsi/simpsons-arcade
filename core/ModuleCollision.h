#ifndef __ModuleCollision_H__
#define __ModuleCollision_H__

#include <list>
#include "Module.h"

// Example: lasers should not collide with lasers but should collider with walls
// enemy shots will collide with other enemies ? and against walls ?

enum CollisionAgainst {
	PLAYER_COLLISION,
	PLAYER_ATTACK_COLISION,
	ENEMY_COLLISION,
	ENEMY_ATTACK_COLISION,
	WALL_COLLISION,
	UNKOWN_COLLISION
};

class GameObject;

extern bool collisionMatrix[6][6];

struct Collider
{
	SDL_Rect rect = { 0,0,0,0 };
	int position_z;
	bool to_delete = false;
	CollisionAgainst col_against = UNKOWN_COLLISION;
	GameObject* referenced_object;

	Collider(SDL_Rect rectangle, int z, GameObject* game_object, CollisionAgainst col_against) : // expand this call if you need to
		rect(rectangle), position_z(z), referenced_object(game_object), col_against(col_against)
	{}

	void SetPos(int x, int y)
	{
		rect.x = x;
		rect.y = y;
	}

	bool CheckCollision(const SDL_Rect& r, int z) const;
};

class ModuleCollision : public Module
{
public:

	ModuleCollision();
	~ModuleCollision();

	update_status PreUpdate();
	update_status Update();

	bool CleanUp();

	Collider* AddCollider(const SDL_Rect& rect, int z, GameObject* game_object, CollisionAgainst col_against);
	void DebugDraw();

private:

	std::list<Collider*> colliders;
	bool debug = false;
};

#endif // __ModuleCollision_H__