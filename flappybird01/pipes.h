#pragma once

#include "pipe.h"

#define PIPES_LEN 10

extern int scrolling;

void pipes_init();
void pipes_enter();
void pipes_update(int dt);
void pipes_render();
void pipelist_enqueue(int x, int y, int scored,int remove, int orientation);
void pipelist_dequeue();

