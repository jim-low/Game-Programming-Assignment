#pragma once
#ifndef DIRECTINPUT_H
#define DIRECTINPUT_H
#include "Header.h"

class DirectInput
{

public:
	DirectInput() {
		this->Initialize();
	}
	~DirectInput();

	void Initialize();
	void GetInput();

	static boolean IsKeyDown(int key);
	static boolean isMouseDown(int button);
};


#endif