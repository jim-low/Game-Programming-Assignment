#include <sstream>
#include "GameOverPage.h"

void GameOverPage::Initialize(int score) {
	HRESULT hr = D3DXCreateTextureFromFile(d3dDevice, "../Assets/you-lose.png", &texture);
	if (FAILED(hr)) {
		cout << "Failed to create Lose Title." << endl;
		MessageBox(NULL, TEXT("Failed to create Lose Title."), TEXT("ERROR!"), MB_YESNOCANCEL | MB_ICONQUESTION);
	}

	hr = D3DXCreateFontA(d3dDevice, 20, 0, FW_BOLD, 1, false, DEFAULT_CHARSET, OUT_TT_ONLY_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, "News Gothic", &font);
	if (FAILED(hr)) {
		cout << "Failed to create font." << endl;
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

	textureWidth = 281;
	textureHeight = 94;

	spriteRow = 1;
	spriteCol = 1;
	spriteWidth = textureWidth / spriteCol;
	spriteHeight = textureHeight / spriteRow;

	animRect.top = currentFrame * spriteHeight;
	animRect.bottom = animRect.top + spriteHeight;
	animRect.left = currentFrame * spriteWidth;
	animRect.right = animRect.left + spriteWidth;

	scaling = D3DXVECTOR2(2, 2);
	centre = D3DXVECTOR2((spriteWidth * scaling.x) / 2, (spriteHeight * scaling.y) / 2);
	direction = 0;
	position = D3DXVECTOR2((MyWindowWidth / 2) - (spriteWidth / (20 * scaling.x)), (MyWindowHeight / 4) - (spriteHeight * (scaling.y / 2)));

	neverGonnaGiveYouUp = new RickRoll();

	audioManager->PlayLoseSoundTrack();
}

void GameOverPage::Update() {
	neverGonnaGiveYouUp->Update();
}

void GameOverPage::Render() {
	d3dDevice->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(0, 0, 0), 1.0f, 0);
	d3dDevice->BeginScene();

	sprite->Begin(D3DXSPRITE_ALPHABLEND);

	neverGonnaGiveYouUp->Render();

	D3DXMATRIX mat;
	D3DXMatrixTransformation2D(&mat, &centre, 0.0, &scaling, &centre, direction, &position);
	sprite->SetTransform(&mat);
	sprite->Draw(texture, &animRect, NULL, NULL, D3DCOLOR_XRGB(255, 255, 255));

	D3DXMatrixTransformation2D(&mat, NULL, 0.0, &scaling, NULL, direction, &scorePos);
	sprite->SetTransform(&mat);
	font->DrawText(sprite, scoreStr, tempStr.length(), &scoreRect, DT_LEFT, D3DCOLOR_XRGB(255, 255, 255));

	sprite->End();
	d3dDevice->EndScene();
	d3dDevice->Present(NULL, NULL, NULL, NULL);
}

void GameOverPage::Input() {
}

GameOverPage::~GameOverPage() {
}