#pragma once
#ifndef PLAYER_H
#define PLAYER_H
#include <vector>
#include "Header.h"
#include "Spaceship.h"
#include "Projectile.h"
#include "Comet.h"

class Player : public Spaceship {
private:
	vector<Projectile*> bullets;

	int ammo;
	int maxAmmo;
	boolean reloading;
	float reloadTimer;
	float reloadRate;

	boolean canShoot;

	boolean upPressed;
	boolean downPressed;
	boolean leftPressed;
	boolean rightPressed;
	boolean spacePressed;

	D3DXVECTOR2 acceleration;
	D3DXVECTOR2 velocity;
	float friction;
	float direction;
	float rotationSpeed;
	float force;
	int mass;

	float fireRateTimer;
	float fireRate;

	void Move();
	void Shoot();
	void CheckBoundary();

public:
	Player() : Spaceship() {
		this->Initialize();
	}
	~Player();

	boolean isDed;

	void Initialize();
	void Update();
	void Render();
	void Input();

	vector<Projectile*>* getBullets();
	int GetHealth();
	void Damage(int damage);
	void KnockBack(Comet* comet);
};

#endif
