#ifndef GAMEOVERPAGE_H
#define GAMEOVERPAGE_H
#include "Header.h"
#include "Game.h"
#include "RickRoll.h"
#include "Label.h"

class GameOverPage : public Game
{
protected:
	int score; // final score of player

	//labels needed
	Label* loseLabel;
	Label* escLabel;
	Label* scoreLabel;

	//for score Label
	string tempStr;
	LPCSTR scoreStr;

	boolean escKeyPressed;

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
	void Input();
};

#endif