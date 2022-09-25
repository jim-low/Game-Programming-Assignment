#pragma once
#ifndef LABEL_H
#define LABEL_H

#include "Header.h"

class Label : public Game
{
protected:

	// All Labels
	// RECT animRect; (from Game Class)
	// LPD3DXFONT fontBrush; (from Game Class)
	// D3DXVECTOR2 position; (from Game Class)
	enum type{TEXT,IMAGE};
	int labelType; //to chack what label it is
	D3DXMATRIX labelMat;
	int width; //either font width, or image width
	int height; //either font height, or image height

	//Font Label
	string labelString;
	LPD3DXFONT font;

	//image Label
	//LPDIRECT3DTEXTURE9 texture; //to initialize what texture to be used for the label (From Game Class)



public:
	//constructor

	//image label 
	Label(D3DXVECTOR2 labelPosition, string fileName, int imageWidth, int imageHeight) {

		labelType = IMAGE;
		this->width = imageWidth;
		this->height = imageHeight;
		this->font = font;

		//initialize texture from the spriteSheet file. 
		HRESULT hr = D3DXCreateTextureFromFile(d3dDevice, fileName.c_str(), &texture);
		if (FAILED(hr)) {
			std::cout << "Could not find label " + fileName;
			MessageBox(NULL, TEXT(("Could not find label " + fileName).c_str()), TEXT("ERROR!"), MB_YESNOCANCEL | MB_ICONQUESTION);
		}

		//define the label image's position and rectangle.
		position = labelPosition; //location
		animRect.top = 0;
		animRect.bottom = animRect.top + height;
		animRect.left = 0;
		animRect.right = animRect.left + width;

		scaling = D3DXVECTOR2(1, 1);
		centre = D3DXVECTOR2(width / 2, height / 2);
	}

	//font label
	Label(D3DXVECTOR2 labelPosition, string fontName, string labelString, int fontWidth, int fontHeight) {

		labelType = TEXT;
		this->width = fontWidth;
		this->height = fontHeight;

		HRESULT hr = D3DXCreateFont(d3dDevice, height, width, 0, 1, false, DEFAULT_CHARSET, OUT_TT_ONLY_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, fontName.c_str(), &font);
		if (FAILED(hr)) {
			cout << "Failed to create font." << endl;
			MessageBox(NULL, TEXT("Failed to create font."), TEXT("ERROR!"), MB_YESNOCANCEL | MB_ICONQUESTION);
		}

		//define the label image's position and rectangle. 
		position = labelPosition; //location
		animRect.top = 0;
		animRect.bottom = animRect.top + fontHeight;
		animRect.left = 0;
		animRect.right = animRect.left + ((fontWidth * labelString.length()) + 30);
		std::cout << animRect.right << std::endl;
		std::cout << animRect.bottom << std::endl;
		scaling = D3DXVECTOR2(1, 1);
		centre = D3DXVECTOR2(width / 2, height / 2);

		this->labelString = labelString;
	}

	Label();
	~Label();

	void Render(); //only render labels. No hover feature
	void RenderWithUpdatingValue(int a);

	void setScaling(float x, float y) {
		scaling = (D3DXVECTOR2(x, y));
	}
};

#endif

