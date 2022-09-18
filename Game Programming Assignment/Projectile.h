#pragma once
#ifndef PROJECTILE_H
#define PROJECTILE_H
#include "Header.h"
#include "Game.h"

class Projectile : public Game {
protected:
	D3DXVECTOR2 speed;
	int damage;

public:
	boolean outOfBounds;

	Projectile() : Game() {}
	~Projectile();

	void Initialization(D3DXVECTOR2 startPos);
	void Update();
	void Render();

	// getter
	int GetDamage();
};

#endif
