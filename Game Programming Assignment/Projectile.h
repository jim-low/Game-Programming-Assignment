#pragma once
#include "Game.h"

class Projectile : public Game {
public:
	Projectile(
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
	) : Game(
		fps,
		animRect,
		colRect,
		position,
		spriteWidth,
		spriteHeight,
		spriteCol,
		spriteRow,
		textureWidth,
		textureHeight,
		textureFile,
		backgroundMovement,
		soundFile,
		soundVolume
	) {

	}
};