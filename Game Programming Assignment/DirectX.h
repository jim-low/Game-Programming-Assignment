#pragma once
#ifndef DIRECTX_H
#define DIRECTX_H
#include "Header.h"

class DirectX
{

public:
	DirectX(){
		this->Initialize();
	}
	~DirectX();

	int Initialize();
};


#endif // DIRECTX_H