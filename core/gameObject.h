#ifndef _GAME_OBJECT
#define _GAME_OBJECT

#include "ModuleCollision.h"
#include "point3D.h"

enum GameObjectType {
	PLAYER_ENTITY,
	ENEMY_ENTITY,
	SCENARY_ENTITY,
	UNKNOWN_ENTITY
};

class GameObject {
public:
	GameObject() {}
	virtual ~GameObject() {}

	virtual bool Start() {
		return true;
	}

	virtual void PreUpdate() = 0;

	virtual void Update() = 0;

	virtual void PostUpdate() = 0;

	virtual bool CleanUp() = 0;

	virtual bool OnEnterCollision(Collider& source, Collider& affected) = 0;

	bool IsEnabled()
	{
		return enabled;
	}

	void SetEnabled(bool enable) {
		enabled = enable;
	}

	iPoint3D position;
	GameObjectType type = GameObjectType::UNKNOWN_ENTITY;
private:
	//GameObject true by default
	bool enabled = true;
};

#endif
