#include <sstream>
#include "Level1.h"
#include "WinPage.h"
#include "GameOverPage.h"

void Level1::Initialize()
{
	HRESULT hr = D3DXCreateFont(d3dDevice, 40, 0, 0, 1, false, DEFAULT_CHARSET, OUT_TT_ONLY_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, "News Gothic", &font);

	if (FAILED(hr)) {
		cout << "Failed to lead font" << endl;
	}

	player = new Player();

	// health label
	healthLabel = new Label(D3DXVECTOR2(0, 0), "Tw Cen MT Condensed", "Health: " + to_string(player->GetHealth()), 20, 40);

	cometSpawnRate = 0.8;
	cometTimer = 10;

	// score text initialize
	scoreCounter = 0.15;
	scoreTimer = 10;
	score = 0;
	scoreLabel = new Label(D3DXVECTOR2(MyWindowWidth - 150 - 20, 10), "Tw Cen MT Condensed", "Score: " + to_string(score), 20, 40);

	audioManager->PlayGameplaySoundTrack();
}

// this formula made me cry for 30 mins - Jim
float Level1::CalculateAngle(Comet* comet)
{
	if (player == NULL) {
		return 0;
	}

	// To calculate trajectory angle:-

	D3DXVECTOR2 playerPos = player->GetPos();
	D3DXVECTOR2 cometPos = comet->GetPos();

	// 1. get difference in x and y position coordinates
	float dx = abs(playerPos.x - cometPos.x);
	float dy = abs(playerPos.y - cometPos.y);

	// 2. get angle in first quadrant using atan function
	// 3. convert result to degree for easier calculation (and to save sanity)
	float angle = atan(dy / dx) * 180 / PI;

	// 4. determine actual quadrant of player relative to comet
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

	// 5. convert angle back to radian
	// 6. boom boom
	return angle * PI / 180;
}

void Level1::SpawnComet() // instantiate comet object
{
	Comet* comet = new Comet();
	comet->ApplyAngle(CalculateAngle(comet));
	comets.push_back(comet); // add comet object to vector
}

void Level1::Update()
{
	if (player != NULL && player->isDed) {
		player = NULL; // deallocate player pointer
		audioManager->StopBackgroundSound(); // shhhhhhh
		games.pop(); // remove level 1 from game stack
		if (score == 69) { // winning condition is only 69
			games.push(new WinPage(score));
		}
		else { // other numbers you lose
			games.push(new GameOverPage(score));
		}
	}

	if (player != NULL) {
		player->Update();
	}

	// update each comets
	for (int i = 0; i < comets.size(); ++i) {
		comets.at(i)->Update();
	}

	// update each comet explosion animation
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

		/*
		if player collided with comet:-
		1. player receive damage from comet
		2. apply knockback to player following newton's third law of motion
		3. calculate comet explosion animation position
		4. instantiate comet explosion object
		5. push object to vector
		6. deallocate collided comet from vector
		*/
		Comet* comet = comets.at(i);
		if (Game::CheckCollision(comet->GetBody(), player->GetBody())) {
			player->Damage(comet->GetDamage());
			player->KnockBack(comet);
			audioManager->PlayCollisionSound();
			D3DXVECTOR2 explosionPos = comet->GetPos();
			explosionPos.x -= 77;
			explosionPos.y -= 75;
			CometExplosion* explosion = new CometExplosion();
			explosion->Initialize(explosionPos, comet->GetScaling());
			explosions.push_back(explosion);
			comets.erase(comets.begin() + i);
		}
	}

	// remove any explosion animation after lifespan ended
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

	// update health indicator text
	if (player != NULL) {
		tempHealth = "Health: " + to_string(player->GetHealth());
		healthLabel->setText(tempHealth.c_str());
		//tempHealth = "Health: " + to_string(player->GetHealth());
		//healthStr = tempHealth.c_str();
	}

	// update score indicator text
	scoreTimer -= scoreCounter;
	if (scoreTimer <= 0) {
		score += 1;
		scoreTimer = 10;
		tempScore = "Score: " + to_string(score);
		scoreLabel->setText(tempScore.c_str());
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

	healthLabel->Render();
	scoreLabel->Render();

	sprite->End();

	d3dDevice->EndScene();
	d3dDevice->Present(NULL, NULL, NULL, NULL);
}
