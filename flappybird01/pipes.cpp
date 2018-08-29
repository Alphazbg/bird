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
time_t t;

int spawnTimer;

struct Pipe pipes[PIPES_LEN]; 
void pipes_init()
{
	pipe_init();
	head = tail = 0;
	srand(unsigned(&t));
	lastY =  rand() % (WINDOW_HEIGHT/2) + 20;
	for (int i = 0; i < PIPES_LEN; i++) {
		initPipe(&pipes[i], 0, 0, 1, 0);
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
		if (y > WINDOW_HEIGHT - 90 )
			y = WINDOW_HEIGHT - 90;
		if (y <  20)
			y = 20;
		
		if (y > 3 * WINDOW_WIDTH / 4)
			orientation = BUTTOM;
		else if (y < WINDOW_WIDTH / 4)
			orientation = TOP;
		else
		orientation = ALL;

		pipelist_enqueue(x, y, 0, orientation);
		spawnTimer = 0;
	}
	while (pipes[head].remove == 1 && tail != head) pipelist_dequeue();
	for (int i = 0; i < PIPES_LEN; i++) {
		if (pipes[i].remove == 0){
			pipe_update(&pipes[i], dt);
			/*if (bird_collides(&pipes[i]))
				setStatus(TitleScreenState);*/
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

void pipelist_enqueue(int x,int y,int remove,int orientation )
{
	if (head != tail + 1) {
		initPipe(&pipes[tail], x, y, remove, orientation);
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


