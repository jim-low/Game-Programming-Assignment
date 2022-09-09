#include "Player.h"

void Player::Initialize()
{
	HRESULT hr = D3DXCreateTextureFromFile(d3dDevice, "../Assets/player-spaceship.png", &texture);

	if (FAILED(hr)) {
		cout << "Failed to load texture" << endl;
	}

	health = 100;

	canShoot = false;
	fireRate = 0.5;
	timer = 10;

	upPressed = false;
	downPressed = false;
	leftPressed = false;
	rightPressed = false;
	spacePressed = false;

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
	position = D3DXVECTOR2(800, 600);

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

	for (Projectile* bullet : bullets) {
		if (!bullet->outOfBounds) {
			bullet->Render();
		}
	}

	D3DXMATRIX mat;
	D3DXMatrixTransformation2D(&mat, NULL, 0.0, &scaling, &centre, direction, &position);
	sprite->SetTransform(&mat);
	sprite->Draw(texture, &animRect, NULL, NULL, D3DCOLOR_XRGB(255, 255, 255));
}

void Player::Update() {
	Move();

	if (canShoot) {
		Shoot();
	}

	for (Projectile* bullet : bullets) {
		if (!bullet->outOfBounds) {
			bullet->Update();
		}
	}

	cout << timer << endl;

	if (spacePressed && !canShoot) {
		timer -= fireRate;
		if (timer <= 0) {
			timer = 10;
			canShoot = false;
			spacePressed = false;
		}
	}
}

void Player::Input() {
	dInputKeyboardDevice->Acquire();
	dInputKeyboardDevice->GetDeviceState(256, diKeys);

	// shoot update
	if (diKeys[DIK_SPACE] & 0x80 && !spacePressed) {
		spacePressed = true;
		canShoot = true;
	}

	// movement
	if (diKeys[DIK_W] & 0x80) {
		upPressed = true;
	}

	if (diKeys[DIK_S] & 0x80) {
		downPressed = true;
	}

	if (diKeys[DIK_A] & 0x80) {
		leftPressed = true;
	}

	if (diKeys[DIK_D] & 0x80) {
		rightPressed = true;
	}
}

void Player::Move() {
	if (upPressed) {
		position.y -= 5;
		upPressed = false;
	}

	if (downPressed) {
		position.y += 5;
		downPressed = false;
	}

	if (leftPressed) {
		position.x -= 5;
		leftPressed = false;
	}

	if (rightPressed) {
		position.x += 5;
		rightPressed = false;
	}
}

void Player::Shoot() {
	Projectile* bullet = new Projectile();
	bullet->Initialization(D3DXVECTOR2(position.x + (spriteWidth / 6), position.y - (spriteHeight/2)));
	bullets.push_back(bullet);
	canShoot = false;
}

Player::~Player() {
}
