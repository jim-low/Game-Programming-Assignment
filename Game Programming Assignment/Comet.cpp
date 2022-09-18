#include "Header.h"
#include "Comet.h"

void Comet::Initialize()
{
	HRESULT hr = D3DXCreateTextureFromFile(d3dDevice, "../Assets/comet.png", &texture);

	if (FAILED(hr)) {
		cout << "Failed to load texture" << endl;
	}

	damage = 5;
	int randomSpeed = (rand() % (12 - 8 + 1)) + 8;
	//speed = D3DXVECTOR2(randomSpeed, randomSpeed);
	speed = D3DXVECTOR2(5, 5);
	mass = 69;

	textureWidth = 77;
	textureHeight = 75;

	currentFrame = 0;
	direction = 0;

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
	position = RandomPositionOutsideScreen();

	colRect.top = position.y;
	colRect.bottom = colRect.top + spriteHeight;
	colRect.left = position.x;
	colRect.right = colRect.left + spriteWidth;

	maxFrame = (spriteRow * spriteCol) - 1;
}

void Comet::ApplyAngle(float radian)
{
	this->radian = radian;
	speed.x = speed.x * cos(radian);
	speed.y = speed.y * sin(radian);
}

int Comet::GetDamage()
{
	return damage;
}

D3DXVECTOR2 Comet::GetSpeed()
{
	return speed;
}

int Comet::GetMass()
{
	return mass;
}

void Comet::Update()
{
	position += speed;

	spriteRow = 1;
	spriteCol = 1;
	spriteWidth = textureWidth / spriteCol;
	spriteHeight = textureHeight / spriteRow;

	animRect.top = currentFrame * spriteHeight;
	animRect.bottom = animRect.top + spriteHeight;
	animRect.left = currentFrame * spriteWidth;
	animRect.right = animRect.left + spriteWidth;

	colRect.top = position.y;
	colRect.bottom = colRect.top + spriteHeight;
	colRect.left = position.x;
	colRect.right = colRect.left + spriteWidth;
}

void Comet::Render()
{
	D3DXMATRIX mat;
	D3DXMatrixTransformation2D(&mat, NULL, 0.0, &scaling, &centre, direction, &position);
	sprite->SetTransform(&mat);
	sprite->Draw(texture, &animRect, NULL, NULL, D3DCOLOR_XRGB(255, 255, 255));
}


D3DXVECTOR2 Comet::RandomPositionOutsideScreen()
{
	int min = -30;
	int max = MyWindowHeight + 30;

	float x = 0;
	float y = 0;

	if (rand() % 2 == 0) {
		x = (rand() % (-10 + 1));
		
		audioManager->SetPanning(-1);
		audioManager->PlayCometSound();

	}
	else {
		x = (rand() % ((MyWindowWidth + 10) - MyWindowWidth) + 1) + MyWindowWidth;

		audioManager->SetPanning(1);
		audioManager->PlayCometSound();
	}
	y = (rand() % (max - min + 1) + min);

	return D3DXVECTOR2(x, y);
}