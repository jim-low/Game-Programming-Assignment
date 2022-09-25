#ifndef SETTINGSPAGE_H
#define SETTINGSPAGE_H
#include "Header.h"
#include "Game.h"
#include "Button.h"
#include "Label.h"

class SettingsPage : public Game
{
protected:
	//test
	LPCSTR tempBGCounter;

	//Buttons needed 
	Button* incBGVol;
	Button* decBGVol;
	Button* incEffVol;
	Button* decEffVol;

	//for labels
	//RECT bGLabelRect;
	//RECT effLabelRect;
	//D3DXVECTOR2 bGLabelPos;
	//D3DXVECTOR2 effLabelPos;

	//D3DXVECTOR2 bGCountPos;
	//D3DXVECTOR2 effCountPos;
	//RECT bGSoundCountRect;
	//RECT effSoundCountRect;

	//labels
	Label* escLabel;

	Label* bgLabel;
	Label* effLabel;
	Label* bgCount;
	Label* effCount;

	//for "Press ESC to go back"
	//RECT escLabelRect;
	//D3DXVECTOR2 escLabelPos;
	//LPD3DXFONT escFont;


	//for buttons
	//RECT buttonRightBGRect;
	//RECT buttonLeftBGRect;
	//RECT buttonRightEffRect;
	//RECT buttonLeftEffRect;

	//collision Rectangles
	//RECT leftBGButtonCol;
	//RECT rightBGButtonCol;
	//RECT leftEffButtonCol;
	//RECT rightEffButtonCol;

	////textures
	//LPDIRECT3DTEXTURE9 butRightTexture;
	//LPDIRECT3DTEXTURE9 butLeftTexture;

	//D3DXVECTOR2 rightBGPos;
	//D3DXVECTOR2 leftBGPos;
	//D3DXVECTOR2 rightEffPos;
	//D3DXVECTOR2 leftEffPos;

	//buttonSizes
	int arrButtonWidth;
	int arrButtonHeight;
	D3DXMATRIX buttonMat; //for matrix position

	//currentSelectedButton
	//int currentSelection;
	//enum buttonFocus { UNFOCUS, ADDBG, MINUSBG, ADDEFF, MINUSEFF };

	//input stuff
	boolean escKeyPressed;
	//boolean leftKeyPressed;
	//float bufferTimer;

	//inputdelay
	boolean clickDelay;

//private:
//	RECT mouse;

public:


	SettingsPage() : Game() { //constructor
		this->Initialize();
	}
	~SettingsPage();

	void Initialize();
	void Update();
	void Render();
	void Input();
};

#endif

