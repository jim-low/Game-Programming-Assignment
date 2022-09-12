#include "Level1.h"

void Level1::InitializeEnemies()
{
	maxEnemies = 10;
	for (int i = 0; i < maxEnemies; ++i) {
		int x = (rand() % (MyWindowWidth + 1));
		int y = (rand() % ((MyWindowHeight / 4) + 1));
		Enemy* enemy = new Enemy();
		enemy->Initialize(D3DXVECTOR2(x, y));
		enemies.push_back(enemy);
	}
}

Level1::~Level1() {
}

void Level1::Initialize() {
	player = new Player();
	InitializeEnemies();
	playerBullets = player->getBullets();
}

void Level1::Update() {
	player->Update();
	int size;

	size = enemies.size();
	for (int i = 0; i < size; ++i) {
		Enemy* enemy = enemies.at(i);
		enemy->Update();
	}

	size = playerBullets->size();
	for (int i = 0; i < size; ++i) {
		Projectile* bullet = playerBullets->at(i);
		if (bullet->outOfBounds) {
			continue;
		}

		for (int j = 0; j < enemies.size(); ++j) {
			Enemy* enemy = enemies.at(j);
			if (checkCollision(enemy->GetBody(), bullet->GetBody())) {
				enemy->Damage(bullet->GetDamage());
				bullet->outOfBounds = true;
			}
		}
	}
}

void Level1::Render() {
	d3dDevice->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(0, 0, 0), 1.0f, 0);
	d3dDevice->BeginScene();

	sprite->Begin(D3DXSPRITE_ALPHABLEND);

	// render game objects
	player->Render();
	int size = enemies.size();
	for (int i = 0; i < size; ++i) {
		Enemy* enemy = enemies.at(i);
		enemy->Render();
	}

	sprite->End();

	d3dDevice->EndScene();
	d3dDevice->Present(NULL, NULL, NULL, NULL);
}

void Level1::Input() {
	player->Input();
}
