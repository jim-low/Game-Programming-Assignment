#include "Player.h"

void Player::Initialize()
{
	HRESULT hr = D3DXCreateTextureFromFile(d3dDevice, "../Assets/new-spaceship.png", &texture);

	if (FAILED(hr)) {
		cout << "Failed to load texture" << endl;
	}

	health = 100;

	canShoot = false;
	fireRate = 0.8;
	fireRateTimer = 10;

	maxAmmo = 15;
	ammo = maxAmmo;
	reloading = false;
	reloadRate = 0.1;
	reloadTimer = 10;

	upPressed = false;
	downPressed = false;
	leftPressed = false;
	rightPressed = false;
	spacePressed = false;

	acceleration = D3DXVECTOR2(0, 0);
	velocity = D3DXVECTOR2(0, 0);
	speed = 2.f;
	friction = 0.2;
	rotationSpeed = 0.1f;
	direction = 0.0f;
	mass = 1;
	force = 1.f;

	textureWidth = 42;
	textureHeight = 29;

	spriteRow = 1;
	spriteCol = 1;
	spriteWidth = textureWidth / spriteCol;
	spriteHeight = textureHeight / spriteRow;

	animRect.top = currentFrame * spriteHeight;
	animRect.bottom = animRect.top + spriteHeight;
	animRect.left = currentFrame * spriteWidth;
	animRect.right = animRect.left + spriteWidth;

	scaling = D3DXVECTOR2(2, 2);
	centre = D3DXVECTOR2(spriteWidth / 2, spriteHeight / 2);
	direction = 0;
	position = D3DXVECTOR2(500, 500);

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
		bullet->Render();
	}

	D3DXMATRIX mat;
	D3DXMatrixTransformation2D(&mat, NULL, 0.0, &scaling, &centre, direction, &position);
	sprite->SetTransform(&mat);
	sprite->Draw(texture, &animRect, NULL, NULL, D3DCOLOR_XRGB(255, 255, 255));
}

void Player::Update() {
	// gameplay
	Move();

	if (canShoot && !reloading) {
		Shoot();
	}

	for (Projectile* bullet : bullets) {
		bullet->Update();
	}

	// timer update
	if (reloading) {
		reloadTimer -= reloadRate;
		if (reloadTimer <= 0) {
			reloading = false;
			ammo = maxAmmo;
			reloadTimer = 10;
		}
	}

	if (spacePressed && !canShoot) {
		fireRateTimer -= fireRate;
		if (fireRateTimer <= 0) {
			canShoot = false;
			spacePressed = false;
			fireRateTimer = 10;
		}
	}

	// sprite update
	animRect.top = currentFrame * spriteHeight;
	animRect.bottom = animRect.top + spriteHeight;
	animRect.left = currentFrame * spriteWidth;
	animRect.right = animRect.left + spriteWidth;

	colRect.top = position.y;
	colRect.bottom = colRect.top + spriteHeight;
	colRect.left = position.x;
	colRect.right = colRect.left + spriteWidth;

	maxFrame = (spriteRow * spriteCol) - 1;

	// bullets update
	for (int i = 0; i < bullets.size(); ++i) {
		if (bullets.at(i)->outOfBounds) {
			bullets.erase(bullets.begin() + i);
		}
		else {
			bullets.at(i)->Update();
		}
	}
}

void Player::Input() {
	dInputKeyboardDevice->Acquire();
	dInputKeyboardDevice->GetDeviceState(256, diKeys);

	// shoot update
	if (diKeys[DIK_SPACE] & 0x80 && !spacePressed && !reloading) {
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

vector<Projectile*>* Player::getBullets()
{
	return &bullets;
}

void Player::CheckBoundary() { // TODO: fix this shit
	if (position.x - speed < 0) {
		leftPressed = false;
	}

	if (position.x + spriteWidth + speed > MyWindowWidth) {
		rightPressed = false;
	}

	if (position.y - speed < 0) {
		upPressed = false;
	}

	if (position.y + spriteHeight + speed > MyWindowHeight) {
		downPressed = false;
	}
}

void Player::Move() {
	// CheckBoundary();

	if (upPressed) {
		position.y -= 5;
		//acceleration.x = cos(direction) * force / mass;
		//acceleration.y = sin(direction) * force / mass;
		upPressed = false;
	}

	if (downPressed) {
		position.y += 5;
		downPressed = false;
	}

	if (leftPressed) {
		position.x -= 5;
		//direction -= rotationSpeed;
		leftPressed = false;
	}

	if (rightPressed) {
		position.x += 5;
		//direction += rotationSpeed;
		rightPressed = false;
	}

	//velocity += acceleration;
	//velocity *= (1 - friction);
	//position += velocity;
	//acceleration = D3DXVECTOR2(0, 0);
}

void Player::Shoot() {
	Projectile* bullet = new Projectile();
	bullet->Initialization(D3DXVECTOR2(position.x + (spriteWidth / 5), position.y - (spriteHeight/2)));
	bullets.push_back(bullet);
	canShoot = false;
	ammo -= 1;

	if (ammo <= 0) {
		reloading = true;
		canShoot = false;
	}
}

Player::~Player() {
}
