#pragma once
#ifndef ENEMY_H
#define ENEMY_H

#include "Spaceship.h"
#include "Header.h"

class Enemy : public Spaceship {
public:
	Enemy() : Spaceship() {}
	~Enemy();

	void Initialize(D3DXVECTOR2 startPos);
	void Update();
	void Render();
	void Damage(int damage);
	boolean IsDed();
};

#endif
