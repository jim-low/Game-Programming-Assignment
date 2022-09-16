#pragma once
#ifndef RICKROLL_H
#define RICKROLL_H
#include "Header.h"
#include "Game.h"

class RickRoll : public Game
{
private:
	int currentRow;
	int rowFrame;

public:
	RickRoll() : Game() {
		this->Initialize();
	}
	~RickRoll();

	void Initialize();
	void Update();
	void Render();
};

#endif
