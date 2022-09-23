#pragma once
#ifndef DIRECTX_H
#define DIRECTX_H
#include "header.h"

class DirectX
{

public:
	DirectX(){
		this->Initialize();
	}
	~DirectX();

	void Initialize();
	int CreateMy3D();
};


#endif // DIRECTX_H