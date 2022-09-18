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

	string tempStr;
	LPCSTR scoreStr;
	RECT scoreRect;
	D3DXVECTOR2 scorePos;
	int score;

	boolean escKeyPressed;

public:
	WinPage(int score) : Game() { //constructor
		this->Initialize(score);
	}
	~WinPage();

	void Initialize(int score);
	void Update();
	void Render();
	void Input();
};

#endif