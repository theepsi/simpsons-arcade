#include "Globals.h"
#include "core.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModuleCollision.h"

using namespace std;

bool collisionMatrix[4][4] = {
	{false, true, true, false},
	{true, false, true, false},
	{true, true, true, false},
	{false, false, false, false}
};

ModuleCollision::ModuleCollision()
{
}

// Destructor
ModuleCollision::~ModuleCollision()
{}

update_status ModuleCollision::PreUpdate()
{
	// Remove all colliders scheduled for deletion
	for (list<Collider*>::iterator it = colliders.begin(); it != colliders.end();)
	{
		if ((*it)->to_delete == true)
		{
			RELEASE(*it);
			it = colliders.erase(it);
		}
		else
			++it;
	}

	return UPDATE_CONTINUE;
}

update_status ModuleCollision::Update()
{
	// After making it work, review that you are doing the minumum checks possible
	for (list<Collider*>::iterator it = colliders.begin(); it != colliders.end(); ++it)
	{
		Collider* col = (*it);
		for (list<Collider*>::iterator it2 = ++it; it2 != colliders.end(); ++it2)
		{
			Collider* col2 = (*it2);
			if (collisionMatrix[col->col_against][col2->col_against] && col->CheckCollision(col2->rect)) {
				//TODO: Notification stuff
			}
		}
	}

	if(App->input->GetKey(SDL_SCANCODE_F1) == KEY_DOWN)
		debug = !debug;

	if(debug == true)
		DebugDraw();

	return UPDATE_CONTINUE;
}

void ModuleCollision::DebugDraw()
{
	for (list<Collider*>::iterator it = colliders.begin(); it != colliders.end(); ++it)
		App->renderer->DrawQuad((*it)->rect, 255, 0, 0, 80);
}

// Called before quitting
bool ModuleCollision::CleanUp()
{
	LOG("Freeing all colliders");

	for (list<Collider*>::iterator it = colliders.begin(); it != colliders.end(); ++it)
		RELEASE(*it);

	colliders.clear();

	return true;
}

Collider* ModuleCollision::AddCollider(const SDL_Rect& rect)
{
	Collider* ret = new Collider(rect);

	colliders.push_back(ret);

	return ret;
}

// -----------------------------------------------------

bool Collider::CheckCollision(const SDL_Rect& r) const
{
	// Return true if the argument and the own rectangle are intersecting
	return !((rect.x+rect.w) > r.x || (r.x + r.w) > rect.x || (r.x + r.h) > rect.x || (rect.x + rect.h) > r.x);
}
