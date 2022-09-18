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
	RECT buttonCreditsRect;
	RECT buttonQuitRect;

	//textures
	LPDIRECT3DTEXTURE9 titleTexture;
	LPDIRECT3DTEXTURE9 butPlayTexture;
	LPDIRECT3DTEXTURE9 butSettingsTexture;
	LPDIRECT3DTEXTURE9 butCreditsTexture;
	LPDIRECT3DTEXTURE9 butQuitTexture;

	//buttonSizes
	int menuButtonWidth;
	int menuButtonHeight;
	int titleWidth;
	int titleHeight;
	D3DXMATRIX buttonMat; //for matrix position
	D3DXVECTOR2 titlePosition;

	D3DXVECTOR2 playPosition; 
	D3DXVECTOR2 settingsPosition;
	D3DXVECTOR2 creditsPosition;
	D3DXVECTOR2 quitPosition;

	RECT playCol;
	RECT settingsCol;
	RECT creditsCol;
	RECT quitCol;

	//currentSelectedButton
	int currentSelection;
	enum buttonFocus{UNFOCUS,PLAY,SETTINGS,CREDITS,QUIT};

	//coordinates of line 1----
	D3DXVECTOR2 l1StartPoint;
	D3DXVECTOR2 l1EndPoint;
	D3DXVECTOR2 l1LineVertices[2];

	//coordinates of line 2----
	D3DXVECTOR2 l2StartPoint;
	D3DXVECTOR2 l2EndPoint;
	D3DXVECTOR2 l2LineVertices[2];

	//input stuff
	boolean leftKeyPressed;

private:
	RECT mouse;

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