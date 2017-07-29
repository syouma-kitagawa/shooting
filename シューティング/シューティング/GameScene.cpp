#include"GameScene.h"
#include "keyboardcheck.h"
#include "player.h"
#include "bullet.h"
//	ゲームシーンの画像情報を入れておく配列
LPDIRECT3DTEXTURE9			g_pGameTexture[GAMESCENE_MAX];

// ゲームシーンの描画関数
void GameSceneDraw()
{
	// バックグラウンドの頂点情報を作成する
	CUSTOMVERTEX backGround[4]
	{
		{ 0.f,   0.f,   1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
		{ 1280.f, 0.f,   1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
		{ 1280.f, 720.f, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
		{ 0.f,   720.f, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }
	};


	// 頂点情報の指定
	g_pDirect3DDevice->SetFVF(D3DFVF_CUSTOMVERTEX);

	// 画面の消去
	g_pDirect3DDevice->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(0x00, 0x00, 0x00), 1.0, 0);
	// 描画を開始
	g_pDirect3DDevice->BeginScene();

	bulletDraw();

	// テクスチャをステージに割り当てる
	g_pDirect3DDevice->SetTexture(0, g_pGameTexture[BACKGROUND_TEX]);
	// 描画
	g_pDirect3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, backGround, sizeof(CUSTOMVERTEX));

	playerDraw();
	
	// 描画を終了
	g_pDirect3DDevice->EndScene();
	// 画面に表示
	g_pDirect3DDevice->Present(NULL, NULL, NULL, NULL);
}

// ゲームシーンの初期化関数
void GameSceneInit()
{
	// 描画の設定
	g_pDirect3DDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, true);
	g_pDirect3DDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);  //SRCの設定
	g_pDirect3DDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
	g_pDirect3DDevice->SetRenderState(D3DRS_DIFFUSEMATERIALSOURCE, D3DMCS_COLOR1);

	g_pDirect3DDevice->SetTextureStageState(0, D3DTSS_COLORARG1, D3DTA_TEXTURE);
	g_pDirect3DDevice->SetTextureStageState(0, D3DTSS_COLORARG2, D3DTA_DIFFUSE);

	g_pDirect3DDevice->SetTextureStageState(0, D3DTSS_COLOROP, D3DTOP_MODULATE);

	g_pDirect3DDevice->SetTextureStageState(0, D3DTSS_ALPHAARG1, D3DTA_TEXTURE);
	g_pDirect3DDevice->SetTextureStageState(0, D3DTSS_ALPHAARG2, D3DTA_DIFFUSE);

	g_pDirect3DDevice->SetTextureStageState(0, D3DTSS_ALPHAOP, D3DTOP_MODULATE);


	// テクスチャを読込
	D3DXCreateTextureFromFile(
		g_pDirect3DDevice,
		"space.png",
		&g_pGameTexture[BACKGROUND_TEX]);

	// プレイヤーの読み込み
	D3DXCreateTextureFromFileEx(
		g_pDirect3DDevice,
		"player.png",              // ファイル名
		0,
		0,
		0,
		0,
		D3DFMT_A1R5G5B5,                // 色抜きを可能に
		D3DPOOL_MANAGED,
		D3DX_FILTER_LINEAR,
		D3DX_FILTER_LINEAR,
		D3DCOLOR_ARGB(255, 0, 255, 0),  //緑を透過
		NULL,
		NULL,
		&g_pGameTexture[PLAYER_TEX]           // テクスチャ名
	);
	//弾の読み込み
	D3DXCreateTextureFromFileEx(
		g_pDirect3DDevice,
		"bullet.png",              // ファイル名
		0,
		0,
		0,
		0,
		D3DFMT_A1R5G5B5,                // 色抜きを可能に
		D3DPOOL_MANAGED,
		D3DX_FILTER_LINEAR,
		D3DX_FILTER_LINEAR,
		D3DCOLOR_ARGB(255, 0, 255, 0),  //緑を透過
		NULL,
		NULL,
		&g_pGameTexture[BULLET_TEX]           // テクスチャ名
	);


	
}