#pragma once
#ifndef SPACESHIP_H
#define SPACESHIP_H

#include "Header.h"

class Spaceship : public Game {
protected:
	int health;
	int damage;
	D3DXVECTOR2 velocity;
	D3DXVECTOR2 acceleration;
	float fireRate;

public:
	Spaceship(
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
		float soundVolume,
		int health,
		int damage,
		D3DXVECTOR2 velocity,
		D3DXVECTOR2 acceleration,
		float fireRate
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
		this->health = health;
		this->damage = damage;
		this->velocity = velocity;
		this->acceleration = acceleration;
		this->fireRate = fireRate;
	}
};

#endif
