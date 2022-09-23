#include "CometExplosion.h"

void CometExplosion::Initialize(D3DXVECTOR2 startPos, D3DXVECTOR2 scaling)
{
	HRESULT hr = D3DXCreateTextureFromFile(d3dDevice, "../Assets/comet-explosion.png", &texture);

	if (FAILED(hr)) {
		cout << "Failed to load texture" << endl;
	}

	timer = 10;
	counter = 2;
	ended = false;

	textureWidth = 360;
	textureHeight = 719;

	spriteRow = 4;
	spriteCol = 2;
	spriteWidth = textureWidth / spriteCol;
	spriteHeight = textureHeight / spriteRow;

	currentFrame = 0;
	currentRow = 0;
	currentCol = 0;
	maxRow = 4;
	maxCol = 2;
	maxFrame = 7;

	animRect.top = currentFrame * spriteHeight;
	animRect.bottom = animRect.top + spriteHeight;
	animRect.left = currentFrame * spriteWidth;
	animRect.right = animRect.left + spriteWidth;

	this->scaling = scaling;
	centre = D3DXVECTOR2((spriteWidth * scaling.x) / 2, (spriteHeight * scaling.y) / 2);
	direction = 0;
	position = startPos;
}

void CometExplosion::Update()
{
	if (ended) {
		return;
	}

	animRect.top = currentRow * spriteHeight;
	animRect.left = currentCol % spriteCol * spriteWidth;
	animRect.right = animRect.left + spriteWidth;
	animRect.bottom = animRect.top + spriteHeight;

	// change animation frame after certain amount of time
	timer -= counter;
	if (timer <= 0) {
		++currentCol;
		if (currentCol >= maxCol) {
			++currentRow;
			currentCol = 0;
		}
		++currentFrame;
		timer = 10;
	}

	if (currentFrame >= maxFrame) {
		currentFrame = 0;
		ended = true;
	}

	if (currentRow >= maxRow) {
		currentRow = 0;
	}

	if (currentCol >= maxCol) {
		currentCol = 0;
	}
}

void CometExplosion::Render()
{
	if (ended) {
		return;
	}

	D3DXMATRIX mat;
	D3DXMatrixTransformation2D(&mat, NULL, 0.0, &scaling, &centre, direction, &position);
	sprite->SetTransform(&mat);
	sprite->Draw(texture, &animRect, NULL, NULL, D3DCOLOR_XRGB(255, 255, 255));
}
