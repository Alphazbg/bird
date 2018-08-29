#pragma once
#include "pipe.h"
#define BIRD_WIDTH  34
#define BIRD_HEIGHT  24

void bird_init();
void bird_update(int dt);
void bird_render();


int  bird_collides(Pipe *pipe);
