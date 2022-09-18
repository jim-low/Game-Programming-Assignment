#pragma once
#ifndef COMETEXPLOSION_H
#define COMETEXPLOSION_H
#include "Header.h"

class CometExplosion : public Game
{
private:
	int currentRow;
	int maxRow;

	int currentCol;
	int maxCol;

	// animation variables
	float timer;
	float counter;

public:
	CometExplosion() : Game() { }
	~CometExplosion();

	boolean ended;

	void Initialize(D3DXVECTOR2 startPos);
	void Update();
	void Render();
};

#endif