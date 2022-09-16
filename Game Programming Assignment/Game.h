#pragma once
#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <d3d9.h>
#include <d3dx9.h>

class Game {
protected:
	int fps;
	RECT animRect;
	RECT colRect;

	int spriteWidth;
	int spriteHeight;
	int spriteCol;
	int spriteRow;

	int currentFrame;
	int maxFrame;

	int textureWidth;
	int textureHeight;

	D3DXVECTOR2 scaling;
	D3DXVECTOR2 centre;
	float direction;
	D3DXVECTOR2 position;

	LPDIRECT3DTEXTURE9 texture;
	int backgroundMovement;
	// string soundFile;
	float soundVolume;


	//test (Brushes)
	LPD3DXFONT fontBrush; //Title of game
	LPD3DXLINE lineBrush; //lines for the panel and cover
	LPD3DXSPRITE spriteBrush; //To draw buttons in the panel

public:
	Game();
	~Game();

	virtual void Initialize();
	virtual void Render(); 
	virtual void CleanUp();
	virtual void Update();
	virtual void Input();
	static boolean CheckCollision(RECT a, RECT b);

	RECT GetBody() {
		return colRect;
	}

	D3DXVECTOR2 GetPos() {
		return position;
	}
};

#endif
