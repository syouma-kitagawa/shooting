#include "GameScene.h"
#include "keyboardcheck.h"

LPDIRECTINPUTDEVICE8	 g_pKeyDevice = NULL;
LPDIRECTINPUT8			 g_pDInput = NULL;

HRESULT InitDInput()
{
	HRESULT hr;

	//�uDirectInput�v�I�u�W�F�N�g�̍쐬
	if (FAILED(hr = DirectInput8Create(GetModuleHandle(NULL),
		DIRECTINPUT_VERSION, IID_IDirectInput8, (VOID**)&g_pDInput, NULL)))
	{
		return hr;
	}

	return S_OK;
}

void KeyCheck(KEYSTATE* Key, int DIK)
{
	BYTE diks[256];
	static BYTE old_diks[256] = { KEY_OFF };

	HRESULT hr = g_pKeyDevice->Acquire();
	if ((hr == DI_OK) || (hr == S_FALSE))
	{
		g_pKeyDevice->GetDeviceState(sizeof(diks), &diks);

		if (diks[DIK] & 0x80)
		{
			if (old_diks[DIK] == KEY_OFF)
			{
				*Key = KEY_PUSH;
				old_diks[DIK] = KEY_ON;
			}
			else
			{
				*Key = KEY_ON;
				old_diks[DIK] = KEY_ON;
			}
		}
		else
		{
			if (old_diks[DIK] == KEY_ON)
			{
				*Key = KEY_RELEASE;
				old_diks[DIK] = KEY_OFF;
			}
			else
			{
				*Key = KEY_OFF;
				old_diks[DIK] = KEY_OFF;
			}
		}
	}
}

HRESULT InitDInputKey(HWND hWnd)
{
	HRESULT hr;

	//�L�[�{�[�h�̏�����
	if (FAILED(hr = g_pDInput->CreateDevice(GUID_SysKeyboard,
		&g_pKeyDevice, NULL)))
	{
		return hr;
	}

	//�f�[�^�t�H�[�}�b�g
	if (FAILED(hr = g_pKeyDevice->SetDataFormat(&c_dfDIKeyboard)))
	{
		return hr;
	}

	//�������x��
	if (FAILED(hr = g_pKeyDevice->SetCooperativeLevel(
		hWnd, DISCL_NONEXCLUSIVE | DISCL_BACKGROUND)))
	{
		return hr;
	}


	g_pKeyDevice->Acquire();
	return S_OK;
}

void ReleaseDInput()
{
	if (g_pDInput != NULL)
	{
		g_pDInput->Release();
		g_pDInput = NULL;
	}
}