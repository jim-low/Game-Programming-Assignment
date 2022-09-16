#pragma once
#ifndef LEVEL1_H
#define LEVEL1_H

#include "Header.h"
#include "Game.h"
#include "CreditsPage.h"
#include "Player.h"
#include "Comet.h"

class Level1 : public Game
{
protected:
	CreditsPage* credits;
	boolean playCredits;

	vector<Comet*> comets;
	Player* player;

	float cometSpawnRate;
	float cometTimer;

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
