#ifndef GAMEOVERPAGE_H
#define GAMEOVERPAGE_H
#include "Header.h"
#include "Game.h"
#include "RickRoll.h"

class GameOverPage : public Game
{
private:
	RickRoll* neverGonnaGiveYouUp;

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