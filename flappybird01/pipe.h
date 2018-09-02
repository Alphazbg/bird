#pragma once

#define PIPE_SPEED 10
#define PIPE_WIDTH 70
#define PIPE_HEIGHT 288
#define GAP_HEIGHT  90

#define PI 3.1415

#define TOP 0
#define BUTTOM 1
#define ALL 2

struct Pipe {
	int x;
	int y;
	int scored;
	int remove;
	int orientation;
};

void pipe_init();
void pipe_update(struct Pipe *pipe,int dt);
void pipe_render(struct Pipe *pipe);
void initPipe(Pipe *pipe, int x, int y, int scored,int remove, int orientation);