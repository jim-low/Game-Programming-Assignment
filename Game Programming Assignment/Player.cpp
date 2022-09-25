#include <math.h>
#include "Player.h"

void Player::Initialize()
{
	HRESULT hr = D3DXCreateTextureFromFile(d3dDevice, "../Assets/new-spaceship.png", &texture);

	if (FAILED(hr)) {
		cout << "Failed to load texture" << endl;
	}

	health = 100;
	isDed = false;

	acceleration = D3DXVECTOR2(0, 0);
	velocity = D3DXVECTOR2(0, 0);
	friction = 0.05;
	rotationSpeed = 0.1f;
	direction = 0.0f;
	mass = 1;
	force = 2.f;

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
	centre = D3DXVECTOR2((spriteWidth * scaling.x) / 2, (spriteHeight * scaling.y) / 2);
	direction = 0;
	position = D3DXVECTOR2((MyWindowWidth / 2) - (spriteWidth * scaling.x), (MyWindowHeight / 2) - (spriteHeight * scaling.y));

	colRect.top = position.y;
	colRect.bottom = colRect.top + spriteHeight;
	colRect.left = position.x;
	colRect.right = colRect.left + spriteWidth;

	maxFrame = (spriteRow * spriteCol) - 1;
}

void Player::Render()
{
	// no need to render if player ded
	if (isDed) {
		return;
	}

	D3DXMATRIX mat;
	D3DXMatrixTransformation2D(&mat, NULL, 0.0, &scaling, &centre, direction, &position);
	sprite->SetTransform(&mat);
	sprite->Draw(texture, &animRect, NULL, NULL, D3DCOLOR_XRGB(255, 255, 255));
}

void Player::Update() {
	// no need to update if player ded
	if (isDed) {
		return;
	}

	Move();

	// sprite and collision update
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

int Player::GetHealth()
{
	return health;
}

void Player::CheckBoundary() // bounce player back if player has collided with window boundary
{
	float width = spriteWidth * scaling.x;
	float height = spriteHeight * scaling.y;

	if (position.x < 0 || position.x > MyWindowWidth - width) {
		if (position.x < 0) {
			position.x = 0;
		}
		if (position.x > MyWindowWidth - width) {
			position.x = MyWindowWidth - width;
		}
		velocity.x *= -1;
	}

	if (position.y < 0 || position.y > MyWindowHeight - height) {
		if (position.y < 0) {
			position.y = 0;
		}
		if (position.y > MyWindowHeight - height) {
			position.y = MyWindowHeight - height;
		}
		velocity.y *= -1;
	}
}

void Player::Damage(int damage)
{
	health -= damage;

	if (health <= 0) {
		audioManager->PlayExplosionSound();
		isDed = true;
	}
}

// newton third law of motion
void Player::KnockBack(Comet* comet)
{
	D3DXVECTOR2 cometPos = comet->GetPos();
	D3DXVECTOR2 cometVelocity = comet->GetSpeed();
	int cometMass = comet->GetMass();

	double distance = sqrt(pow(this->position.x - cometPos.x, 2) + pow(this->position.y - cometPos.y, 2));

	// normal to the tangent (should do this in vector)
	D3DXVECTOR2 normal = D3DXVECTOR2((cometPos.x - this->position.x) / distance, (cometPos.y - this->position.y) / distance);

	// impulse energy (to know how long the vector should be)
	double p = 2 * (velocity.x * normal.x + velocity.y * normal.y - cometVelocity.x * normal.x - cometVelocity.y * normal.y) / (mass + cometMass);

	// apply the impulse force to the existing velocity
	velocity.x -= p * cometMass * normal.x;
	velocity.y -= p * cometMass * normal.y;
}

void Player::Move() {
	CheckBoundary();

	if (DirectInput::IsKeyDown(DIK_W)) {
		acceleration.x = sin(direction) * force / mass;
		acceleration.y = -cos(direction) * force / mass;
	}

	if (DirectInput::IsKeyDown(DIK_A)) {
		direction -= rotationSpeed;
	}

	if (DirectInput::IsKeyDown(DIK_D)) {
		direction += rotationSpeed;
	}

	velocity += acceleration;
	velocity *= (1 - friction);
	position += velocity;
	acceleration = D3DXVECTOR2(0, 0);
}

Player::~Player() {
}
