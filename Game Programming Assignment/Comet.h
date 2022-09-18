#pragma once
#ifndef COMET_H
#define COMET_H
#include "Game.h"

class Comet : public Game
{
protected:
	float radian; // angle of comet trajectory towards player
	int damage;
	D3DXVECTOR2 speed;
	int mass;

private:
	D3DXVECTOR2 RandomPositionOutsideScreen(); // calculate position of comet outside of screen boundaries

public:
	Comet() : Game() {
		this->Initialize();
	}
	~Comet();

	void Initialize();
	void Update();
	void Render();

	void ApplyAngle(float radian); // apply radian angle to speed variable

	// setters
	int GetDamage();
	D3DXVECTOR2 GetSpeed();
	int GetMass();
};

#endif
