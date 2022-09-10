#pragma once
#ifndef PLAYER_H
#define PLAYER_H
#include <vector>
#include "Header.h"
#include "Spaceship.h"
#include "Projectile.h"

enum Direction {
	NO_MOVE,
	LEFT,
	RIGHT,
	UP,
	DOWN
};

class Player : public Spaceship {
private:
	vector<Projectile*> bullets;
	int ammo;
	int maxAmmo;
	boolean reloading;
	float reloadTimer;
	float reloadRate;

	// name probably need to change
	boolean canShoot;

	boolean upPressed;
	boolean downPressed;
	boolean leftPressed;
	boolean rightPressed;
	boolean spacePressed;

	// TODO: implement acceleration, velocity
	D3DXVECTOR2 acceleration;
	D3DXVECTOR2 velocity;
	float speed;
	float friction;

	float fireRateTimer;
	float fireRate;

	void Move();
	void Shoot();

public:
	Player() : Spaceship() {
		this->Initialize();
	}
	~Player();

	void Initialize();
	void Update();
	void Render();
	void Input();
};

#endif
