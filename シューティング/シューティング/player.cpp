#include "GameScene.h"
#include "player.h"
#include "keyboardcheck.h"
#include "bullet.h"
KEYSTATE g_Key[KEYMAX] = { KEY_OFF };

PLAYER_STATE		  g_Player = { 600.f, 550.f,50.f };


/**
*制御処理
*/
void playerControl(void)
{
	KeyCheck(&g_Key[KEY_W], DIK_W);
	KeyCheck(&g_Key[KEY_A], DIK_A);
	KeyCheck(&g_Key[KEY_S], DIK_S);
	KeyCheck(&g_Key[KEY_D], DIK_D);
	KeyCheck(&g_Key[KEY_Z], DIK_Z);

	if (g_Key[KEY_W] == KEY_ON)
	{
		g_Player.Posy -= MOVE_SPEED;
	}

	if (g_Key[KEY_A] == KEY_ON)
	{
		g_Player.Posx -= MOVE_SPEED;
	}

	if (g_Key[KEY_S] == KEY_ON)
	{
		g_Player.Posy += MOVE_SPEED;
	}

	if (g_Key[KEY_D] == KEY_ON)
	{
		g_Player.Posx += MOVE_SPEED;
	}
	if (g_Key[KEY_Z] == KEY_ON)
	{
		for (int i = 0; i < BOMBNUM; i++)
		{
			if (bulletBoll[i].bulletFlg=false)
			{
				bulletBoll[i].bulletFlg = true;
				bulletBoll[i].x = g_Player.Posx;
				bulletBoll[i].y = g_Player.Posy;
			}
		}
		bulletDraw();
	}
}
void playerDraw()
{

	CUSTOMVERTEX player[4]
	{
		{ g_Player.Posx - g_Player.scale, g_Player.Posy - g_Player.scale, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
		{ g_Player.Posx + g_Player.scale, g_Player.Posy - g_Player.scale, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
		{ g_Player.Posx + g_Player.scale, g_Player.Posy + g_Player.scale, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
		{ g_Player.Posx - g_Player.scale, g_Player.Posy + g_Player.scale, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }
	};

	// テクスチャをステージに割り当てる
	g_pDirect3DDevice->SetTexture(0, g_pGameTexture[PLAYER_TEX]);
	// 描画
	g_pDirect3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, player, sizeof(CUSTOMVERTEX));
}