#pragma once

#ifndef HEADER_H
#define HEADER_H

// include perpustakaan
#define WIN32_LEAN_AND_MEAN
#define BUTTONDOWN(name, key) (name.rgbButtons[key] & 0x80)

#define MyWindowWidth 1600
#define MyWindowHeight 900

#include <iostream>
#include <Windows.h>
#include <d3d9.h>
#include <d3dx9.h>
#include <dinput.h>
#include <stack>

#pragma comment (lib, "d3d9.lib") // this code is NOT standard C++ -> cannot use this code on Linux, only works on Windows
#pragma comment (lib, "d3dx9.lib") // this code is NOT standard C++ -> cannot use this code on Linux, only works on Windows
#pragma comment (lib, "dinput8.lib")
#pragma comment (lib, "dxguid.lib")
#pragma comment (lib, "fmod_vc.lib")

// classes
#include "Game.h"
#include "AudioManager.h"
#include "FrameTimer.h"

using namespace std;

// externs
extern stack<Game*> games; // game stack
extern IDirect3DDevice9* d3dDevice; // DirectX device
extern LPD3DXSPRITE sprite; // sprite brush
extern LPDIRECTINPUT8 dInput; // DirectX input
extern LPDIRECTINPUTDEVICE8 dInputKeyboardDevice; // DirectX Keyboard Device
extern BYTE diKeys[256]; // snapshot of keyboard
extern LPDIRECTINPUTDEVICE8 dInputMouseDevice; // DirectX Mouse Device
extern DIMOUSESTATE mouseState;
extern AudioManager* audioManager;
extern LPD3DXFONT font; // font brush
extern float PI; // value of PI (used for angle calculation)

// absolute mouse position values
extern int mouseX;
extern int mouseY;

#endif
