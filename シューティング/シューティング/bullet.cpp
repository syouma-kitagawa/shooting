#include "GameScene.h"
#include "bullet.h"

Bullet bulletBoll[BOMBNUM];

CUSTOMVERTEX bulletDR[4];

  //����������
void bulletInit()
{
	for(int i = 0; i < 100; i++)
	{
		bulletBoll[i].x = bulletBoll[i].y = 0.0f;
		bulletBoll[i].bulletFlg = false;
	}
}
void bulletDraw()
{
	// �o�b�N�O���E���h�̒��_�����쐬����
	CUSTOMVERTEX bullet[4]
	{
		{ 0.f,   0.f,   1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
		{ 50.f, 0.f,   1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
		{ 50.f, 50.f, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
		{ 0.f,   50.f, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }
	};

	for (int i = 0; i < BOMBNUM; i++)
	{
		bulletDR[0].x += bulletBoll[i].x-50;
		bulletDR[1].x += bulletBoll[i].x+50;
		bulletDR[2].x += bulletBoll[i].x+50;
		bulletDR[3].x += bulletBoll[i].x-50;
		bulletDR[0].y += bulletBoll[i].y-50;
		bulletDR[1].y += bulletBoll[i].y-50;
		bulletDR[2].y += bulletBoll[i].y+50;
		bulletDR[3].y += bulletBoll[i].y+50;
		bulletDR[i].y += BSPEED;
	}

	// �e�N�X�`�����X�e�[�W�Ɋ��蓖�Ă�
	g_pDirect3DDevice->SetTexture(0, g_pGameTexture[BULLET_TEX]);
	// �`��
	g_pDirect3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, bulletDR, sizeof(CUSTOMVERTEX));

}
