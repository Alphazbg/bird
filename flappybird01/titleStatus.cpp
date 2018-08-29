#include "stdafx.h"
#include "titleStatus.h"
#include "status.h"
#include <graphics.h>
#include <conio.h>

void title_update(int dt)
{
	if (_kbhit())
		if (_getch() == ' ') {
			setStatus(PlayState);
		}
}

void title_render()
{
	settextcolor(RGB(255, 153, 238));
	settextstyle(56, 0, _T("Ink Free"));
	outtextxy(140, 90,  _T("flappy bird"));
}


