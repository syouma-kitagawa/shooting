#ifndef KEYBOARDCHECK
#define KEYBOARDCHECK

#include "GameScene.h"
#include "player.h"

#include <mmsystem.h>
#include <dinput.h>


enum KEYSTATE {
	KEY_PUSH,
	KEY_RELEASE,
	KEY_ON,
	KEY_OFF
};

enum KEYKIND
{
	KEY_LEFT,
	KEY_RIGHT,
	KEY_UP,
	KEY_DOWN,
	KEY_A,
	KEY_B,
	KEY_C,
	KEY_D,
	KEY_E,
	KEY_F,
	KEY_G,
	KEY_H,
	KEY_I,
	KEY_J,
	KEY_K,
	KEY_L,
	KEY_M,
	KEY_N,
	KEY_O,
	KEY_P,
	KEY_Q,
	KEY_R,
	KEY_S,
	KEY_T,
	KEY_U,
	KEY_V,
	KEY_W,
	KEY_X,
	KEY_Y,
	KEY_Z,
	KEY_SPACE,
	KEY_ESC,
	KEYMAX
};

extern LPDIRECTINPUTDEVICE8	     g_pKeyDevice;
extern LPDIRECTINPUT8			 g_pDInput;

void KeyCheck(KEYSTATE* Key, int DIK);

HRESULT InitDInput();

HRESULT InitDInputKey(HWND hWnd);

void ReleaseDInput();


#endif 

