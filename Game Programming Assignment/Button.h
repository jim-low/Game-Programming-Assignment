#pragma once
#ifndef BUTTON_H
#define BUTTON_H

#include "Header.h"

class Button : public Game{

private:
	void (*clickResponse)(void); //function pointer

protected:

	//contain components of a button (Buttons used are as png files, when hovered, the texture alters from the sprite sheet.)
	//RECT animRect; //defines the rectangle in the spriteSheet (From Game Class)
	//RECT colRect; //defines the rectangle in the spriteSheet (From Game Class)
	//LPDIRECT3DTEXTURE9 buttonTexture; //to initialize what texture to be used for the button (From Game Class)

	//define how big the button is in the spritesheet
	int buttonWidth; 
	int buttonHeight;

	//to resize buttons within the game, use matrixes
	D3DXMATRIX buttonMat;

	//D3DXVECTOR2 buttonPosition; (From Game Class)
	//D3DXVECTOR2 scaling (From Game Class)
	//D3DXVECTOR2 centre (From Game Class)

public:
	//constructor

	Button(int buttonWidth, int buttonHeight, D3DXVECTOR2 buttonPos, string fileName, void (*clickResponse)(void)) {
		
		//initialize texture from the spriteSheet file. 
		HRESULT hr = D3DXCreateTextureFromFile(d3dDevice, fileName.c_str(), &texture);
		if (FAILED(hr)) {
			std::cout << "Could not find button" + fileName;
			MessageBox(NULL, TEXT(("Could not find button" + fileName).c_str()), TEXT("ERROR!"), MB_YESNOCANCEL | MB_ICONQUESTION);
		}
		
		this->clickResponse = clickResponse;
		this->buttonWidth = buttonWidth;
		this->buttonHeight = buttonHeight;

		//define the first frame of the spriteSheet as the initial button
		animRect.top = 0;
		animRect.bottom = animRect.top + buttonHeight;
		animRect.left = 0;
		animRect.right = animRect.left + buttonWidth;

		//define the collision rectangle and it's location
		position = buttonPos; //location
		colRect.top = buttonPos.y; //(Due to issues with the spritesheets, collision rectangles may need to be hard coded additionally)
		colRect.bottom = buttonPos.y + buttonHeight;
		colRect.left = buttonPos.x;
		colRect.right = buttonPos.x + buttonWidth;

		scaling = D3DXVECTOR2(0.9, 0.9);
		centre = D3DXVECTOR2(buttonWidth / 2, buttonHeight / 2);
	}


	~Button();

	void Update();
	void Render();

	//getters

	RECT getColRect() {
		return colRect;
	}

	void presetColRect(int addTop, int addBottom, int addLeft, int addRight) {
		colRect.top += addTop;
		colRect.bottom += addBottom;
		colRect.left += addLeft;
		colRect.right += addRight;
	}

};

#endif


