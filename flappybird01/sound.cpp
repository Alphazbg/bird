#include "stdafx.h"
#include "sound.h"
#include "string.h"
#include <graphics.h>




wchar_t open_string[50];
wchar_t play_string[50];

void sound_play(wchar_t * path, wchar_t * name, int repeat)
{
	wchar_t srepeat[] = L"repeat";

	wsprintf(open_string, L"open %s alias %s", path, name);
	wsprintf(play_string, L"play %s %s",name,repeat? srepeat:L"");
	mciSendString(open_string, NULL, 0, NULL);
	mciSendString(play_string, NULL, 0, NULL);
}

void sound_close(wchar_t * name)
{
	wchar_t close_string[50];
	wsprintf(close_string, L"close %s", name);
	mciSendString(close_string, NULL, 0, NULL);
	
}
