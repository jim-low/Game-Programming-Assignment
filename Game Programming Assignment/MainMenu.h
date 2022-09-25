#ifndef MAINMENU_H
#define MAINMENU_H
#include "Header.h"
#include "Game.h"
#include "Button.h"
#include "Label.h"


class MainMenu : public Game
{
protected: 

	//Buttons needed
	Button* playButton; 
	Button* settingsButton;
	Button* creditsButton;
	Button* quitButton;

	//label test
	Label* titleLabel;

	//textures
	LPDIRECT3DTEXTURE9 titleTexture;

	//buttonSizes
	int menuButtonWidth;
	int menuButtonHeight;
	D3DXMATRIX mat; //for matrix position
	D3DXVECTOR2 titlePosition;

	//coordinates of line 1----
	D3DXVECTOR2 l1StartPoint;
	D3DXVECTOR2 l1EndPoint;
	D3DXVECTOR2 l1LineVertices[2];

	//coordinates of line 2----
	D3DXVECTOR2 l2StartPoint;
	D3DXVECTOR2 l2EndPoint;
	D3DXVECTOR2 l2LineVertices[2];

private:
	RECT mouse; // mouse position for collision detection

public:
	MainMenu() : Game() { //constructor
		this->Initialize();
	}
	~MainMenu();

	void Initialize();
	void Update();
	void Render();
};

#endif