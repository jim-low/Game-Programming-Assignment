#ifndef GAMEOVERPAGE_H
#define GAMEOVERPAGE_H
#include "Header.h"
#include "Game.h"
#include "RickRoll.h"

class GameOverPage : public Game
{
protected:
	//for score
	int score;
	RECT scoreRect;
	D3DXVECTOR2 scorePos;
	string tempStr;
	LPCSTR scoreStr;
	boolean escKeyPressed;

	//for "Press ESC to go back"
	RECT escLabelRect;
	D3DXVECTOR2 escLabelPos;
	LPD3DXFONT escFont;

private:
	RickRoll* neverGonnaGiveYouUp;

public:
	GameOverPage(int score) : Game() { //constructor
		this->Initialize(score);
	}
	~GameOverPage();

	void Initialize(int score);
	void Update();
	void Render();
	void Input();
};

#endif