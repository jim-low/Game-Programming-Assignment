#include <sstream>
#include "WinPage.h"
#include "MainMenu.h"

void WinPage::Initialize(int score) {
	HRESULT hr = D3DXCreateTextureFromFile(d3dDevice, "../Assets/win_Title.png", &winTexture);
	if (FAILED(hr)) {
		std::cout << "Failed to create Title texture in Menu.";
		MessageBox(NULL, TEXT("Failed to create Title texture in Menu."), TEXT("ERROR!"), MB_YESNOCANCEL | MB_ICONQUESTION);
	}

	hr = D3DXCreateFont(d3dDevice, 40, 0, 0, 1, false, DEFAULT_CHARSET, OUT_TT_ONLY_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, "News Gothic", &font);
	if (FAILED(hr)) {
		std::cout << "Failed to create font.";
		MessageBox(NULL, TEXT("Failed to create font."), TEXT("ERROR!"), MB_YESNOCANCEL | MB_ICONQUESTION);
	}

	this->score = score;
	tempStr = "Your score: " + to_string(score);
	scoreStr = tempStr.c_str();
	scorePos = D3DXVECTOR2(0, 0);
	scoreRect.top = MyWindowHeight / 14 * 6;
	scoreRect.left = MyWindowWidth / 14 * 3;
	scoreRect.bottom = scoreRect.top + 100;
	scoreRect.right = scoreRect.left + 420;

	//initialize position 
	winWidth = 375;
	winHeight = 245;
	winRect.top = 0;
	winRect.bottom = winHeight;
	winRect.left = 0;
	winRect.right = winWidth;

	position = D3DXVECTOR2((MyWindowWidth/2) - (winWidth/2), (MyWindowHeight / 2) - (winHeight / 2)); 
	centre = D3DXVECTOR2(winWidth / 2, winHeight / 2);
	scaling = D3DXVECTOR2(1.8f, 1.8f);

	audioManager->PlayWinSoundTrack();
}

void WinPage::Render() {
	//clear screen
	d3dDevice->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(0, 0, 0), 1.0f, 0);

	//start screen 
	d3dDevice->BeginScene();

	//draw sprite
	sprite->Begin(D3DXSPRITE_ALPHABLEND);

	//set matrix to title

	D3DXMatrixTransformation2D(&winMat, &centre, 0.0, &scaling, NULL, NULL, &position);
	sprite->SetTransform(&winMat);
	sprite->Draw(winTexture, &winRect, NULL, NULL, D3DCOLOR_XRGB(255, 255, 255));

	D3DXMATRIX mat;
	D3DXMatrixTransformation2D(&mat, NULL, 0.0, &scaling, NULL, direction, &scorePos);
	sprite->SetTransform(&mat);
	font->DrawText(sprite, scoreStr, tempStr.length(), &scoreRect, DT_LEFT, D3DCOLOR_XRGB(255, 255, 255));

	sprite->End();

	//	End the scene
	d3dDevice->EndScene();

	//	Present the back buffer to screen
	d3dDevice->Present(NULL, NULL, NULL, NULL);
}

void WinPage::Update() {
	if (escKeyPressed) {
		audioManager->StopBackgroundSound();
		audioManager->PlayMainMenuSoundTrack();
		games.pop();
		escKeyPressed = false;
	}
}

void WinPage::Input() {
	dInputKeyboardDevice->Acquire();
	dInputKeyboardDevice->GetDeviceState(256, diKeys);

	if (diKeys[DIK_ESCAPE] & 0x80) {
		escKeyPressed = true;
	}
}

WinPage::~WinPage() {
}