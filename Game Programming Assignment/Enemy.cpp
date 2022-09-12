#include "Enemy.h"
#include "Player.h"
#include "Projectile.h"

void Enemy::Initialize(D3DXVECTOR2 startPos) {
	HRESULT hr = D3DXCreateTextureFromFile(d3dDevice, "../Assets/aliens.png", &texture);

	if (FAILED(hr)) {
		cout << "Failed to load texture" << endl;
	}

	health = 30;

	textureWidth = 576 / 4;
	textureHeight = 384 / 8;

	spriteRow = 1;
	spriteCol = 3;
	spriteWidth = textureWidth / spriteCol;
	spriteHeight = textureHeight / spriteRow;

	animRect.top = currentFrame * spriteHeight;
	animRect.bottom = animRect.top + spriteHeight;
	animRect.left = currentFrame * spriteWidth;
	animRect.right = animRect.left + spriteWidth;

	scaling = D3DXVECTOR2(1.3, 1.3);
	centre = D3DXVECTOR2(spriteWidth / 2, spriteHeight / 2);
	direction = 0;
	position = startPos;

	colRect.top = position.y;
	colRect.bottom = colRect.top + spriteHeight;
	colRect.left = position.x;
	colRect.right = colRect.left + spriteWidth;

	maxFrame = (spriteRow * spriteCol) - 1;
}

void Enemy::Update() {
	if (health <= 0) {
		return;
	}

	animRect.top = currentFrame * spriteHeight;
	animRect.bottom = animRect.top + spriteHeight;
	animRect.left = currentFrame * spriteWidth;
	animRect.right = animRect.left + spriteWidth;

	colRect.top = position.y;
	colRect.bottom = colRect.top + spriteHeight;
	colRect.left = position.x;
	colRect.right = colRect.left + spriteWidth;

	maxFrame = (spriteRow * spriteCol) - 1;
}

void Enemy::Render() {
	if (health <= 0) {
		return;
	}

	D3DXMATRIX mat;
	D3DXMatrixTransformation2D(&mat, NULL, 0.0, &scaling, &centre, direction, &position);
	sprite->SetTransform(&mat);
	sprite->Draw(texture, &animRect, NULL, NULL, D3DCOLOR_XRGB(255, 255, 255));
}

void Enemy::Damage(int damage)
{
	health -= damage;
}

Enemy::~Enemy() {

}
