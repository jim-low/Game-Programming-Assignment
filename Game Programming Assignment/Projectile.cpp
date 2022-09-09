#include "Projectile.h"

//void Projectile::Initialization() {
//	HRESULT hr = D3DXCreateTextureFromFile(d3dDevice, "../Assets/player-bullet2-but-really-bad-edit.png", &texture);
//
//	if (FAILED(hr)) {
//		cout << "Failed to load texture" << endl;
//	}
//
//	speed = D3DXVECTOR2(0, 5);
//	damage = 69;
//
//	textureWidth = 58;
//	textureHeight = 56;
//
//	spriteRow = 1;
//	spriteCol = 1;
//	spriteWidth = textureWidth / spriteCol;
//	spriteHeight = textureHeight / spriteRow;
//
//	animRect.top = currentFrame * spriteHeight;
//	animRect.bottom = animRect.top + spriteHeight;
//	animRect.left = currentFrame * spriteWidth;
//	animRect.right = animRect.left + spriteWidth;
//
//	scaling = D3DXVECTOR2(1, 1);
//	centre = D3DXVECTOR2(spriteWidth / 2, spriteHeight / 2);
//	direction = 0;
//	position = D3DXVECTOR2(100, 300);
//
//	colRect.top = position.y;
//	colRect.bottom = colRect.top + spriteHeight;
//	colRect.left = position.x;
//	colRect.right = colRect.left + spriteWidth;
//
//	maxFrame = (spriteRow * spriteCol) - 1;
//}
//
//void Projectile::Update() {
//	//position += speed;
//}
//
//void Projectile::Render() {
//	cout << "Projectile::Render()" << endl;
//
//	D3DXMATRIX mat;
//	D3DXMatrixTransformation2D(&mat, NULL, 0.0, &scaling, &centre, direction, &position);
//	sprite->SetTransform(&mat);
//	sprite->Draw(texture, &animRect, NULL, NULL, D3DCOLOR_XRGB(255, 255, 255));
//}
//
//Projectile::~Projectile() {
//
//}
