#ifndef WINPAGE_H
#define WINPAGE_H
#include "Header.h"
#include "Game.h"
#include "Label.h"

class WinPage : public Game
{
protected:
	int score;

	//labels needed
	Label* winLabel;
	Label* escLabel;
	Label* scoreLabel;

	// score text variables
	string tempStr;
	LPCSTR scoreStr;

	// input
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