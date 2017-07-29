#ifndef BULLET
#define BULLET


#define BOMBNUM 100
#define BSPEED 5

struct Bullet {
	float x, y;
	bool bulletFlg;
};


Bullet bulletBoll[];

void bulletInit();
void bulletDraw();

#endif 

