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
};

#endif
