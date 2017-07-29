#ifndef GAMESCENE
#define GAMESCENE

#define D3DFVF_CUSTOMVERTEX (D3DFVF_XYZRHW | D3DFVF_DIFFUSE | D3DFVF_TEX1)
#include <windows.h>
#include <d3d9.h>
#include <d3dx9.h>
#include <stdio.h>

struct CUSTOMVERTEX
{
	FLOAT	x, y, z, rhw;
	DWORD	color;
	FLOAT	tu, tv;
};

enum GAME_TEXTURE
{
	BACKGROUND_TEX,
	PLAYER_TEX,
	BULLET_TEX,
	GAMESCENE_MAX
};

// ゲームシーンの初期化関数
void GameSceneInit();

void GameSceneDraw();
//	ゲームシーンの画像情報を入れておく配列
extern LPDIRECT3DTEXTURE9	g_pGameTexture[GAMESCENE_MAX];
extern LPDIRECT3D9			g_pDirect3D;		// DirectXオブジェクトのポインタ
extern LPDIRECT3DDEVICE9	g_pDirect3DDevice;	// DirectXデバイスのポインタ

#endif 

