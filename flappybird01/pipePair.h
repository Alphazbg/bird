#pragma once
#include "pipe.h"

struct PipPair {
	Pipe top_p;
	Pipe buttom_p;
};

void setPipPair(PipPair * pp,int x, int y);
void pipePair_init(PipPair *pp);
void pipPair_update(PipPair *pp);
void pipPair_render(PipPair *pp);
