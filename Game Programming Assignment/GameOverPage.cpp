#include "GameOverPage.h"

void GameOverPage::Initialize() {
	HRESULT hr = D3DXCreateTextureFromFile(d3dDevice, "../Assets/you-lose.png", &texture);
	if (FAILED(hr)) {
		cout << "Failed to create Lose Title." << endl;
		MessageBox(NULL, TEXT("Failed to create Lose Title."), TEXT("ERROR!"), MB_YESNOCANCEL | MB_ICONQUESTION);
	}

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
	position = D3DXVECTOR2((MyWindowWidth / 2) - (spriteWidth / (3 * scaling.x)), (MyWindowHeight / 4) - (spriteHeight * (scaling.y / 2)));

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

	sprite->End();
	d3dDevice->EndScene();
	d3dDevice->Present(NULL, NULL, NULL, NULL);
}

void GameOverPage::Input() {
}

GameOverPage::~GameOverPage() {
}