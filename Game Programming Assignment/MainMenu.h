#ifndef MAINMENU_H
#define MAINMENU_H
#include "Header.h"
#include "Game.h"


class MainMenu : public Game
{
protected: 

	//RECTS to pinpoint location
	RECT titleRect; 
	RECT buttonPlayRect;
	RECT buttonSettingsRect;

	//textures
	LPDIRECT3DTEXTURE9 butUnPlayTexture = NULL;
	LPDIRECT3DTEXTURE9 butPlayTexture = NULL;
	LPDIRECT3DTEXTURE9 butUnSettingsTexture = NULL;
	LPDIRECT3DTEXTURE9 butSettingsTexture = NULL;

	//brushes
	LPD3DXFONT titleBrush; //Title of game
	LPD3DXLINE lineBrush; //lines for the panel and cover
	LPD3DXSPRITE buttonBrush; //To draw buttons in the panel

	//coordinates of line 1----
	D3DXVECTOR2 l1StartPoint;
	D3DXVECTOR2 l1EndPoint;
	D3DXVECTOR2 l1LineVertices[2];

	//coordinates of line 2----
	D3DXVECTOR2 l2StartPoint;
	D3DXVECTOR2 l2EndPoint;
	D3DXVECTOR2 l2LineVertices[2];

public:
	MainMenu() : Game() { //constructor
		this->Initialize();
	}
	~MainMenu();

	void Initialize();
	void Update();
	void Render();
	void Input();
};

#endif