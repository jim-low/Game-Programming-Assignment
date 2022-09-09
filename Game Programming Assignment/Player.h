#pragma once
#ifndef PLAYER_H
#define PLAYER_H
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
	Projectile* bullet;
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
