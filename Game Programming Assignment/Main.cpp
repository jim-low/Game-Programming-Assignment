#include <math.h>
#include "Header.h"
#include "DirectX.h"
#include "DirectInput.h"
#include "FrameTimer.h"
#include "Game.h"
#include "Level1.h"
#include "CreditsPage.h"
#include "MainMenu.h"
#include "WinPage.h"
#include "GameOverPage.h"
#include "SettingsPage.h"

HRESULT hr;

//Window's Global
HWND g_hWnd = NULL;
WNDCLASS wndClass;
//DX Global
IDirect3DDevice9* d3dDevice;

//Direct Input Global
LPDIRECTINPUT8 dInput;
LPDIRECTINPUTDEVICE8 dInputKeyboardDevice;
BYTE diKeys[256];
LPDIRECTINPUTDEVICE8 dInputMouseDevice;
DIMOUSESTATE mouseState;


// drawing things
LPD3DXSPRITE sprite = NULL;
LPD3DXFONT font = NULL;

// gaem things
stack<Game*> games;
AudioManager* audioManager;
DirectX* directX;
DirectInput* directInput;
FrameTimer* frameTimer;

float PI = atan(1.f) * 4;

int mouseX = 0;
int mouseY = 0;

LRESULT CALLBACK WindowProcedure(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {

	switch (message)
	{
	case WM_MOUSEMOVE:
		// get absolute mouse position
		mouseX = (short)LOWORD(lParam);
		mouseY = (short)HIWORD(lParam);
		break;
		//	The message is post when we destroy the window.
	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

void CreateMyWindow() {
	ZeroMemory(&wndClass, sizeof(wndClass));

	wndClass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndClass.hInstance = GetModuleHandle(NULL);
	wndClass.lpfnWndProc = WindowProcedure;
	wndClass.lpszClassName = "My Window";
	wndClass.style = CS_HREDRAW | CS_VREDRAW;

	RegisterClass(&wndClass);

	g_hWnd = CreateWindowEx(0, wndClass.lpszClassName, "Spaceship Game", WS_OVERLAPPEDWINDOW, 150, 80, MyWindowWidth, MyWindowHeight, NULL, NULL, GetModuleHandle(NULL), NULL);
	ShowWindow(g_hWnd, 1);
}

void InitializeLevel() {

	srand(time(0));


	if (FAILED(hr)) {
		cout << "Failed to create player texture." << endl;
	}
}

void InitializeSound() {
	audioManager = new AudioManager();
	audioManager->InitializeAudio();
}

void Update(int framesToUpdate) {
	for (int i = 0; i < framesToUpdate; i++) {
		games.top()->Update();
	}
}

int IfMyWindowIsRunning() {

	MSG msg;
	ZeroMemory(&msg, sizeof(msg));

	if (msg.message != WM_QUIT)
	{
		while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT) {
				return false;
			}
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}
	else {
		return false;
	}
	return true;
}

void CleanUpMyWindow() {
	UnregisterClass(wndClass.lpszClassName, GetModuleHandle(NULL));
}

int main() {
	CreateMyWindow();
	directX = new DirectX();
	directInput = new DirectInput();
	InitializeSound();

	frameTimer = new FrameTimer();
	frameTimer->Init(69);

	MainMenu* mainMenu = new MainMenu();
	games.push(mainMenu);

	while (IfMyWindowIsRunning())
	{
		audioManager->UpdateSound();
		games.top()->Input();
		Update(frameTimer->FramesToUpdate());
		games.top()->Render();
	}
	directInput->~DirectInput();
	directX->~DirectX();
	CleanUpMyWindow();
	return 0;
}

