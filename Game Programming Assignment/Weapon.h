#pragma once
#ifndef WEAPON_H
#define WEAPON_H

#include "Header.h"
#include "Game.h"

class Weapon : public Game
{
public:
	Weapon() : Game() {}
	~Weapon();

	void Initialization();
};

#endif
