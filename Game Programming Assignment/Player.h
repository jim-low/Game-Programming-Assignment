#pragma once
#ifndef PLAYER_H
#define PLAYER_H
#include "Header.h"

class Player : public Spaceship {
protected:
	Weapon weapon[2];

public:
	Player() : Spaceship();

	void Initialize();
	void Update();
};

#endif
