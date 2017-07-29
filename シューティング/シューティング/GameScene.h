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

// �Q�[���V�[���̏������֐�
void GameSceneInit();

void GameSceneDraw();
//	�Q�[���V�[���̉摜�������Ă����z��
extern LPDIRECT3DTEXTURE9	g_pGameTexture[GAMESCENE_MAX];
extern LPDIRECT3D9			g_pDirect3D;		// DirectX�I�u�W�F�N�g�̃|�C���^
extern LPDIRECT3DDEVICE9	g_pDirect3DDevice;	// DirectX�f�o�C�X�̃|�C���^

#endif 

