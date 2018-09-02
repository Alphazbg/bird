#include "stdafx.h"
#include "pipes.h"
#include "scence.h"
#include <stdlib.h>
#include <time.h>
#include "bird.h"
#include "status.h"


int head;
int tail;

int lastY;

int spawnTimer;
int scrolling = true;

struct Pipe pipes[PIPES_LEN]; 
void pipes_init()
{
	pipe_init();
}

void pipes_enter()
{
	score = 0;
	head = tail = 0;
	lastY = WINDOW_HEIGHT / 2 - rand() % (WINDOW_HEIGHT / 2 - 60) + 20;
	for (int i = 0; i < PIPES_LEN; i++) {
		initPipe(&pipes[i], 0, 0, 0, 1, 0);
	}
}

void pipes_update(int dt)
{
	int x,y;
	int orientation;

	spawnTimer = spawnTimer + dt;
	if (spawnTimer > (rand()%10 + 20))
	{
   		x = WINDOW_WIDTH + PIPE_WIDTH;
       	y = lastY + rand() % 80 - 40;
		if (y > WINDOW_HEIGHT - 40 )
			y = WINDOW_HEIGHT - 40;
		if (y <  20)
			y = 20;
		
		if (y > 3 * WINDOW_HEIGHT / 4 - 20 && y < WINDOW_HEIGHT - 60) {
			orientation = TOP;
			y -= PIPE_HEIGHT;
		}
			
		else if (y < WINDOW_HEIGHT / 4 && y > 40)
			orientation = BUTTOM;
		else 
			orientation = ALL;
		lastY = y;
		pipelist_enqueue(x, y, 0,0, orientation);
		spawnTimer = 0;
	}
	while (pipes[head].remove == 1 && tail != head) pipelist_dequeue();
	for (int i = 0; i < PIPES_LEN; i++) {
		if (pipes[i].remove == 0){
   			pipe_update(&pipes[i], dt);
			if (pipes[i].scored == 0) {
				bird_score(&pipes[i]);
			}
			if (bird_collides(&pipes[i]))
			{
				//scrolling = false;
				statusChange(ScoreStatus);
			}
  				
		}
	}

}

void pipes_render()
{
	for (int i = 0; i < PIPES_LEN; i++) {
		if (pipes[i].remove == 0)
      			pipe_render(&pipes[i]);
	}
}

void pipelist_enqueue(int x,int y,int scored,int remove,int orientation )
{
	if (head != tail + 1) {
		initPipe(&pipes[tail], x, y,scored, remove, orientation);
		if (tail == PIPES_LEN - 1)
			tail = 1;
		else
			tail++;
	}

}

void  pipelist_dequeue()
{
	if (head != tail)
	{
		pipes[head].remove = 1;
		if (head == PIPES_LEN - 1)
			head = 1;
		else
			head = head + 1;
	}

}


