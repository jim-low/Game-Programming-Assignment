#include "DirectInput.h"

DirectInput::~DirectInput()
{

	dInputKeyboardDevice->Unacquire();
	dInputKeyboardDevice->Release();
	dInputKeyboardDevice = NULL;

	dInputMouseDevice->Unacquire();
	dInputMouseDevice->Release();
	dInputMouseDevice = NULL;

	dInput->Release();
	dInput = NULL;

}

void DirectInput::Initialize()
{
	hr = DirectInput8Create(GetModuleHandle(NULL), 0x0800, IID_IDirectInput8, (void**)&dInput, NULL);

	hr = dInput->CreateDevice(GUID_SysKeyboard, &dInputKeyboardDevice, NULL);

	hr = dInput->CreateDevice(GUID_SysMouse, &dInputMouseDevice, NULL);

	dInputKeyboardDevice->SetDataFormat(&c_dfDIKeyboard);
	dInputMouseDevice->SetDataFormat(&c_dfDIMouse);

	dInputKeyboardDevice->SetCooperativeLevel(g_hWnd, DISCL_FOREGROUND | DISCL_NONEXCLUSIVE);
	dInputMouseDevice->SetCooperativeLevel(g_hWnd, DISCL_FOREGROUND | DISCL_NONEXCLUSIVE);
}

void DirectInput::GetInput()
{
	dInputKeyboardDevice->Acquire();
	dInputKeyboardDevice->GetDeviceState(256, diKeys);

	dInputMouseDevice->Acquire();
	dInputMouseDevice->GetDeviceState(sizeof(mouseState), &mouseState);
}

boolean DirectInput::IsKeyDown(int key)
{
	return diKeys[key] & 0x80;
}

boolean DirectInput::isMouseDown(int button)
{
	return (mouseState.rgbButtons[button] & 0x80);
}
