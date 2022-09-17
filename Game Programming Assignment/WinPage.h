#ifndef WINPAGE_H
#define WINPAGE_H
#include "Header.h"
#include "Game.h"

class WinPage : public Game
{
protected:
	RECT winRect;
	LPDIRECT3DTEXTURE9 winTexture;
	D3DXVECTOR2 winPos;
	int winWidth;
	int winHeight;
	D3DXMATRIX winMat; //for matrix position

public:
	WinPage() : Game() { //constructor
		this->Initialize();
	}
	~WinPage();

	void Initialize();
	void Update();
	void Render();
	void Input();
};

#endif