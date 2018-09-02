#include "stdafx.h"
#include "status.h"
#include "status.h"
#include "status.h"
#include "scence.h"
#include "status.h"
#include <graphics.h>
#include <conio.h>

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
	outtextxy(140, 90,  _T("Flappy bird"));

	settextstyle(28, 0, _T("Ink Free"));
	outtextxy(240, 160, _T("Press enter"));

	settextcolor(RGB(255, 187, 119));
	settextstyle(12, 0, _T("Ink Free"));
	outtextxy(340, 200, _T("v0.1 by hao"));
	


}


