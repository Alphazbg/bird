#include "stdafx.h"
#include <graphics.h>
#include <conio.h>
#include "status.h"
#include "bird.h"
#include "pipes.h"
#include "scence.h"

int status;
void statusChange(int s)
{
	status = s;
}

int currentStatus()
{
	return status;
}



// Title Status

void title_init()
{
	play_enter();
}

void title_update(int dt)
{
	play_enter();
	if (_kbhit())
		if (_getch() == '\r') {
			count_enter();
			statusChange(CountStatus);
		}
}


void title_render()
{
	settextcolor(RGB(217, 87, 99));
	setbkmode(TRANSPARENT);
	settextstyle(56, 0, _T("Impact"));
	outtextxy(140, 90, _T("Flappy bird"));

	settextstyle(28, 0, _T("Ink Free"));
	outtextxy(240, 160, _T("Press enter"));

	settextcolor(RGB(255, 187, 119));
	settextstyle(12, 0, _T("Ink Free"));
	outtextxy(340, 200, _T("v0.1 by hao"));



}

//Count Status

int COUNTDOWN_TIME = 10;
int count;
int timer;

void count_init()
{
	count_enter();
}

void count_enter()
{

	count = 3;
	timer = 0;
}

void count_update(int dt)
{
	timer = timer + dt;
	if (timer > COUNTDOWN_TIME)
	{
		timer = timer % COUNTDOWN_TIME;
		count = count - 1;
	}
	if (count == 0) {
		play_enter();
		statusChange(PlayStatus);
	}


}

void count_render()
{
	settextcolor(RGB(255, 255, 255));
	settextstyle(72, 0, _T("Comic Sans MS"));
	TCHAR s[50];
	_stprintf_s(s, _T("%d"), count);
	outtextxy(240, 140, s);

}




//Play Status

void play_init()
{
	bird_init();
	pipes_init();
	play_enter();
}

void play_enter()
{
	bird_enter();
	pipes_enter();
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


int score;
void score_enter(int params)
{
	score = params;
}

void score_init()
{
	play_enter();
}

void score_update(int dt)
{
	if (_kbhit())
		if (_getch() == '\r') {
			count_enter();
			statusChange(CountStatus);
		}
}

void score_render()
{

	settextstyle(56, 0, _T("Comic Sans MS"));
	outtextxy(140, 80, _T("You Lost!!"));

	TCHAR s[50];

	_stprintf_s(s, _T("Score: %d"), score);
	settextstyle(28, 0, _T("Ink Free"));
	settextcolor(RGB(255, 255, 255));
	outtextxy(240, 160, s);

	settextcolor(RGB(255, 187, 119));
	outtextxy(120, 200, _T("Press Enter play again."));

}