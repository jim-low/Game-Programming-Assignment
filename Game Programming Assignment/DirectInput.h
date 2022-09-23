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
};


#endif