#pragma once
#include "pipe.h"
#define BIRD_WIDTH  34
#define BIRD_HEIGHT  24

void bird_init();
void bird_enter();
void bird_update(int dt);
void bird_render();
int isCollides(int x, int y);


int bird_collides(Pipe *pipe);
void bird_score(Pipe *pipe);
