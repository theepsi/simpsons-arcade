#include <math.h>
#include "ModuleParticles.h"
#include "core.h"
#include "ModuleAudio.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleCollision.h"

#include "SDL/include/SDL_timer.h"

ModuleParticles::ModuleParticles()
{}

ModuleParticles::~ModuleParticles()
{}

// Load assets
bool ModuleParticles::Start()
{
	LOG("Loading particles");
	graphics = App->textures->Load("rtype/particles.png");

	laser.fx_audio = App->audio->LoadFx("rtype/laser.wav");
	Animation laser_anim;
	laser_anim.frames.push_back({ 232, 103, 16, 12 });
	laser_anim.frames.push_back({ 249, 103, 16, 12 });
	laser_anim.speed = 0.1f;
	laser.animation = laser_anim;
	laser.speed = 5.0f;
	laser.life_time = 5000;
	laser.x = 0;
	laser.y = 0;


	// TODO 2: Create a prototype for the laser particle
	// audio: rtype/laser.wav
	// coords: {232, 103, 16, 12}; {249, 103, 16, 12};


	// TODO 12: Create a new "Explosion" particle 
	// audio: rtype/explosion.wav
	// coords: {274, 296, 33, 30}; {313, 296, 33, 30}; {346, 296, 33, 30}; {382, 296, 33, 30}; {419, 296, 33, 30}; {457, 296, 33, 30};

	return true;
}

update_status ModuleParticles::PreUpdate()
{
	// Remove all Particles scheduled for deletion
	for (list<Particle*>::iterator it = active.begin(); it != active.end();)
	{
		if ((*it)->to_delete == true)
		{
			RELEASE(*it);
			it = active.erase(it);
		}
		else
			++it;
	}

	return UPDATE_CONTINUE;
}

// Unload assets
bool ModuleParticles::CleanUp()
{
	LOG("Unloading particles");
	App->textures->Unload(graphics);

	for (list<Particle*>::iterator it = active.begin(); it != active.end(); ++it)
		RELEASE(*it);

	active.clear();

	return true;
}

// Update: draw background

//TODO: ENNIO PREUPDATE
update_status ModuleParticles::Update()
{
	for (list<Particle*>::iterator it = active.begin(); it != active.end();)
	{
		Particle* p = *it;

		if(p->Update() == false)
		{
			RELEASE(*it);
			it = active.erase(it);
		}
		else
		{
			App->renderer->Blit(graphics, (int) p->x, (int) p->y, &p->animation.GetCurrentFrame());
			++it;
		}
			
	}

	return UPDATE_CONTINUE;
}

void ModuleParticles::AddParticle(const Particle& particle, int x, int y)
{
	Particle* new_particle = new Particle(particle);
	new_particle->x = (float) x;
	new_particle->y = (float) y;
	new_particle->current_ticks = SDL_GetTicks();
	App->audio->PlayFx(new_particle->fx_audio);

	active.push_back(new_particle);
	// TODO 4: Fill in a method to create an instance of a prototype particle	
}

// -------------------------------------------------------------
// -------------------------------------------------------------

Particle::Particle()
{}

// TODO 3: Fill in a copy constructor
Particle::Particle(const Particle& p) 
{
	this->animation = p.animation;
	this->animation.Reset();
	this->fx_audio = p.fx_audio;
	this->life_time = p.life_time;
	this->speed = p.speed;
	this->x = p.x;
	this->y = p.y;

}

Particle::~Particle()
{
}

bool Particle::Update()
{
	bool ret = true;

	if(SDL_GetTicks() > (unsigned int)(current_ticks + life_time))
	{
		to_delete = true;
		ret = false;
	}

	//to_delete = life_time >= 0 && SDL_GetTicks() >= (current_ticks + life_time);

	// TODO 5: This is the core of the particle functionality.
	// Return false if the particle must be destroyed
	x += speed;

	return !to_delete;
}

