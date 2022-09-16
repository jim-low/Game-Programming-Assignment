#ifndef GAMEOVERPAGE_H
#define GAMEOVERPAGE_H
#include "Header.h"
#include "Game.h"


class GameOverPage : public Game
{
protected:
	Game* game;

	//RECTS to pinpoint location
	RECT rickRect;
	RECT loseTitleRect;

	//textures
	LPDIRECT3DTEXTURE9 rickTexture = NULL;

	D3DXMATRIX loseMat; //for matrix position
	D3DXVECTOR2 loseTitlePosition;
	D3DXVECTOR2 rickPosition;
	int currentRow;
	int rowFrame;

	//coordinates of box using lines----
	D3DXVECTOR2 lBpos1;
	D3DXVECTOR2 lBpos2;
	D3DXVECTOR2 lBpos3;
	D3DXVECTOR2 lBpos4;
	D3DXVECTOR2 lBVertices[5];
	int boxNTitleGap;


public:
	GameOverPage() : Game() { //constructor
		this->Initialize();
	}
	~GameOverPage();

	void Initialize();
	void Update();
	void Render();
	void Input();
};

#endif