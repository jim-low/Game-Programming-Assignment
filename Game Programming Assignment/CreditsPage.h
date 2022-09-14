#pragma once
#ifndef CREDITSPAGE_H
#define CREDITSPAGE_H
#include "Header.h"


class CreditsPage : public Game {
private:
	boolean clicked;
	boolean hover;
	LPCSTR credits;
	D3DXMATRIX mat;

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
