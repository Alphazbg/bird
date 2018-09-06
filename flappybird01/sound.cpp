#include "stdafx.h"
#include "sound.h"
#include "string.h"
#include <graphics.h>

TCHAR open_string[50];
TCHAR play_string[50];

void sound_play(TCHAR* path, wchar_t * name, int repeat)
{
	wchar_t srepeat[] = _T("repeat");

	_stprintf_s(open_string, _T("open %s alias %s"), path, name);
	_stprintf_s(play_string, _T("play %s %s"),name,repeat? srepeat:_T(""));
	mciSendString(open_string, NULL, 0, NULL);
	mciSendString(play_string, NULL, 0, NULL);
}

void sound_close(wchar_t * name)
{
	TCHAR close_string[50];
	_stprintf_s(close_string, _T("close %s"), name);
	mciSendString(close_string, NULL, 0, NULL);
	
}
