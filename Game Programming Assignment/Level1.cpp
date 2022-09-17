#include "Level1.h"
#include "Level2.h"
#include "GameOverPage.h"

void Level1::Initialize()
{
	player = new Player();

	cometSpawnRate = 0.8;
	cometTimer = 10;

	audioManager->PlayGameplaySoundTrack();
}

// this formula made me cry for 30 mins
float Level1::CalculateAngle(Comet* comet)
{
	if (player == NULL) {
		return 0;
	}

	D3DXVECTOR2 playerPos = player->GetPos();
	D3DXVECTOR2 cometPos = comet->GetPos();

	float dx = abs(playerPos.x - cometPos.x);
	float dy = abs(playerPos.y - cometPos.y);

	float angle = atan(dy / dx) * 180 / PI;

	// check which quadrant player is in relative to the comet
	if (playerPos.x <= cometPos.x) { // check left
		if (playerPos.y >= cometPos.y) { // check bottom (second quadrant)
			angle += 90;
		}
		else if (playerPos.y <= cometPos.y) { // check top (third quadrant)
			angle += 180;
		}
	}
	else if (playerPos.x >= cometPos.x) { // check right
		if (playerPos.y <= cometPos.y) {
			angle = 360 - angle;
		}
	}

	return angle * PI / 180;
}




void Level1::SpawnComet()
{
	Comet* comet = new Comet();
	comet->ApplyAngle(CalculateAngle(comet));
	comets.push_back(comet);
}

void Level1::Input()
{
	if (player != NULL) {
		player->Input();
	}
}

void Level1::Update()
{
	if (player != NULL && player->isDed) {
		player = NULL;
		audioManager->StopBackgroundSound();
		games.pop();
		games.push(new GameOverPage());
	}

	if (player != NULL) {
		player->Update();
	}

	for (int i = 0; i < comets.size(); ++i) {
		comets.at(i)->Update();
	}

	for (int i = 0; i < explosions.size(); ++i) {
		CometExplosion* explosion = explosions.at(i);
		if (!explosion->ended) {
			explosion->Update();
		}
	}

	for (int i = 0; i < comets.size(); ++i) {
		if (player == NULL) {
			break;
		}

		if (Level2::CheckCollision(comets.at(i)->GetBody(), player->GetBody())) {
			player->Damage(comets.at(i)->GetDamage());
			audioManager->PlayCollisionSound();
			D3DXVECTOR2 explosionPos = comets.at(i)->GetPos();
			explosionPos.x -= 77;
			explosionPos.y -= 75;
			CometExplosion* explosion = new CometExplosion();
			explosion->Initialize(explosionPos);
			explosions.push_back(explosion);
			comets.erase(comets.begin() + i);
		}
	}

	for (int i = 0; i < explosions.size(); ++i) {
		CometExplosion* explosion = explosions.at(i);
		if (explosion->ended) {
			explosions.erase(explosions.begin() + i);
		}
	}

	cometTimer -= cometSpawnRate;
	if (cometTimer <= 0) {
		SpawnComet();
		cometTimer = 10;
	}
}

void Level1::Render()
{
	d3dDevice->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(0, 0, 0), 1.0f, 0);
	d3dDevice->BeginScene();

	sprite->Begin(D3DXSPRITE_ALPHABLEND);

	// render game objects
	if (player != NULL) {
		player->Render();
	}

	for (int i = 0; i < comets.size(); ++i) {
		comets.at(i)->Render();
	}

	for (int i = 0; i < explosions.size(); ++i) {
		CometExplosion* explosion = explosions.at(i);
		if (!explosion->ended) {
			explosion->Render();
		}
	}

	sprite->End();

	d3dDevice->EndScene();
	d3dDevice->Present(NULL, NULL, NULL, NULL);
}
