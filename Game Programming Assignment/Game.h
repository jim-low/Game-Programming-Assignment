#pragma once
#ifndef GAME_H
#define GAME_H
#include "Header.h"

#include <iostream>
#include <d3d9.h>
#include <d3dx9.h>

class Game {
protected:
	int fps;
	RECT animRect;
	RECT colRect;
	D3DXVECTOR2 position;
	int spriteWidth;
	int spriteHeight;
	int spriteCol;
	int spriteRow;
	int textureWidth;
	int textureHeight;
	std::string textureFile;
	int backgroundMovement;
	std::string soundFile;
	float soundVolume;

public:
	Game(
		int fps,
		RECT animRect,
		RECT colRect,
		D3DXVECTOR2 position,
		int spriteWidth,
		int spriteHeight,
		int spriteCol,
		int spriteRow,
		int textureWidth,
		int textureHeight,
		std::string textureFile,
		int backgroundMovement,
		std::string soundFile,
		float soundVolume
	) {
		this->fps = fps;
		this->animRect = animRect;
		this->colRect = colRect;
		this->position = position;
		this->spriteWidth = spriteWidth;
		this->spriteHeight = spriteHeight;
		this->spriteCol = spriteCol;
		this->spriteRow = spriteRow;
		this->textureWidth = textureWidth;
		this->textureHeight = textureHeight;
		this->textureFile = textureFile;
		this->backgroundMovement = backgroundMovement;
		this->soundFile = soundFile;
		this->soundVolume = soundVolume;

	}

};

#endif
