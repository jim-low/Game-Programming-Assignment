#include <sstream>
#include "WinPage.h"
#include "MainMenu.h"

void WinPage::Initialize(int score) {
	//score
	this->score = score;
	tempStr = "Your score: " + to_string(score);
	scoreStr = tempStr.c_str();

	//initialize win label
	winLabel = new Label(D3DXVECTOR2((MyWindowWidth / 2) - (375 / 2), (MyWindowHeight / 2) - (245 / 2)), "../Assets/win_Title.png", 375, 245);
	winLabel->setScaling(1.8f, 1.8f);

	//initialize escLabel
	escLabel = new Label(D3DXVECTOR2(0, 0), "News Gothic", "Press the 'ESC' key to go back.", 10, 30);

	//initialize scoreLabel
	scoreLabel = new Label(D3DXVECTOR2(MyWindowWidth / 14 * 5.7, MyWindowHeight / 14 * 10.5), "News Gothic", scoreStr, 20, 50);

	audioManager->PlayWinSoundTrack();

}

void WinPage::Render() {
	//clear screen
	d3dDevice->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(0, 0, 0), 1.0f, 0);

	//start screen 
	d3dDevice->BeginScene();

	//draw sprite
	sprite->Begin(D3DXSPRITE_ALPHABLEND);

	//render stuff.
	winLabel->Render();
	escLabel->Render();
	scoreLabel->Render();

	sprite->End();

	//	End the scene
	d3dDevice->EndScene();

	//	Present the back buffer to screen
	d3dDevice->Present(NULL, NULL, NULL, NULL);
}

void WinPage::Update() {
	if (escKeyPressed) {
		audioManager->StopBackgroundSound(); // shhhhhhh
		audioManager->PlayMainMenuSoundTrack(); // play main menu mooosik
		games.pop(); // render main menu
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