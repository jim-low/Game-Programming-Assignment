#pragma once
#ifndef LEVEL1_H
#define LEVEL1_H

#include "Header.h"
#include "Game.h"
#include "Player.h"
#include "Comet.h"
#include "CometExplosion.h"

class Level1 : public Game
{
protected:
	vector<CometExplosion*> explosions;
	vector<Comet*> comets;
	Player* player;

	string tempHealth;
	LPCSTR healthStr;
	RECT healthRect;
	D3DXVECTOR2 healthPos;

	float cometSpawnRate;
	float cometTimer;

	string tempScore;
	LPCSTR scoreStr;
	RECT scoreRect;
	D3DXVECTOR2 scorePos;
	float scoreTimer;
	float scoreCounter;
	int score;

private:
	float CalculateAngle(Comet* comet); // calculate angle between comet and player
	void SpawnComet();

public:
	Level1(): Game() {
		this->Initialize();
	}
	~Level1();

	void Initialize();
	void Input();
	void Update();
	void Render();
};

#endif
