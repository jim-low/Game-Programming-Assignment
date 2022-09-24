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
	// movement
	D3DXVECTOR2 acceleration;
	D3DXVECTOR2 velocity;
	float friction;
	float direction;
	float rotationSpeed;
	float force;
	int mass;

	// utilities
	void Move();
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

	// getters
	int GetHealth();

	// utility methods
	void Damage(int damage); // receive damage method
	void KnockBack(Comet* comet); // receive knockback when collided with comet
};

#endif
