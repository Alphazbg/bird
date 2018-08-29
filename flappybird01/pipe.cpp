#include "stdafx.h"
#include "pipe.h"
#include "scence.h"
#include <graphics.h>
#include <stdlib.h>
#include <time.h>


IMAGE pipe_image, pipe_mask_image;


int randPipeType()
{
	return rand() % 3;
}

void pipe_init()
{

	loadimage(&pipe_image, _T("pipe.jpg"));
	loadimage(&pipe_mask_image, _T("pipe_mask.jpg"));

}

void initPipe(Pipe *pipe, int x, int y, int remove, int orientation)
{
	pipe->x = x;
	pipe->y = y;
	pipe->remove = remove;
	pipe->orientation = orientation;
}



void pipe_update(Pipe * pipe,int dt)
{
	if (pipe->x > -1 * PIPE_WIDTH)
		pipe->x -= PIPE_SPEED * dt;
	else
		pipe->remove = 1;
}

void pipe_render(Pipe * pipe)
{
	IMAGE pipe_top, pipe_mask_top;
	if (pipe->orientation == TOP)
	{
		rotateimage(&pipe_top, &pipe_image, PI);
		rotateimage(&pipe_mask_top, &pipe_mask_image, PI);

		putimage(pipe->x, pipe->y - PIPE_HEIGHT, &pipe_mask_top, NOTSRCERASE);
		putimage(pipe->x, pipe->y - PIPE_HEIGHT, &pipe_top, SRCINVERT);
	}
	else if(pipe->orientation == BUTTOM){
		putimage(pipe->x, pipe->y, &pipe_mask_image, NOTSRCERASE);
		putimage(pipe->x, pipe->y, &pipe_image, SRCINVERT);
	}

	else {
		rotateimage(&pipe_top, &pipe_image, PI);
		rotateimage(&pipe_mask_top, &pipe_mask_image, PI);

		putimage(pipe->x, pipe->y - PIPE_HEIGHT, &pipe_mask_top, NOTSRCERASE);
		putimage(pipe->x, pipe->y - PIPE_HEIGHT, &pipe_top, SRCINVERT);

		putimage(pipe->x, pipe->y + GAP_HEIGHT, &pipe_mask_image, NOTSRCERASE);
		putimage(pipe->x, pipe->y + GAP_HEIGHT, &pipe_image, SRCINVERT);
	}

	
}


