#include "stdafx.h"
#include "scence.h"
#include <graphics.h>
#include "status.h"
#include "sound.h"
#include "string.h"

void scence_init()
{
	wchar_t path[] = L"marios_way.mp3";
	wchar_t name[] = L"bkmusic";
	initgraph(WINDOW_WIDTH, WINDOW_HEIGHT, SHOWCONSOLE);
	loadimage(&background, _T("background.jpg"));
	loadimage(&ground, _T("ground.jpg"));
	
	int repeat = 1;
	sound_play(path, name,repeat);

	
	play_init();
	statusChange(TitleStatus);

	BeginBatchDraw();
}

IMAGE background, ground;
