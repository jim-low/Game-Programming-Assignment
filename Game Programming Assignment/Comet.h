#pragma once
#ifndef COMET_H
#define COMET_H
#include "Game.h"

class Comet : public Game
{
protected:
	float radian;
	int damage;
	D3DXVECTOR2 speed;
	int mass;

private:
	D3DXVECTOR2 RandomPositionOutsideScreen();

public:
	Comet() : Game() {
		this->Initialize();
	}
	~Comet();

	void Initialize();
	void Update();
	void Render();

	void ApplyAngle(float radian);
	int GetDamage();
	D3DXVECTOR2 GetSpeed();
	int GetMass();
};

#endif
