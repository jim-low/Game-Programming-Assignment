#pragma once
#ifndef SPACESHIP_H
#define SPACESHIP_H

#include "Header.h"

class Spaceship : public Game {
protected:
	int health;
	int damage;
	D3DXVECTOR2 velocity;
	D3DXVECTOR2 acceleration;
	float fireRate;

public:
	Spaceship() : Game() {}

};

#endif
