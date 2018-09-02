#pragma once

#define TitleStatus	0
#define CountStatus	1
#define PlayStatus	2
#define ScoreStatus	3
#define EndStatus	4


void statusChange(int status);
int  currentStatus();



void title_update(int dt);
void title_render();

void count_init();
void count_enter();
void count_update(int dt);
void count_render();

void play_init();
void play_enter();
void play_update(int dt);
void play_render();

//SCore Status

extern int score;

void score_init();
void score_enter(int params);

void score_update(int dt);

void score_render();