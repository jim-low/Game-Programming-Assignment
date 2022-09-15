#pragma once
#ifndef LEVEL2_H
#define LEVEL2_H
#include "Header.h"
#include "Game.h"
#include "Player.h"
#include "Enemy.h"

class Level2 : public Game
{
protected:
	Player* player;
	vector<Projectile*>* playerBullets;

	vector<Enemy*> enemies;
	int maxEnemies;

private:
	void InitializeEnemies();
	void UpdateEnemies();
	void CheckBulletsHitEnemies();
	void RenderEnemies();

public:
	Level2() : Game() {
		this->Initialize();
	}
	~Level2();

	void Initialize();
	void Update();
	void Render();
	void Input();
};

#endif
