#include "Header.h"

void Player::Initialize()
{
	HRESULT hr = D3DXCreateTextureFromFile(d3dDevice, "../Assets/player-spaceship.png", &texture);

	if (FAILED(hr)) {
		cout << "Failed to load texture" << endl;
	}

	textureWidth = 318;
	textureHeight = 512;

	spriteRow = 4;
	spriteCol = 3;
	spriteWidth = textureWidth / spriteCol;
	spriteHeight = textureHeight / spriteRow;

	animRect.top = currentFrame * spriteHeight;
	animRect.bottom = animRect.top + spriteHeight;
	animRect.left = currentFrame * spriteWidth;
	animRect.right = animRect.left + spriteWidth;

	position = D3DXVECTOR2(69, 420);

	colRect.top = position.y;
	colRect.bottom = colRect.top + spriteHeight;
	colRect.left = position.x;
	colRect.right = colRect.left + spriteWidth;

	maxFrame = (spriteRow * spriteCol) - 1;
}

// void Player::Update()
// {
// }

Player::~Player() {
}
