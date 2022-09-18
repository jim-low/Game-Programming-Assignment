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
	vector<Projectile*> bullets; // bullets vector

	// ammo and reload mechanics
	int ammo;
	int maxAmmo;
	boolean reloading;
	float reloadTimer;
	float reloadRate;
	boolean canShoot;

	// inputs
	boolean upPressed;
	boolean downPressed;
	boolean leftPressed;
	boolean rightPressed;
	boolean spacePressed;

	// movement idk
	D3DXVECTOR2 acceleration;
	D3DXVECTOR2 velocity;
	float friction;
	float direction;
	float rotationSpeed;
	float force;
	int mass;

	// pewpew mechanics
	float fireRateTimer;
	float fireRate;

	// utilities
	void Move();
	void Shoot();
	void CheckBoundary();

public:
	Player() : Spaceship() {
		this->Initialize();
	}
	~Player();

	// shows if player is dead
	boolean isDed;

	void Initialize();
	void Update();
	void Render();
	void Input();

	// getters
	vector<Projectile*>* getBullets();
	int GetHealth();

	// utility methods
	void Damage(int damage); // receive damage method
	void KnockBack(Comet* comet); // receive knockback when collided with comet
};

#endif
