#include "Player.h"

void Player::Initialize()
{
	HRESULT hr = D3DXCreateTextureFromFile(d3dDevice, "../Assets/player-spaceship.png", &texture);

	if (FAILED(hr)) {
		cout << "Failed to load texture" << endl;
	}

	health = 100;

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

	scaling = D3DXVECTOR2(0.7, -0.7);
	centre = D3DXVECTOR2(spriteWidth / 2, spriteHeight / 2);
	direction = 0;
	position = D3DXVECTOR2(69, 420);

	colRect.top = position.y;
	colRect.bottom = colRect.top + spriteHeight;
	colRect.left = position.x;
	colRect.right = colRect.left + spriteWidth;

	maxFrame = (spriteRow * spriteCol) - 1;
}

void Player::Render()
{
	if (health <= 0) {
		return;
	}

	D3DXMATRIX mat;
	D3DXMatrixTransformation2D(&mat, NULL, 0.0, &scaling, &centre, direction, &position);
	sprite->SetTransform(&mat);
	sprite->Draw(texture, &animRect, NULL, NULL, D3DCOLOR_XRGB(255, 255, 255));
}

void Player::Update() {
	//Move();
	Shoot();
}

void Player::Input() {
	dInputKeyboardDevice->Acquire();
	dInputKeyboardDevice->GetDeviceState(256, diKeys);

	// shoot update
	if (diKeys[DIK_SPACE] & 0x80) {
		Shoot();
	}

	// movement
	if (diKeys[DIK_W] & 0x80) {
		position.y -= 5;
	}

	if (diKeys[DIK_S] & 0x80) {
		position.y += 5;
	}

	if (diKeys[DIK_A] & 0x80) {
		position.x -= 5;
	}

	if (diKeys[DIK_D] & 0x80) {
		position.x += 5;
	}
}

void Player::Shoot() {
	cout << "pew pew mothafoka" << endl;
}

Player::~Player() {
}
