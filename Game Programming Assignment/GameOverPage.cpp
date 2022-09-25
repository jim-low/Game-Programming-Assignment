#include <sstream>
#include "GameOverPage.h"

void GameOverPage::Initialize(int score) {

	//initialize score
	this->score = score;

	// initializing score text
	tempStr = "Your score: " + to_string(score);
	scoreStr = tempStr.c_str();

	//initialize lose label
	loseLabel = new Label(D3DXVECTOR2(MyWindowWidth/2 - (281/2), 60),"../Assets/you-lose.png", 281, 94);
	loseLabel->setScaling(2.0f, 2.0f);

	//initialize esc label
	escLabel = new Label(D3DXVECTOR2(0, 0), "News Gothic", "Press the 'ESC' key to go back.", 10, 30);

	//initialize score Label
	scoreLabel = new Label(D3DXVECTOR2(MyWindowWidth / 14 * 5.7, MyWindowHeight / 14 * 12), "News Gothic", scoreStr, 20, 50);

	// appropriate naming
	neverGonnaGiveYouUp = new RickRoll();

	audioManager->PlayLoseSoundTrack();
}

void GameOverPage::Update() {
	// update is never gonna let you down
	neverGonnaGiveYouUp->Update();

	if (escKeyPressed) {
		/*
		stop game over background music
		play main menu sound track
		remove game over scene from game stack to render main menu
		*/
		audioManager->StopBackgroundSound();
		audioManager->PlayMainMenuSoundTrack();
		games.pop();
		escKeyPressed = false;
	}
}

void GameOverPage::Render() {
	d3dDevice->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(0, 0, 0), 1.0f, 0);
	d3dDevice->BeginScene();

	sprite->Begin(D3DXSPRITE_ALPHABLEND);

	// hes never gonna run around and desert you
	neverGonnaGiveYouUp->Render();

	loseLabel->Render();
	escLabel->Render();
	scoreLabel->Render();

	sprite->End();
	d3dDevice->EndScene();
	d3dDevice->Present(NULL, NULL, NULL, NULL);
}

void GameOverPage::Input() {
	dInputKeyboardDevice->Acquire();
	dInputKeyboardDevice->GetDeviceState(256, diKeys);

	if (diKeys[DIK_ESCAPE] & 0x80) {
		escKeyPressed = true;
	}
}

GameOverPage::~GameOverPage() {
}