#ifndef GAMEOVERPAGE_H
#define GAMEOVERPAGE_H
#include "Header.h"
#include "Game.h"
#include "RickRoll.h"

class GameOverPage : public Game
{
protected:
	int score; // final score of player

	// render score text variables
	RECT scoreRect;
	D3DXVECTOR2 scorePos;
	string tempStr;
	LPCSTR scoreStr;

	// render escape label variables
	RECT escLabelRect;
	D3DXVECTOR2 escLabelPos;
	LPD3DXFONT escFont;

private:
	RickRoll* neverGonnaGiveYouUp; // unique animation sprite variables

public:
	GameOverPage(int score) : Game() { //constructor
		this->Initialize(score);
	}
	~GameOverPage();

	void Initialize(int score);
	void Update();
	void Render();
};

#endif