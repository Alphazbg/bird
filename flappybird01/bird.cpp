
#include "stdafx.h"
#include "bird.h"
#include "scence.h"
#include "status.h"
#include <graphics.h>
#include <conio.h>
#include "pipe.h"
#include "sound.h"


IMAGE bird, bird_mask;
int bird_x, bird_y;
int bird_width, bird_height;

int dy;

int GRAVITY = 1;

void bird_init()
{
	loadimage(&bird, _T("bird.jpg"));
	loadimage(&bird_mask, _T("bird_mask.jpg"));

	bird_enter();

}

void bird_enter()
{
	bird_x = WINDOW_WIDTH / 2 - bird.getwidth() / 2;
	bird_y = WINDOW_HEIGHT / 2 - bird.getheight() / 2;
	bird_width = bird.getwidth();
	bird_height = bird.getheight();
	FlushMouseMsgBuffer();
	fflush(stdin);
	dy = 0;
}

void bird_update(int dt)
{
	int c;

	dy = dy + GRAVITY * dt;
	bird_y = bird_y + dy;
	if (bird_y > WINDOW_HEIGHT - 15) {
		score_enter(score);
		statusChange(ScoreStatus);
	}
		

	if (_kbhit())
		if ((c = _getch()) == ' ')
		{
			dy = -5;
			wchar_t path[] = L"jump.wav";
			wchar_t name[] = L"jpmusic";
			sound_close(name);
			sound_play(path, name, 0);		
		}
		else if( c == 'q' || c ==  'Q')
		{
			statusChange(EndStatus);
		}
	while (MouseHit())
	{
		MOUSEMSG mouse;
		mouse = GetMouseMsg();
		switch (mouse.uMsg) {
			case WM_LBUTTONDOWN:
				dy = -5;
				wchar_t path[] = L"jump.wav";
				wchar_t name[] = L"jpmusic";
				sound_close(name);
				sound_play(path, name, 0);
				break;
		}
			
	}
}



void bird_render()
{
 	putimage(bird_x, bird_y, &bird_mask, NOTSRCERASE);
	putimage(bird_x, bird_y, &bird, SRCINVERT);

}

int bird_collides(Pipe *pipe) {

	if (pipe->orientation == TOP || pipe->orientation == BUTTOM)
		return isCollides(pipe->x, pipe->y);
	else
		return isCollides(pipe->x, pipe->y) || isCollides(pipe->x, pipe->y - PIPE_HEIGHT - GAP_HEIGHT);
	return 0;
}

void bird_score(Pipe *pipe)
{
	if (!pipe->scored) {
		if (pipe->x + PIPE_WIDTH < bird_x ) {
			score += 1;
			pipe->scored = 1;
		}
	}
	
}
int isCollides(int x, int y)
{
	if ((bird_x + 2) + (bird_width - 4) >= x && bird_x + 2 <= x + PIPE_WIDTH)
		if (((bird_y + 2) + (bird_height - 4)) >= y && (bird_y + 2 <= y + PIPE_HEIGHT))
			return 1;
	return 0;
}
