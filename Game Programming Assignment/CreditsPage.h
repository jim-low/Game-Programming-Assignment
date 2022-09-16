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
	boolean clicked;
	boolean hover;
	LPCSTR credits;
	D3DXMATRIX mat;
	float textSpeed;
	LPDIRECT3DTEXTURE9 harambe;

public:
	CreditsPage() : Game() {
		this->Initialize();
	}
	~CreditsPage();

	void Initialize();
	void Update();
	void Render();
	void Input();
};

#endif
