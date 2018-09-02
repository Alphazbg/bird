#include "stdafx.h"
#include "status.h"
#include "bird.h"
#include "pipes.h"


void play_init()
{
	play_enter();
}

void play_enter()
{
	bird_init();
	pipes_init();
}



void play_update(int dt)
{
	bird_update(dt);
	pipes_update(dt);
}

void play_render()
{
	bird_render();
	pipes_render();

}
