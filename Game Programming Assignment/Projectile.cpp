#include "Header.h"
#include "Projectile.h"

void Projectile::Initialization(D3DXVECTOR2 startPos) {
	HRESULT hr = D3DXCreateTextureFromFile(d3dDevice, "../Assets/bullet1.png", &texture);

	if (FAILED(hr)) {
		cout << "Failed to load texture" << endl;
	}

	speed = D3DXVECTOR2(0, -15.f);
	damage = 10;
	outOfBounds = false;

	textureWidth = 35;
	textureHeight = 64;

	spriteRow = 1;
	spriteCol = 1;
	spriteWidth = textureWidth / spriteCol;
	spriteHeight = textureHeight / spriteRow;

	animRect.top = currentFrame * spriteHeight;
	animRect.bottom = animRect.top + spriteHeight;
	animRect.left = currentFrame * spriteWidth;
	animRect.right = animRect.left + spriteWidth;

	scaling = D3DXVECTOR2(1, 1);
	centre = D3DXVECTOR2(spriteWidth / 2, spriteHeight / 2);
	direction = 0;
	position = startPos;

	colRect.top = position.y;
	colRect.bottom = colRect.top + spriteHeight;
	colRect.left = position.x;
	colRect.right = colRect.left + spriteWidth;

	maxFrame = (spriteRow * spriteCol) - 1;
}

void Projectile::Update() {
	position += speed;

	if (position.y < (0 - textureHeight) || position.y > MyWindowHeight) {
		outOfBounds = true;
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

void Projectile::Render() {
	D3DXMATRIX mat;
	D3DXMatrixTransformation2D(&mat, NULL, 0.0, &scaling, &centre, direction, &position);
	sprite->SetTransform(&mat);
	sprite->Draw(texture, &animRect, NULL, NULL, D3DCOLOR_XRGB(255, 255, 255));
}

int Projectile::GetDamage()
{
	return damage;
}

Projectile::~Projectile() {
	cout << "bullet has been deletedededed" << endl;
}
