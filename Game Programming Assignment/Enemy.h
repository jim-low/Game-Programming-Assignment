#pragma once
#ifndef ENEMY_H
#define ENEMY_H

#include "Spaceship.h"
#include "Header.h"

class Enemy : public Spaceship {
protected:
public:
	Enemy() : Spaceship() {
		this->Initialize();
	}
	~Enemy();

	void Initialize();
	void Update();
	void Render();
};

#endif
