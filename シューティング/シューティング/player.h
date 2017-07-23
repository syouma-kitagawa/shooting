#ifndef PLAYER
#define PLAYER

#include "GameScene.h"

#define MOVE_SPEED 5.f

struct PLAYER_STATE
{
	float Posx, Posy, scale;
};

void playerControl(void);

void playerDraw();



#endif 

