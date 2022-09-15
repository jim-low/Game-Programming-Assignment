#include "Level2.h"

void Level2::InitializeEnemies()
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

void Level2::UpdateEnemies()
{
	for (int i = 0; i < enemies.size(); ++i) {
		if (enemies.at(i)->IsDed()) {
			enemies.erase(enemies.begin() + i);
		}
		else {
			enemies.at(i)->Update();
		}
	}
}

void Level2::CheckBulletsHitEnemies()
{
	for (int i = 0; i < playerBullets->size(); ++i) {
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

void Level2::RenderEnemies()
{
	for (int i = 0; i < enemies.size(); ++i) {
		Enemy* enemy = enemies.at(i);
		enemy->Render();
	}
}

Level2::~Level2() {
}

void Level2::Initialize() {
	player = new Player();
	InitializeEnemies();
	playerBullets = player->getBullets();
}

void Level2::Update() {
	player->Update();
	playerBullets = player->getBullets();

	UpdateEnemies();
	CheckBulletsHitEnemies();
}

void Level2::Render() {
	d3dDevice->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(0, 0, 0), 1.0f, 0);
	d3dDevice->BeginScene();

	sprite->Begin(D3DXSPRITE_ALPHABLEND);

	// render game objects
	player->Render();
	RenderEnemies();

	sprite->End();

	d3dDevice->EndScene();
	d3dDevice->Present(NULL, NULL, NULL, NULL);
}

void Level2::Input() {
	player->Input();
}
