#pragma once
#ifndef CREDITSPAGE_H
#define CREDITSPAGE_H
#include <vector>
#include "Header.h"
#include "Game.h"
#include "Player.h"
#include "Comet.h"

class CreditsPage : public Game {
private:
	LPCSTR credits;
	float textSpeed;
	RECT mouse; // mouse rectangle for collision
	D3DXMATRIX mat; // mat for transformation

public:
	CreditsPage() : Game() {
		this->Initialize();
	}
	~CreditsPage();

	void Initialize();
	void Update();
	void Render();
};

#endif
