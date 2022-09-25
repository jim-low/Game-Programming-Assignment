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
	vector<CometExplosion*> explosions; // comet explosion animation vector
	vector<Comet*> comets; // comet projectiles
	Player* player;

	// health indicator string variable
	string tempHealth;
	LPCSTR healthStr;
	RECT healthRect;
	D3DXVECTOR2 healthPos;

	// comet spawn variables
	float cometSpawnRate;
	float cometTimer;

	// score indicator string variable
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
	void Update();
	void Render();
};

#endif
