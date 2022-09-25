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

	//labels
	Label* escLabel;

	Label* bgLabel;
	Label* effLabel;
	Label* bgCount;
	Label* effCount;

	//buttonSizes
	int arrButtonWidth;
	int arrButtonHeight;

	//inputdelay
	boolean clickDelay;

public:


	SettingsPage() : Game() { //constructor
		this->Initialize();
	}
	~SettingsPage();

	void Initialize();
	void Update();
	void Render();
};

#endif

